/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_partsphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 17:47:36 by jorobin           #+#    #+#             */
/*   Updated: 2018/04/22 23:37:42 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_partsphere_error(void)
{
	ft_putstr("XML ERROR : PART SPHERE NODE\n--------------------------\n<cen");
	ft_putstr("ter> { X, Y, Z } </center>\n<radius> RADIUS");
	ft_putstr(" </radius>\n<phimin> PHI MIN </phimin>");
	ft_putstr("\n<phimax> PHI MIN </phimax>\n");
	ft_putstr("Radius must be > 0 && < int max\n");
	ft_putstr("--------------------------\n");
	ft_error("Sphere center at { 0, 0, 0 } if none\n");
}

void	set_partsphere3(t_object *object, xmlNodePtr child, xmlChar *xmldata)
{
	set_phi(object, child, xmldata);
	set_theta(object, child, xmldata);
}

void	set_partsphere2(t_object *object, xmlNodePtr child, xmlChar *xmldata)
{
	double *a;

	a = NULL;
	if (xmlStrcmp(child->name, (const xmlChar *)"center") == 0)
	{
		if (!set_point(xmldata, &object->partsphere.center))
		{
			xmlFree(xmldata);
			ft_partsphere_error();
		}
	}
	else if (xmlStrcmp(child->name, (const xmlChar *)"radius") == 0)
	{
		if ((a = ft_atod_safe((char*)xmldata)) == NULL)
		{
			xmlFree(xmldata);
			ft_partsphere_error();
		}
		free(a);
		a = ft_atod_safe((char*)xmldata);
		object->partsphere.radius = *a;
		free(a);
	}
	set_partsphere3(object, child, xmldata);
}

void	verif_val(t_object *object)
{
	if (object->partsphere.radius <= 0 || \
		!(object->partsphere.radius < INT_MAX) || \
		object->partsphere.phi_min < 0 || object->partsphere.phi_min > 360 || \
		object->partsphere.phi_max < 0 || object->partsphere.phi_max > 360 || \
		object->partsphere.theta_min < 0 ||\
		object->partsphere.theta_min > 360 || \
		object->partsphere.theta_max < 0 || object->partsphere.theta_max > 360)
		ft_partsphere_error();
}

void	set_partsphere(xmlDocPtr doc, t_object *object, xmlNodePtr cur)
{
	xmlChar		*xmldata;
	xmlNodePtr	child;

	object->type = 9;
	child = cur;
	if (!(cur))
		ft_partsphere_error();
	while (child != NULL)
	{
		xmldata = xmlNodeListGetString(doc, child->xmlChildrenNode, 0);
		if (xmldata)
		{
			set_partsphere2(object, child, xmldata);
			xmlFree(xmldata);
		}
		child = child->next;
	}
	verif_val(object);
	object->partsphere.kepsilon = 0.00001;
	object->partsphere.cos_theta_min = cos(object->partsphere.theta_min);
	object->partsphere.cos_theta_max = cos(object->partsphere.theta_max);
	object->d = object->partsphere.center;
	set_object_generic(doc, object, cur);
}
