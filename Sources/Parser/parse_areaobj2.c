/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_areaobj2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 15:03:02 by asavann           #+#    #+#             */
/*   Updated: 2018/04/24 23:56:59 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "sphere.h"
#include "emissive.h"
#include "constants.h"

xmlXPathObjectPtr	checkobject(xmlDocPtr doc, xmlNodePtr cur, t_world *world)
{
	xmlXPathObjectPtr	xpathobj;

	if (world)
		;
	if (!(cur))
		ft_error("Error in the definition of areaobj.\n");
	xpathobj = findnodesbyname(doc, cur, (xmlChar *)"../object");
	if (xpathobj->nodesetval->nodeNr == 0)
	{
		xmlXPathFreeObject(xpathobj);
		ft_error("Missing object in area light\n");
	}
	xmlXPathFreeObject(xpathobj);
	xpathobj = findnodesbyname(doc, cur, (xmlChar *)"../object/disk");
	return (xpathobj);
}

static void			set_lsphere(t_object **obj, int ns)
{
	(*obj)->sphere.kepsilon = 0.00001;
	(*obj)->sphere.area = 4.0 * PI *\
	(*obj)->sphere.radius * (*obj)->sphere.radius;
	(*obj)->sphere.inv_area = 1.0 / (*obj)->sphere.area;
	(*obj)->hit = spherehit;
	(*obj)->shadow_hit = spherehitshadow;
	(*obj)->sample = sphere_sample;
	(*obj)->get_normal = sphere_get_normal;
	(*obj)->pdfo = sphere_pdf;
	(*obj)->mat.get_le = get_le;
	(*obj)->mat.shade = area_light_shade;
	(*obj)->mat.path_shade = area_light_shade;
	(*obj)->mat.tex.path = NULL;
	(*obj)->shadow = 0;
	(*obj)->type = 0;
	if (!is_perfectsquare(ns) || ns == 0 || (*obj)->sphere.radius <= 0)
		ft_error("Error in the definition of a rectangle light.\n");
	sphere_set_sampler(&(*obj)->sphere, ns);
}

void				parse_lsphere(xmlDocPtr doc,\
			xmlNodePtr cur, t_world *world, int ns)
{
	xmlChar				*xmldata;
	t_object			*obj;

	if (!cur)
		ft_error("Error in the definition of a sphere light.\n");
	obj = world->object;
	while (obj->next != NULL)
		obj = obj->next;
	xmldata = find_data(doc, cur, "../center");
	set_point(xmldata, &obj->sphere.center);
	xmlFree(xmldata);
	xmldata = find_data(doc, cur, "../radius");
	obj->sphere.radius = ft_atod((char *)xmldata);
	xmlFree(xmldata);
	set_lsphere(&obj, ns);
}
