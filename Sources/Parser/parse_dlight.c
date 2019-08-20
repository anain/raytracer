/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dlight.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 16:21:24 by asavann           #+#    #+#             */
/*   Updated: 2018/04/21 21:33:04 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void		set_func_directional(t_light **light)
{
	(*light)->get_direction = get_direction;
	(*light)->l = l;
	(*light)->g = gdir;
	(*light)->pdf = pdfdir;
	(*light)->in_shadow = in_shadowd;
}

void			parse_directional_light(xmlDocPtr doc, xmlNodePtr cur,\
				t_light **li)
{
	xmlChar *xmldata;
	t_light	*light;

	if (!(cur))
		ft_error("Error in the definition of directional light.\n");
	light = addlight(li);
	xmldata = find_data(doc, cur, "../shadow");
	light->shadow = ft_atod((char *)xmldata);
	xmlFree(xmldata);
	xmldata = find_data(doc, cur, "../color");
	set_colorp(xmldata, &light->dlight.color);
	xmlFree(xmldata);
	xmldata = find_data(doc, cur, "../direction");
	set_vec(xmldata, &light->dlight.dir);
	xmlFree(xmldata);
	xmldata = find_data(doc, cur, "../intensity");
	light->dlight.ls = ft_atod((char *)xmldata);
	xmlFree(xmldata);
	if ((light->shadow != 1 && light->shadow != 0) || light->dlight.ls < 0)
		ft_error("Error in the definition of a directional light.");
	normalize(&light->dlight.dir);
	set_func_directional(&light);
}
