/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pathtracer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 21:37:19 by asavann           #+#    #+#             */
/*   Updated: 2018/04/21 21:41:08 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	parse_pathtracer(xmlDocPtr doc, xmlNodePtr cur, t_world *world)
{
	xmlXPathObjectPtr	xpathobj;

	xpathobj = findnodesbyname(doc, cur, (const xmlChar *)"../path_tracer");
	if (xpathobj->nodesetval->nodeNr > 0)
		world->tracer.t = path_trace;
	xmlXPathFreeObject(xpathobj);
}
