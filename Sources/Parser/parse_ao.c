/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ao.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 17:27:37 by asavann           #+#    #+#             */
/*   Updated: 2018/04/25 00:13:46 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void			parse_ao(xmlDocPtr doc, xmlNodePtr cur,\
				t_ambientoccluder *ao)
{
	int		ns;
	xmlChar	*xmldata;

	if (!(cur))
		ft_error("Error in the definition of ambiant occluder.\n");
	xmldata = find_data(doc, cur, "../intensity");
	ao->ls = ft_atod((char *)xmldata);
	xmlFree(xmldata);
	xmldata = find_data(doc, cur, "../min_amount");
	ao->min_amount = ft_atod((char *)xmldata);
	xmlFree(xmldata);
	xmldata = find_data(doc, cur, "../color");
	set_colorp(xmldata, &ao->c);
	xmlFree(xmldata);
	xmldata = find_data(doc, cur, "../numsamples");
	ns = ft_atod((char *)xmldata);
	xmlFree(xmldata);
	if (ao->ls < 0 || ao->min_amount < 0 || ao->min_amount > 1 ||\
	!is_perfectsquare(ns) || ns <= 0)
		ft_error("Error in the definition of ambient occlusion.\n");
	set_samplerao(ao, ns);
}
