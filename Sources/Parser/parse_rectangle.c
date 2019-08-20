/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rectangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorobin <jorobin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 17:47:26 by jorobin           #+#    #+#             */
/*   Updated: 2018/04/23 15:37:36 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_rectangle_error(void)
{
	ft_putstr("XML ERROR : RECTANGLE NODE\n--------------------------\n<vecto");
	ft_putstr("r_a> { X, Y, Z } </vector_a>\n<vector_b> { X, Y, ");
	ft_putstr("Z } </vector_b>\n<normal> { X, Y, Z } </normal>\n");
	ft_putstr("--------------------------\n");
	ft_error("rectangle point at { 0, 0, 0 } if none\n");
}

void	verif_value(t_object *object)
{
	if (!object->rectangle.normal.x && !object->rectangle.normal.y\
		&& !object->rectangle.normal.z)
		ft_rectangle_error();
	object->rectangle.kepsilon = 0.00001;
	object->rectangle.len_squared_a = len_square(&object->rectangle.a);
	object->rectangle.len_squared_b = len_square(&object->rectangle.b);
	object->rectangle.len_a = length(&object->rectangle.a);
	object->rectangle.len_b = length(&object->rectangle.b);
}

void	set_rectangle3(t_object *object, xmlNodePtr child, xmlChar *xmldata)
{
	if (xmlStrcmp(child->name, (const xmlChar *)"vector_b") == 0)
	{
		if (!set_vector(xmldata, &object->rectangle.b))
		{
			xmlFree(xmldata);
			ft_rectangle_error();
		}
	}
	else if (xmlStrcmp(child->name, (const xmlChar *)"normal") == 0)
	{
		if (!set_normal(xmldata, &object->rectangle.normal))
		{
			xmlFree(xmldata);
			ft_rectangle_error();
		}
		normalizen(&object->rectangle.normal);
	}
}

void	set_rectangle2(t_object *object, xmlNodePtr child, xmlChar *xmldata)
{
	if (xmlStrcmp(child->name, (const xmlChar *)"point") == 0)
	{
		if (!set_point(xmldata, &object->rectangle.p0))
		{
			xmlFree(xmldata);
			ft_rectangle_error();
		}
	}
	if (xmlStrcmp(child->name, (const xmlChar *)"vector_a") == 0)
	{
		if (!set_vector(xmldata, &object->rectangle.a))
		{
			xmlFree(xmldata);
			ft_rectangle_error();
		}
	}
	set_rectangle3(object, child, xmldata);
}

void	set_rectangle(xmlDocPtr doc, t_object *object, xmlNodePtr cur)
{
	xmlChar		*xmldata;
	xmlNodePtr	child;

	object->type = 6;
	child = cur;
	if (!(cur))
		ft_rectangle_error();
	while (child != NULL)
	{
		xmldata = xmlNodeListGetString(doc, child->xmlChildrenNode, 0);
		if (xmldata)
		{
			set_rectangle2(object, child, xmldata);
			xmlFree(xmldata);
		}
		child = child->next;
	}
	verif_value(object);
	if (no_vector(&object->rectangle.a) || no_vector(&object->rectangle.b))
		ft_rectangle_error();
	object->d = object->rectangle.p0;
	set_object_generic(doc, object, cur);
}
