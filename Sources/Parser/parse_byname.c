/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_byname.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 15:49:06 by anain             #+#    #+#             */
/*   Updated: 2018/04/21 21:29:26 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

xmlXPathObjectPtr	findnodesbyname(xmlDocPtr doc, xmlNodePtr rootnode,\
		const xmlChar *nodename)
{
	xmlXPathObjectPtr	xpathobj;
	xmlXPathContextPtr	xpathctx;

	xpathctx = xmlXPathNewContext(doc);
	if (xpathctx == NULL)
		ft_error("Error: unable to create new XPath context\n");
	xpathobj = xmlXPathNodeEval(rootnode, nodename, xpathctx);
	xmlXPathFreeContext(xpathctx);
	return (xpathobj);
}

xmlChar				*find_data(xmlDocPtr doc, xmlNodePtr node, char *str)
{
	xmlChar				*xmldata;
	xmlXPathObjectPtr	xpathobj;

	xpathobj = findnodesbyname(doc, node, (const xmlChar *)str);
	if (xpathobj->nodesetval->nodeNr == 0)
	{
		ft_putstr("Error in ");
		ft_putstr((char *)node->parent->name);
		ft_putstr(" : ");
		ft_putstr(str);
		ft_error(" not found.");
	}
	node = xpathobj->nodesetval->nodeTab[0]->xmlChildrenNode;
	xmldata = xmlNodeListGetString(doc, node, 0);
	if (node == NULL)
		ft_error("Error");
	xmlXPathFreeObject(xpathobj);
	return (xmldata);
}

xmlChar				*find_optional_data(xmlDocPtr doc, xmlNodePtr node,\
		char *str)
{
	xmlChar				*xmldata;
	xmlXPathObjectPtr	xpathobj;

	xpathobj = findnodesbyname(doc, node, (const xmlChar *)str);
	if (xpathobj->nodesetval->nodeNr == 0)
	{
		xmlXPathFreeObject(xpathobj);
		return (NULL);
	}
	node = xpathobj->nodesetval->nodeTab[0]->xmlChildrenNode;
	xmldata = xmlNodeListGetString(doc, node, 0);
	xmlXPathFreeObject(xpathobj);
	return (xmldata);
}
