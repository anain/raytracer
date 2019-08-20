/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorobin <jorobin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 12:36:39 by jorobin           #+#    #+#             */
/*   Updated: 2018/04/23 14:43:50 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_sphere_error(void)
{
	ft_putstr("XML ERROR : SPHERE NODE\n--------------------------\n<cen");
	ft_putstr("ter> { X, Y, Z } </center>\n<radius> RADIUS");
	ft_putstr(" </radius>\n");
	ft_putstr("--------------------------\n");
	ft_putstr("Radius must be > 0 && < int max\n");
	ft_error("Sphere center at { 0, 0, 0 } if none\n");
}

void	set_sphere2(t_object *object, xmlNodePtr child, xmlChar *xmldata)
{
	double *a;

	a = NULL;
	if (xmlStrcmp(child->name, (const xmlChar *)"center") == 0)
	{
		if (!set_point(xmldata, &object->sphere.center))
		{
			xmlFree(xmldata);
			ft_sphere_error();
		}
	}
	else if (xmlStrcmp(child->name, (const xmlChar *)"radius") == 0)
	{
		if ((a = ft_atod_safe((char*)xmldata)) == NULL)
		{
			xmlFree(xmldata);
			ft_sphere_error();
		}
		free(a);
		a = ft_atod_safe((char*)xmldata);
		object->sphere.radius = *a;
		free(a);
	}
}

void	set_sphere_generic(xmlDocPtr doc, t_object *object, xmlNodePtr cur)
{
	t_point3d	savcenter;
	float		savradius;

	savcenter = object->sphere.center;
	savradius = object->sphere.radius;
	object->sphere.center = (t_point3d) {0, 0, 0};
	object->sphere.radius = 1;
	set_object_generic(doc, object, cur);
	scaling_generic(&object->inv_mat, \
		(t_point3d) {savradius, savradius, savradius});
	scaling_generic(&object->mat.inv_mat,
		(t_point3d) {savradius, savradius, savradius});
	translate(object, savcenter.x, savcenter.y, savcenter.z);
	translate_tex(object, savcenter.x, savcenter.y, savcenter.z);
}

void	set_sphere(xmlDocPtr doc, t_object *object, xmlNodePtr cur)
{
	xmlChar		*xmldata;
	xmlNodePtr	child;

	object->type = 1;
	child = cur;
	if (!(cur))
		ft_sphere_error();
	while (child != NULL)
	{
		xmldata = xmlNodeListGetString(doc, child->xmlChildrenNode, 0);
		if (xmldata)
			set_sphere2(object, child, xmldata);
		xmlFree(xmldata);
		child = child->next;
	}
	if (object->sphere.radius <= 0 || !(object->sphere.radius < INT_MAX))
		ft_sphere_error();
	object->sphere.kepsilon = 0.00001;
	set_sphere_generic(doc, object, cur);
}
