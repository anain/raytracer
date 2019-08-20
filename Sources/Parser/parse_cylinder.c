/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 12:35:56 by jorobin           #+#    #+#             */
/*   Updated: 2018/04/22 23:47:36 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_cylinder_error(void)
{
	ft_putstr("XML ERROR : CYLINDER NODE\n--------------------------\n<bot");
	ft_putstr("top> BOTTOM POINT </bottom>\n<top> TOP POINT");
	ft_putstr(" </top>\n<radius> RADIUS </radius>\n");
	ft_error("--------------------------\n");
}

void	set_cylinder5(t_object *object)
{
	if (object->ocylinder.radius <= 0 || !(object->ocylinder.radius < INT_MAX)\
		|| !(object->ocylinder.y0 < INT_MAX) || object->ocylinder.y1\
		== object->ocylinder.y0 || !(object->ocylinder.y1 < INT_MAX))
		ft_cylinder_error();
	object->ocylinder.kepsilon = 0.00001;
	object->ocylinder.invradius = 1 / object->ocylinder.radius;
}

void	set_cylinder3(t_object *object, xmlNodePtr child, xmlChar *xmldata)
{
	double *a;

	a = NULL;
	if (xmlStrcmp(child->name, (const xmlChar *)"top") == 0)
	{
		if ((a = ft_atod_safe((char*)xmldata)) == NULL)
		{
			xmlFree(xmldata);
			ft_cylinder_error();
		}
		free(a);
		a = ft_atod_safe((char*)xmldata);
		object->ocylinder.y1 = *a;
		free(a);
	}
	set_cylinder4(object, child, xmldata);
}

void	set_cylinder2(t_object *object, xmlNodePtr child, xmlChar *xmldata)
{
	double *a;

	a = NULL;
	if (xmlStrcmp(child->name, (const xmlChar *)"bottom") == 0)
	{
		if ((a = ft_atod_safe((char*)xmldata)) == NULL)
		{
			xmlFree(xmldata);
			ft_cylinder_error();
		}
		free(a);
		a = ft_atod_safe((char*)xmldata);
		object->ocylinder.y0 = *a;
		free(a);
	}
	set_cylinder3(object, child, xmldata);
}

void	set_cylinder(xmlDocPtr doc, t_object *object, xmlNodePtr cur)
{
	xmlChar		*xmldata;
	xmlNodePtr	child;

	object->type = CYLINDER;
	child = cur;
	object->ocylinder.radius = -1;
	if (!(cur))
		ft_error("Error in the definition of cylinder.\n");
	while (child != NULL)
	{
		xmldata = xmlNodeListGetString(doc, child->xmlChildrenNode, 0);
		if (xmldata)
		{
			set_cylinder2(object, child, xmldata);
			xmlFree(xmldata);
		}
		child = child->next;
	}
	set_cylinder5(object);
	object->d = (t_point3d) {0, 0, 0};
	set_object_generic(doc, object, cur);
}
