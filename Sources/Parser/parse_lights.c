/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lights.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <anain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 22:15:56 by anain             #+#    #+#             */
/*   Updated: 2018/04/25 00:05:00 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "partsphere.h"
#include "emissive.h"
#include "environmentlight.h"
#include <stdio.h>

t_light		*addlight(t_light **l)
{
	t_light *light;
	t_light	*last;

	if (!(last = (t_light *)malloc(sizeof(t_light))))
		ft_error(MALLOC_ERR);
	last->next = NULL;
	if (!*l)
	{
		*l = last;
		return (*l);
	}
	light = *l;
	while ((*l)->next != NULL)
		*l = (*l)->next;
	(*l)->next = last;
	*l = light;
	return (last);
}

t_object	*addobj(t_object **o, t_world *world)
{
	t_object	*obj;
	t_object	*last;

	if (!(last = (t_object *)malloc(sizeof(t_object))))
		ft_error(MALLOC_ERR);
	last->next = NULL;
	if (!*o)
	{
		*o = last;
		world->begin = *o;
		return (*o);
	}
	obj = *o;
	while ((*o)->next != NULL)
		*o = (*o)->next;
	(*o)->next = last;
	*o = obj;
	return (last);
}

void		parse_amb(xmlDocPtr doc, xmlNodePtr cur,\
					t_ambient *amb)
{
	xmlChar	*xmldata;

	xmldata = find_data(doc, cur, "../intensity");
	amb->ls = ft_atod((char *)xmldata);
	xmlFree(xmldata);
	xmldata = find_data(doc, cur, "../color");
	set_colorp(xmldata, &amb->color);
	xmlFree(xmldata);
	if (amb->ls < 0)
		ft_error("error in the definition of basic ambient.\n");
}

static void	parse_light2(xmlDocPtr doc, xmlNodePtr cur, t_world *world)
{
	xmlXPathObjectPtr	xpathobj;
	int					i;

	i = -1;
	xpathobj = findnodesbyname(doc, cur, (const xmlChar *)"../AO");
	if (xpathobj->nodesetval->nodeNr > 0)
	{
		parse_ao(doc,\
		xpathobj->nodesetval->nodeTab[0]->xmlChildrenNode, &world->ao);
		world->ambient = lao;
	}
	xmlXPathFreeObject(xpathobj);
	xpathobj = findnodesbyname(doc, cur, (const xmlChar *)"../basic_ambient");
	if (xpathobj->nodesetval->nodeNr > 0)
		parse_amb(doc,\
		xpathobj->nodesetval->nodeTab[0]->xmlChildrenNode, &world->amb);
	xmlXPathFreeObject(xpathobj);
	xpathobj = findnodesbyname(doc, cur, (const xmlChar *)"../area_light");
	while (++i < xpathobj->nodesetval->nodeNr)
		parse_area(doc,\
		xpathobj->nodesetval->nodeTab[0]->xmlChildrenNode, world);
	xmlXPathFreeObject(xpathobj);
	parse_pathtracer(doc, cur, world);
}

void		parse_lights(xmlDocPtr doc, xmlNodePtr cur, t_world *world)
{
	xmlXPathObjectPtr	xpathobj;
	int					i;

	i = -1;
	init_amb(&world->amb);
	world->ambient = lamb;
	if (!cur)
		ft_error("Light error.\n");
	xpathobj = findnodesbyname(doc, cur, (const xmlChar *)"../directional");
	while (++i < xpathobj->nodesetval->nodeNr)
		parse_directional_light(doc,\
		xpathobj->nodesetval->nodeTab[i]->xmlChildrenNode, &world->light);
	xmlXPathFreeObject(xpathobj);
	xpathobj = findnodesbyname(doc, cur, (const xmlChar *)"../spot");
	i = -1;
	while (++i < xpathobj->nodesetval->nodeNr)
		parse_spot_light(doc,\
		xpathobj->nodesetval->nodeTab[i]->xmlChildrenNode, &world->light);
	xmlXPathFreeObject(xpathobj);
	xpathobj = findnodesbyname(doc, cur, (const xmlChar *)"../environment");
	if (xpathobj->nodesetval->nodeNr > 0)
		parse_environment_light(doc,\
		xpathobj->nodesetval->nodeTab[0]->xmlChildrenNode, world);
	xmlXPathFreeObject(xpathobj);
	parse_light2(doc, cur, world);
}
