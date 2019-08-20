/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_objects_materialtypes.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 12:22:06 by anain             #+#    #+#             */
/*   Updated: 2018/04/25 00:25:19 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	phong(xmlDocPtr doc, t_object *object, xmlNodePtr phong_node)
{
	xmlChar	*xmldata;
	int		ns;

	xmldata = find_data(doc, phong_node, "../numsamples");
	if (!xmldata)
		print_xmlphong_usage();
	ns = (int)(set_positive_value(xmldata));
	xmlFree(xmldata);
	if (is_perfectsquare(ns) && ns > 0)
	{
		set_samplerphong(&object->mat.phong.specular_brdf, ns);
		set_samplerlamb(&object->mat.phong.diffuse_brdf, ns);
	}
	else
	{
		ft_putstr("--------------------------\n");
		ft_putstr("numsamples should be a perfect square.\n");
		print_xmlphong_usage();
	}
	matte_compo(doc, &object->mat.phong.ambient_brdf, phong_node, 1);
	matte_compo(doc, &object->mat.phong.diffuse_brdf, phong_node, 2);
	phong_compo(doc, &object->mat.phong.specular_brdf, phong_node);
	object->mat.shade = shadephong;
	object->mat.path_shade = pathphong;
}

void	matte(xmlDocPtr doc, t_object *object, xmlNodePtr matte_node)
{
	xmlChar	*xmldata;
	int		ns;

	xmldata = find_data(doc, matte_node, "../numsamples");
	ns = (int)(set_positive_value(xmldata));
	xmlFree(xmldata);
	if (is_perfectsquare(ns) && ns > 0)
		set_samplerphong(&object->mat.phong.specular_brdf, ns);
	else
	{
		ft_putstr("numsamples should be a perfect square.");
		print_xmlphong_usage();
	}
	set_samplerlamb(&object->mat.matte.diffuse_brdf, ns);
	matte_compo(doc, &object->mat.matte.ambient_brdf, matte_node, 1);
	matte_compo(doc, &object->mat.matte.diffuse_brdf, matte_node, 2);
	object->mat.shade = shadematte;
	object->mat.path_shade = pathshadematte;
}

void	mirror(xmlDocPtr doc, t_object *object, xmlNodePtr reflective_node)
{
	matte_compo(doc, &object->mat.phong.ambient_brdf, reflective_node, 1);
	matte_compo(doc, &object->mat.phong.diffuse_brdf, reflective_node, 2);
	phong_compo(doc, &object->mat.phong.specular_brdf, reflective_node);
	mirror_compo(doc, &object->mat.reflective.perfectspecular, reflective_node);
	object->mat.shade = reflective;
	object->mat.path_shade = pathreflective;
}

void	transparence(xmlDocPtr doc, t_object *object,\
xmlNodePtr transparence_node)
{
	matte_compo(doc, &object->mat.phong.ambient_brdf, \
		transparence_node, 1);
	matte_compo(doc, &object->mat.phong.diffuse_brdf, \
		transparence_node, 2);
	phong_compo(doc, &object->mat.phong.specular_brdf, \
		transparence_node);
	mirror_compo(doc, &object->mat.reflective.perfectspecular, \
		transparence_node);
	transp_compo(doc, &object->mat.transparence.perft, transparence_node);
	if (object->mat.transparence.perft.kt + \
		object->mat.reflective.perfectspecular.kr != 1)
		print_xmltransparence_usage();
	object->mat.shade = shadetransp;
	object->mat.path_shade = pathtransp;
}
