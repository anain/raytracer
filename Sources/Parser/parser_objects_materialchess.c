/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_objects_materialchess.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <anain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 20:38:57 by anain             #+#    #+#             */
/*   Updated: 2018/04/22 23:18:46 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	chess(xmlDocPtr doc, t_object *obj, xmlNodePtr node)
{
	xmlChar *xmldata;

	if (node != NULL)
		transformation(doc, obj, node);
	obj->mat.chess.size = 1;
	obj->mat.chess.color1 = (t_rgbcolor){1, 1, 1};
	obj->mat.chess.color2 = (t_rgbcolor){0, 0, 0};
	obj->mat.mapping = get_chess_color;
	while (node != NULL)
	{
		xmldata = xmlNodeListGetString(doc, node->xmlChildrenNode, 0);
		if (xmlStrcmp(node->name, (const xmlChar *)"color1") == 0)
			set_rgb(xmldata, &obj->mat.chess.color1);
		else if (xmlStrcmp(node->name, (const xmlChar *)"color2") == 0)
			set_rgb(xmldata, &obj->mat.chess.color2);
		else if (xmlStrcmp(node->name, (const xmlChar *)"size") == 0)
			obj->mat.chess.size = set_positive_value(xmldata);
		node = node->next;
		xmlFree(xmldata);
	}
}
