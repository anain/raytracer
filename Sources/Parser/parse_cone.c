/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 12:36:16 by jorobin           #+#    #+#             */
/*   Updated: 2018/04/22 23:46:44 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_cone_error(void)
{
	ft_putstr("XML ERROR : CONE NODE\n--------------------------\n<hei");
	ft_putstr("ght> HEIGHT </height>\n<radius> RADIUS");
	ft_putstr(" </radius>\n");
	ft_error("--------------------------\n");
}

void	set_cone3(t_object *object, xmlNodePtr child, xmlChar *xmldata)
{
	double *a;

	a = NULL;
	if (xmlStrcmp(child->name, (const xmlChar *)"height") == 0)
	{
		if ((a = ft_atod_safe((char*)xmldata)) == NULL)
		{
			xmlFree(xmldata);
			ft_cone_error();
		}
		free(a);
		a = ft_atod_safe((char*)xmldata);
		object->icone.h = *a;
		free(a);
	}
}

void	set_cone2(t_object *object, xmlNodePtr child, xmlChar *xmldata)
{
	double *a;

	a = NULL;
	if (xmlStrcmp(child->name, (const xmlChar *)"radius") == 0)
	{
		if ((a = ft_atod_safe((char*)xmldata)) == NULL)
		{
			xmlFree(xmldata);
			ft_cone_error();
		}
		free(a);
		a = ft_atod_safe((char*)xmldata);
		object->icone.radius = *a;
		free(a);
	}
	set_cone3(object, child, xmldata);
}

void	set_cone(xmlDocPtr doc, t_object *object, xmlNodePtr cur)
{
	xmlChar		*xmldata;
	xmlNodePtr	child;

	object->type = 3;
	child = cur;
	object->icone.radius = 0;
	object->icone.h = 0;
	if (!(cur))
		ft_error("Error in the definition of cone.\n");
	while (child != NULL)
	{
		xmldata = xmlNodeListGetString(doc, child->xmlChildrenNode, 0);
		if (xmldata)
		{
			set_cone2(object, child, xmldata);
			xmlFree(xmldata);
		}
		child = child->next;
	}
	if (!object->icone.h || !object->icone.radius)
		ft_cone_error();
	object->icone.kepsilon = 0.00001;
	object->icone.invradius = 1 / object->icone.radius;
	object->d = (t_point3d) {0, 0, 0};
	set_object_generic(doc, object, cur);
}
