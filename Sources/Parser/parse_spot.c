/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_spot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 16:21:59 by asavann           #+#    #+#             */
/*   Updated: 2018/04/22 23:44:06 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void		set_func_spot(t_light **light)
{
	(*light)->get_direction = get_directions;
	(*light)->l = lspot;
	(*light)->g = gspot;
	(*light)->pdf = pdfspot;
	(*light)->in_shadow = in_shadows;
}

void			parse_spot_light(xmlDocPtr doc, xmlNodePtr cur,\
				t_light **li)
{
	xmlChar *xmldata;
	t_light	*light;

	if (!(cur))
		ft_error("Error in the definition of a spot light.\n");
	light = addlight(li);
	xmldata = find_data(doc, cur, "../shadow");
	light->shadow = ft_atod((char *)xmldata);
	xmlFree(xmldata);
	xmldata = find_data(doc, cur, "../color");
	set_colorp(xmldata, &light->spot.color);
	xmlFree(xmldata);
	xmldata = find_data(doc, cur, "../location");
	set_point(xmldata, &light->spot.location);
	xmlFree(xmldata);
	xmldata = find_data(doc, cur, "../intensity");
	light->spot.ls = ft_atod((char *)xmldata);
	xmlFree(xmldata);
	if ((light->shadow != 1 && light->shadow != 0) || light->spot.ls < 0)
		ft_error("Error in the definition of a spot.");
	set_func_spot(&light);
}
