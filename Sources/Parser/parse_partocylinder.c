/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_partocylinder.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 17:47:42 by jorobin           #+#    #+#             */
/*   Updated: 2018/04/22 22:12:18 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_partocylinder_error(void)
{
	ft_putstr("XML ERROR : PART OPEN CYLINDER NODE\n-----------------");
	ft_putstr("---------\n<bottom> START </bottom>\n<top> ");
	ft_putstr("END </top>\n<radius> RADIUS </radius>\n");
	ft_putstr("<phimin> PHI MIN </phimin>\n<phimax> PHI M");
	ft_error("AX </phimax>\n--------------------------\n");
}

void	set_partocylinder6(t_object *object)
{
	if (object->pocylinder.radius <= 0 || \
		!(object->pocylinder.radius < INT_MAX)\
		|| !(object->pocylinder.y0 < INT_MAX) || object->pocylinder.y1\
		== object->pocylinder.y0 || !(object->pocylinder.y1 < INT_MAX) ||\
		object->pocylinder.phi_min < 0 || object->pocylinder.phi_min > 360 || \
		object->pocylinder.phi_max < 0 || object->pocylinder.phi_max > 360)
		ft_partocylinder_error();
	object->pocylinder.kepsilon = 0.00001;
	object->pocylinder.invradius = 1.0 / object->pocylinder.radius;
}

void	set_partocylinder3(t_object *object, xmlNodePtr child, xmlChar *xmldata)
{
	double *a;

	a = NULL;
	if (xmlStrcmp(child->name, (const xmlChar *)"top") == 0)
	{
		if ((a = ft_atod_safe((char*)xmldata)) == NULL)
		{
			xmlFree(xmldata);
			ft_partocylinder_error();
		}
		free(a);
		a = ft_atod_safe((char*)xmldata);
		object->pocylinder.y1 = *a;
		free(a);
	}
	set_partocylinder4(object, child, xmldata);
}

void	set_partocylinder2(t_object *object, xmlNodePtr child, xmlChar *xmldata)
{
	double *a;

	a = NULL;
	if (xmlStrcmp(child->name, (const xmlChar *)"bottom") == 0)
	{
		if ((a = ft_atod_safe((char*)xmldata)) == NULL)
		{
			xmlFree(xmldata);
			ft_partocylinder_error();
		}
		free(a);
		a = ft_atod_safe((char*)xmldata);
		object->pocylinder.y0 = *a;
		free(a);
	}
	set_partocylinder3(object, child, xmldata);
}

void	set_partocylinder(xmlDocPtr doc, t_object *object, xmlNodePtr cur)
{
	xmlChar		*xmldata;
	xmlNodePtr	child;

	object->type = 8;
	child = cur;
	if (!(cur))
		ft_partocylinder_error();
	while (child != NULL)
	{
		xmldata = xmlNodeListGetString(doc, child->xmlChildrenNode, 0);
		if (xmldata)
		{
			set_partocylinder2(object, child, xmldata);
			xmlFree(xmldata);
		}
		child = child->next;
	}
	set_partocylinder6(object);
	object->d = (t_point3d) {0, 0, 0};
	set_object_generic(doc, object, cur);
}
