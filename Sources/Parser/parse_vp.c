/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 22:16:01 by anain             #+#    #+#             */
/*   Updated: 2018/04/25 00:15:40 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	print_xmlvp_usage(void)
{
	ft_putstr("XML ERROR : VIEWPLANE NODE\n--------------------------\n<h");
	ft_putstr("res> HORIZONTAL RESOLUTION </hres>\n<vres> VERTICAL RESO");
	ft_putstr("LUTION </vres>\n");
	ft_putstr("<antialiasing> SAM");
	ft_putstr("PLE NUMBER </antialiasing>\n<backgroundcolor> { R, G, B } ");
	ft_putstr("</backgroundcolor>\n<show_out_of_g");
	ft_putstr("amut> OUT OF  GAMUT (1 or 0) </show_out_of_gamut>\n<max_d");
	ft_error("epth> MAX DEPTH </max_depth>\n--------------------------\n");
}

void	parse_vp2(xmlChar *xmldata, xmlNodePtr cur, t_world *world)
{
	if (xmlStrcmp(cur->name, (const xmlChar *)"hres") == 0)
		world->vp.hres = ft_atod((char*)xmldata);
	else if (xmlStrcmp(cur->name, (const xmlChar *)"vres") == 0)
		world->vp.vres = ft_atod((char*)xmldata);
	else if (xmlStrcmp(cur->name, (const xmlChar *)"antialiasing") == 0)
	{
		world->vp.numsamples = ft_atod((char*)xmldata);
		is_perfectsquare(world->vp.numsamples);
	}
	else if (xmlStrcmp(cur->name, (const xmlChar *)"backgroundcolor") == 0)
		set_rgb(xmldata, &world->vp.background_color);
	else if (xmlStrcmp(cur->name, (const xmlChar *)"show_out_of_gamut") == 0)
		world->vp.show_out_of_gamut = ft_atod((char*)xmldata);
	else if (xmlStrcmp(cur->name, (const xmlChar *)"max_depth") == 0)
		world->vp.max_depth = ft_atod((char*)xmldata);
}

void	parse_vp(xmlDocPtr doc, xmlNodePtr cur, t_world *world)
{
	xmlChar		*xmldata;

	xmldata = NULL;
	while (cur != NULL)
	{
		xmldata = xmlNodeListGetString(doc, cur->xmlChildrenNode, 0);
		if (xmldata)
		{
			parse_vp2(xmldata, cur, world);
			xmlFree(xmldata);
		}
		cur = cur->next;
	}
	if (world->vp.hres <= 0 || world->vp.vres <= 0 ||\
		!is_perfectsquare(world->vp.numsamples) || world->vp.numsamples <= 0)
		print_xmlvp_usage();
	if (world->vp.max_depth > 300)
		ft_error("Max depth cannot be superior to 300.");
	set_sample(&world->vp, world->vp.numsamples);
}
