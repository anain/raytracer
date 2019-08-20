/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_area.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 19:20:24 by asavann           #+#    #+#             */
/*   Updated: 2018/04/25 00:12:09 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "arealight.h"
#include "emissive.h"

static void	set_func_area(t_light **li)
{
	(*li)->get_direction = get_direction_arealight;
	(*li)->l = larea;
	(*li)->g = garea;
	(*li)->pdf = pdfarea;
	(*li)->in_shadow = in_shadowarea;
	(*li)->shadow = 1;
}

void		parse_area(xmlDocPtr doc, xmlNodePtr cur, t_world *world)
{
	xmlChar		*xmldata;
	t_light		*light;
	t_object	*obj;
	int			ns;

	if (!(cur))
		ft_error("Error in the definition of area_light.\n");
	light = addlight(&world->light);
	obj = addobj(&world->object, world);
	xmldata = find_data(doc, cur, "../intensity");
	obj->mat.emissive.ls = ft_atod((char *)xmldata);
	xmlFree(xmldata);
	xmldata = find_data(doc, cur, "../color");
	set_colorp(xmldata, &obj->mat.emissive.ce);
	xmlFree(xmldata);
	xmldata = find_data(doc, cur, "../numsamples");
	ns = ft_atod((char *)xmldata);
	xmlFree(xmldata);
	if (obj->mat.emissive.ls < 0 || !is_perfectsquare(ns) || ns <= 0)
		ft_error("Error in the definition of area light.\n");
	parse_lobject(doc, cur, world, ns);
	set_func_area(&light);
	obj->type = 0;
	light->arealight.material = &obj->mat;
	light->arealight.object = *obj;
}
