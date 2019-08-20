/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_torus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 17:47:02 by jorobin           #+#    #+#             */
/*   Updated: 2018/04/24 16:25:00 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_torus_error(void)
{
	ft_putstr("XML ERROR : TORUS NODE\n--------------");
	ft_putstr("------------\n<diameter> DIAMETER </diam");
	ft_putstr("eter>\n<density> DENSITY </density>\n");
	ft_putstr("--------------------------\n");
	ft_error("[i] Torus position always at { 0, 0, 0 }\n");
}

void	set_torus3(t_object *object, xmlNodePtr child, xmlChar *xmldata)
{
	double *a;

	a = NULL;
	if (xmlStrcmp(child->name, (const xmlChar *)"diameter") == 0)
	{
		if ((a = ft_atod_safe((char*)xmldata)) == NULL)
		{
			xmlFree(xmldata);
			ft_torus_error();
		}
		free(a);
		a = ft_atod_safe((char*)xmldata);
		object->torus.a = *a;
		free(a);
	}
}

void	set_torus2(t_object *object, xmlNodePtr child, xmlChar *xmldata)
{
	double *a;

	a = NULL;
	if (xmlStrcmp(child->name, (const xmlChar *)"density") == 0)
	{
		if ((a = ft_atod_safe((char*)xmldata)) == NULL)
		{
			xmlFree(xmldata);
			ft_torus_error();
		}
		free(a);
		a = ft_atod_safe((char*)xmldata);
		object->torus.b = *a;
		free(a);
	}
	set_torus3(object, child, xmldata);
}

void	set_torus(xmlDocPtr doc, t_object *object, xmlNodePtr cur)
{
	xmlChar		*xmldata;
	xmlNodePtr	child;

	object->type = 12;
	child = cur;
	if (!(cur))
		ft_torus_error();
	while (child != NULL)
	{
		xmldata = xmlNodeListGetString(doc, child->xmlChildrenNode, 0);
		if (xmldata)
		{
			set_torus2(object, child, xmldata);
			xmlFree(xmldata);
		}
		child = child->next;
	}
	if (object->torus.a <= 0 || object->torus.b <= 0)
		ft_torus_error();
	object->torus.kepsilon = 0.00001;
	object->d = (t_point3d) {0, 0, 0};
	set_object_generic(doc, object, cur);
}
