/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_areaobj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 15:02:14 by asavann           #+#    #+#             */
/*   Updated: 2018/04/24 23:14:18 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "disk.h"
#include "rectangle.h"
#include "emissive.h"

static void	set_ldisk(t_object **obj, int ns)
{
	(*obj)->disk.r_squared = (*obj)->disk.r * (*obj)->disk.r;
	(*obj)->disk.kepsilon = 0.00001;
	(*obj)->disk.area = M_PI * (*obj)->disk.r_squared;
	(*obj)->disk.inv_area = 1.0 / (*obj)->disk.area;
	(*obj)->hit = diskhit;
	(*obj)->shadow_hit = diskhitshadow;
	(*obj)->sample = disk_sample;
	(*obj)->get_normal = disk_get_normal;
	(*obj)->pdfo = disk_pdf;
	(*obj)->mat.get_le = get_le;
	(*obj)->mat.shade = area_light_shade;
	(*obj)->mat.path_shade = area_light_shade;
	(*obj)->mat.tex.path = NULL;
	(*obj)->shadow = 0;
	(*obj)->disk.k = 1;
	if (!is_perfectsquare(ns) || ns == 0 || (*obj)->disk.r <= 0)
		ft_error("Error in the definition of a disk light.\n");
	disk_set_sampler(&(*obj)->disk, ns);
	compute_uvwdisk(&(*obj)->disk);
}

static void	parse_ldisk(xmlDocPtr doc, xmlNodePtr cur, t_world *world, int ns)
{
	xmlChar				*xmldata;
	t_object			*obj;

	if (!cur)
		ft_error("Error in the definition of a disk light.\n");
	obj = world->object;
	while (obj->next != NULL)
		obj = obj->next;
	xmldata = find_data(doc, cur, "../center");
	set_point(xmldata, &obj->disk.center);
	xmlFree(xmldata);
	xmldata = find_data(doc, cur, "../radius");
	obj->disk.r = ft_atod((char *)xmldata);
	xmlFree(xmldata);
	xmldata = find_data(doc, cur, "../normal");
	set_normal(xmldata, &obj->disk.normal);
	normalizen(&obj->disk.normal);
	xmlFree(xmldata);
	set_ldisk(&obj, ns);
}

static void	set_lrect(t_object **obj, int ns)
{
	(*obj)->rectangle.len_squared_a = len_square(&(*obj)->rectangle.a);
	(*obj)->rectangle.len_squared_b = len_square(&(*obj)->rectangle.b);
	(*obj)->rectangle.kepsilon = 0.00001;
	(*obj)->rectangle.area = length(&(*obj)->rectangle.a)\
	* length(&(*obj)->rectangle.b);
	(*obj)->rectangle.inv_area = 1.0 / (*obj)->rectangle.area;
	(*obj)->hit = rectanglehit;
	(*obj)->shadow_hit = rectanglehitshadow;
	(*obj)->sample = rect_sample;
	(*obj)->get_normal = rect_get_normal;
	(*obj)->pdfo = rect_pdf;
	(*obj)->mat.get_le = get_le;
	(*obj)->mat.shade = area_light_shade;
	(*obj)->mat.path_shade = area_light_shade;
	(*obj)->mat.tex.path = NULL;
	(*obj)->shadow = 0;
	if (!is_perfectsquare(ns) || ns == 0)
		ft_error("Error in the definition of a rectangle light.\n");
	rect_set_sampler(&(*obj)->rectangle, ns);
}

static void	parse_lrectangle(xmlDocPtr doc,\
			xmlNodePtr cur, t_world *world, int ns)
{
	xmlChar				*xmldata;
	t_object			*obj;

	if (!cur)
		ft_error("Error in the definition of a rectangle light.\n");
	obj = world->object;
	while (obj->next != NULL)
		obj = obj->next;
	xmldata = find_data(doc, cur, "../p0");
	set_point(xmldata, &obj->rectangle.p0);
	xmlFree(xmldata);
	xmldata = find_data(doc, cur, "../vector_a");
	set_vec(xmldata, &obj->rectangle.a);
	xmlFree(xmldata);
	xmldata = find_data(doc, cur, "../vector_b");
	set_vec(xmldata, &obj->rectangle.b);
	xmlFree(xmldata);
	xmldata = find_data(doc, cur, "../normal");
	set_normal(xmldata, &obj->rectangle.normal);
	normalizen(&obj->rectangle.normal);
	xmlFree(xmldata);
	set_lrect(&obj, ns);
}

void		parse_lobject(xmlDocPtr doc, xmlNodePtr cur, t_world *world, int ns)
{
	xmlXPathObjectPtr	xpathobj;

	xpathobj = checkobject(doc, cur, world);
	if (xpathobj->nodesetval->nodeNr)
		parse_ldisk(doc,\
		xpathobj->nodesetval->nodeTab[0]->xmlChildrenNode, world, ns);
	else
	{
		xmlXPathFreeObject(xpathobj);
		xpathobj = findnodesbyname(doc, cur, (xmlChar *)"../object/rectangle");
		if (xpathobj->nodesetval->nodeNr)
			parse_lrectangle(doc,\
			xpathobj->nodesetval->nodeTab[0]->xmlChildrenNode, world, ns);
		else
		{
			xmlXPathFreeObject(xpathobj);
			xpathobj = findnodesbyname(doc, cur, (xmlChar *)"../object/sphere");
			if (xpathobj->nodesetval->nodeNr)
				parse_lsphere(doc,\
			xpathobj->nodesetval->nodeTab[0]->xmlChildrenNode, world, ns);
			else
				ft_error("Missing object in area light.\n");
		}
	}
	xmlXPathFreeObject(xpathobj);
}
