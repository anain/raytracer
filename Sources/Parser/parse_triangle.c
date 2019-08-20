/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_triangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorobin <jorobin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 17:46:56 by jorobin           #+#    #+#             */
/*   Updated: 2018/04/24 22:47:47 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	verif_normal(t_object *object)
{
	if (!object->triangle.normal.x && !object->triangle.normal.y \
		&& !object->triangle.normal.z)
	{
		ft_putstr("hint : NORMAL CAN'T BE { 0, 0, 0 } ! \n\n");
		ft_triangle_error();
	}
}

void	set_triangle3(t_object *object, xmlNodePtr child, xmlChar *xmldata)
{
	if (xmlStrcmp(child->name, (const xmlChar *)"vertice_3") == 0)
	{
		if (!set_point(xmldata, &object->triangle.v2))
		{
			xmlFree(xmldata);
			ft_triangle_error();
		}
	}
}

void	set_triangle2(t_object *object, xmlNodePtr child, xmlChar *xmldata)
{
	if (xmlStrcmp(child->name, (const xmlChar *)"vertice_1") == 0)
	{
		if (!set_point(xmldata, &object->triangle.v0))
		{
			xmlFree(xmldata);
			ft_triangle_error();
		}
	}
	if (xmlStrcmp(child->name, (const xmlChar *)"vertice_2") == 0)
	{
		if (!set_point(xmldata, &object->triangle.v1))
		{
			xmlFree(xmldata);
			ft_triangle_error();
		}
	}
	set_triangle3(object, child, xmldata);
}

void	set_triangle_init(t_object *object)
{
	object->triangle.normal = (t_normal) {0, 0, 0};
	object->triangle.v0 = (t_point3d) {0, 0, 0};
	object->triangle.v1 = (t_point3d) {0, 0, 0};
	object->triangle.v2 = (t_point3d) {0, 0, 0};
}

void	set_triangle(xmlDocPtr doc, t_object *object, xmlNodePtr cur)
{
	xmlChar		*xmldata;
	xmlNodePtr	child;

	object->type = 5;
	if (!(cur))
		ft_triangle_error();
	child = cur;
	set_triangle_init(object);
	while (child != NULL)
	{
		xmldata = xmlNodeListGetString(doc, child->xmlChildrenNode, 0);
		if (xmldata)
		{
			set_triangle2(object, child, xmldata);
			xmlFree(xmldata);
		}
		child = child->next;
	}
	set_triangle_normal(&object->triangle);
	verif_normal(object);
	if ((no_point(&object->triangle.v0) && no_point(&object->triangle.v1) \
	&& no_point(&object->triangle.v2)) || no_normal(&object->triangle.normal))
		ft_triangle_error();
	object->d = object->triangle.v0;
	set_object_generic(doc, object, cur);
}
