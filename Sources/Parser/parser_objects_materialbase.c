/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_objects_materialbase.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 12:56:05 by anain             #+#    #+#             */
/*   Updated: 2018/04/20 17:15:34 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	phong_compo(xmlDocPtr doc, t_glossyspecular *glossyspec,\
xmlNodePtr node)
{
	xmlChar		*xmldata;
	xmlNodePtr	p;

	p = node;
	xmldata = find_data(doc, node, "../glossy_coef");
	glossyspec->ks = set_coef(xmldata);
	xmlFree(xmldata);
	xmldata = find_data(doc, node, "../glossy_color");
	set_rgb(xmldata, &glossyspec->cs);
	xmlFree(xmldata);
	xmldata = find_data(doc, node, "../exp");
	glossyspec->exp = set_positive_value(xmldata);
	xmlFree(xmldata);
	node = p;
}

void	matte_compo(xmlDocPtr doc, t_lambertian *lambertian,\
xmlNodePtr node, int i)
{
	xmlChar *xmldata;

	if (i == 1)
	{
		xmldata = find_data(doc, node, "../ambient_coef");
		lambertian->kd = set_coef(xmldata);
		xmlFree(xmldata);
	}
	else if (i == 2)
	{
		xmldata = find_data(doc, node, "../diffuse_coef");
		lambertian->kd = set_coef(xmldata);
		xmlFree(xmldata);
	}
	xmldata = find_data(doc, node, "../color");
	set_rgb(xmldata, &lambertian->cd);
	xmlFree(xmldata);
}

void	mirror_compo(xmlDocPtr doc, t_perfectspecular *pf, xmlNodePtr node)
{
	xmlChar *xmldata;

	xmldata = find_data(doc, node, "../reflective_coef");
	pf->kr = set_coef(xmldata);
	xmlFree(xmldata);
	xmldata = find_data(doc, node, "../reflective_color");
	set_rgb(xmldata, &pf->cr);
	xmlFree(xmldata);
}

void	transp_compo(xmlDocPtr doc, t_transparence *transp, xmlNodePtr node)
{
	xmlChar *xmldata;

	xmldata = find_data(doc, node, "../transparence_coef");
	transp->kt = set_coef(xmldata);
	xmlFree(xmldata);
	xmldata = find_data(doc, node, "../ior");
	transp->ior = set_positive_value(xmldata);
	xmlFree(xmldata);
}
