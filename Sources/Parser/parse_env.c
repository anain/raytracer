/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 16:23:17 by asavann           #+#    #+#             */
/*   Updated: 2018/04/25 00:13:08 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "environmentlight.h"
#include "emissive.h"

static void		set_el(t_light **light, t_object **obj, int ns)
{
	(*light)->get_direction = get_directionel;
	(*light)->l = lel;
	(*light)->g = gdir;
	(*light)->pdf = pdfel;
	(*light)->in_shadow = in_shadowel;
	(*light)->el.materialptr = &(*obj)->mat;
	(*obj)->mat.shade = area_light_shade;
	(*obj)->mat.path_shade = area_light_shade;
	(*obj)->mat.get_le = get_le;
	(*obj)->sphere.center = (t_point3d){0, 0, 0};
	(*obj)->sphere.radius = 1000000;
	(*obj)->sphere.kepsilon = 0.000001;
	(*obj)->shadow = 0;
	(*obj)->hit = concavespherehit;
	(*obj)->shadow_hit = concavespherehitshadow;
	(*obj)->type = 0;
	(*obj)->mat.tex.path = NULL;
	set_samplerel(&(*light)->el, ns);
}

void			parse_environment_light(xmlDocPtr doc, xmlNodePtr cur,\
				t_world *w)
{
	xmlChar		*xmldata;
	t_light		*light;
	t_object	*obj;
	int			ns;

	if (!(cur))
		ft_error("Error in the definition of env.\n");
	light = addlight(&w->light);
	obj = addobj(&w->object, w);
	xmldata = find_data(doc, cur, "../shadow");
	light->shadow = ft_atod((char *)xmldata);
	xmlFree(xmldata);
	xmldata = find_data(doc, cur, "../color");
	set_colorp(xmldata, &obj->mat.emissive.ce);
	xmlFree(xmldata);
	xmldata = find_data(doc, cur, "../intensity");
	obj->mat.emissive.ls = ft_atod((char *)xmldata);
	xmlFree(xmldata);
	xmldata = find_data(doc, cur, "../numsamples");
	ns = ft_atod((char *)xmldata);
	xmlFree(xmldata);
	if (obj->mat.emissive.ls < 0 || (light->shadow != 0 && light->shadow != 1)\
	|| !is_perfectsquare(ns) || ns <= 0)
		ft_error("Error in the definition of a environment light.\n");
	set_el(&light, &obj, ns);
}
