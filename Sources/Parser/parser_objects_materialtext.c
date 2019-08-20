/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_objects_materialtext.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 15:37:55 by anain             #+#    #+#             */
/*   Updated: 2018/04/24 21:55:21 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	error_sphere_mapping(void)
{
	ft_putstr("Mapping on a sphere : <mapping> MAPPING TYPE </mapping>.\n");
	ft_putstr("Mapping types : sphere_mapping || probe_mapping\n");
	print_xmltext_usage();
}

void	set_sphere_mapping(xmlDocPtr doc, t_object *object, xmlNodePtr node)
{
	xmlChar	*type;
	char	*typem;

	type = find_data(doc, node, "../mapping");
	typem = (char *)type;
	if (typem == NULL)
		error_sphere_mapping();
	if (ft_strcmp((char *)type, "sphere_mapping") == 0)
		object->mat.mapping = sphere_mapping;
	else if (ft_strcmp((char *)type, "probe_mapping") == 0)
		object->mat.mapping = probe_mapping;
	else
		error_sphere_mapping();
	xmlFree(type);
}

void	mapping(xmlDocPtr doc, t_object *obj, xmlNodePtr node)
{
	if (obj->type == SPHERE || obj->type == SKYBOX)
		set_sphere_mapping(doc, obj, node);
	else if (obj->type == CYLINDER)
	{
		obj->mat.mapping = cylindrical_mapping;
	}
	else if (obj->type == RECTANGLE)
		obj->mat.mapping = rectangular_mapping;
	else if (obj->type == PLANE)
		obj->mat.mapping = rectangular_mapping;
	else if (obj->type == CONE)
		obj->mat.mapping = cylindrical_mapping;
	else
	{
		ft_putstr("Texture mapping available for sphere, rectangle, ");
		ft_error("cylinder only.\n");
		ft_error("--------------------------\n");
	}
}

void	transfotext(t_object *obj, xmlNodePtr node, xmlChar *xmldata)
{
	t_point3d	p;

	if (!set_point(xmldata, &p))
		print_xmltransfo_usage();
	else if (xmlStrcmp(node->name, (const xmlChar *)"scaling") == 0)
		scaling_generic(&obj->mat.inv_mat, p);
	else if (xmlStrcmp(node->name, (const xmlChar *)"translation") == 0)
		translate_tex(obj, p.x, p.y, p.z);
	else if (xmlStrcmp(node->name, (const xmlChar *)"rotation") == 0)
	{
		rotate_x(&obj->mat.inv_mat, p.x);
		rotate_y(&obj->mat.inv_mat, p.y);
		rotate_z(&obj->mat.inv_mat, p.z);
	}
}

void	texture(xmlDocPtr doc, t_object *obj, xmlNodePtr node)
{
	xmlChar		*xmldata;

	if (!(node) || !(node->xmlChildrenNode))
		print_xmltext_usage();
	mapping(doc, obj, node);
	while (node != NULL)
	{
		xmldata = xmlNodeListGetString(doc, node->xmlChildrenNode, 0);
		if (xmlStrcmp(node->name, (const xmlChar *)"source") == 0)
			obj->mat.tex.path = ft_strdup((char *)xmldata);
		else if (xmlStrcmp(node->name, (const xmlChar *)"pattern") == 0)
			texture_bank(&obj->mat, (char *)xmldata);
		else if (xmlStrcmp(node->name, (const xmlChar *)"translation") == 0 \
		|| xmlStrcmp(node->name, (const xmlChar *)"rotation") == 0 || \
		xmlStrcmp(node->name, (const xmlChar *)"scaling") == 0)
			transfotext(obj, node, xmldata);
		node = node->next;
		xmlFree(xmldata);
	}
}
