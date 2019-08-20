/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorobin <jorobin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 12:36:30 by jorobin           #+#    #+#             */
/*   Updated: 2018/04/20 19:56:24 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_plane_error(void)
{
	ft_putstr("XML ERROR : PLANE NODE\n--------------------------\n<poi");
	ft_putstr("nt> { X, Y, Z } </point>\n<normal> { X, Y, Z }");
	ft_putstr(" </normal>\n");
	ft_putstr("--------------------------\n");
	ft_error("Plane point at { 0, 0, 0 } if none\n");
}

void	set_plane2(t_object *object, xmlNodePtr child, xmlChar *xmldata)
{
	if (xmlStrcmp(child->name, (const xmlChar *)"point") == 0)
	{
		if (!set_point(xmldata, &object->plane.point))
		{
			xmlFree(xmldata);
			ft_plane_error();
		}
	}
	else if (xmlStrcmp(child->name, (const xmlChar *)"normal") == 0)
	{
		if (!set_normal(xmldata, &object->plane.normal))
		{
			xmlFree(xmldata);
			ft_plane_error();
		}
	}
}

void	set_plane(xmlDocPtr doc, t_object *object, xmlNodePtr cur)
{
	xmlChar		*xmldata;
	xmlNodePtr	child;

	object->type = 2;
	child = cur;
	if (!(cur))
		ft_plane_error();
	while (child != NULL)
	{
		xmldata = xmlNodeListGetString(doc, child->xmlChildrenNode, 0);
		if (xmldata)
			set_plane2(object, child, xmldata);
		xmlFree(xmldata);
		child = child->next;
	}
	if (!object->plane.normal.x && !object->plane.normal.y &&\
		!object->plane.normal.z)
	{
		ft_putstr("hint : NORMAL CAN'T BE { 0, 0, 0 } ! \n\n");
		ft_plane_error();
	}
	object->plane.kepsilon = 0.00001;
	object->d = object->plane.point;
	set_object_generic(doc, object, cur);
}
