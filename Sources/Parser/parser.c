/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 15:51:34 by anain             #+#    #+#             */
/*   Updated: 2018/04/22 20:16:59 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	print_xmlglobal_usage(void)
{
	ft_putstr("XML ERROR : \n--------------------------\n");
	ft_putstr("<camera> CAMERA NODES </camera>\n");
	ft_putstr("<viewplane> VIEWPLANE NODES </viewplane>\n");
	ft_putstr("<lights> LIGHTS NODES </lights>\n");
	ft_putstr("<objects> OBJECTS NODES </objects>\n");
	ft_error("--------------------------\n");
}

void	check(xmlDocPtr doc, xmlNodePtr cur, char *str)
{
	xmlXPathObjectPtr xpathobj;

	xpathobj = findnodesbyname(doc, cur, (const xmlChar *)str);
	if (xpathobj->nodesetval->nodeNr == 0)
		print_xmlglobal_usage();
	xmlXPathFreeObject(xpathobj);
}

void	parsedoc(xmlDocPtr doc, xmlNodePtr cur, t_world *world)
{
	int		i;
	char	*elem[4];
	void	(*tab[4])(xmlDocPtr doc, xmlNodePtr cur, t_world *world);

	elem[0] = "camera";
	elem[1] = "viewplane";
	elem[2] = "lights";
	elem[3] = "objects";
	tab[0] = parse_cam;
	tab[1] = parse_vp;
	tab[2] = parse_lights;
	tab[3] = parse_objects;
	i = -1;
	while (++i < 4)
		check(doc, cur, elem[i]);
	cur = cur->xmlChildrenNode;
	while (cur != NULL)
	{
		i = -1;
		while (++i < 4)
			if (xmlStrcmp(cur->name, (const xmlChar *)elem[i]) == 0)
				(tab[i])(doc, cur->xmlChildrenNode, world);
		cur = cur->next;
	}
}

void	get_obj_tab(t_world *w)
{
	char **tab;

	w->objnames = NULL;
	if (!(tab = (char**)malloc(sizeof(char*) * 16)))
		ft_error("MALLOC ERROR");
	tab[0] = "OTHER";
	tab[1] = "SPHERE";
	tab[2] = "PLANE";
	tab[3] = "CONE";
	tab[4] = "CYLINDER";
	tab[5] = "TRIANGLE";
	tab[6] = "RECTANGLE";
	tab[7] = "DISK";
	tab[8] = "PARTCYLINDER";
	tab[9] = "PARTSPHERE";
	tab[10] = "BOX";
	tab[11] = "PARABOLOID";
	tab[12] = "TORUS";
	tab[13] = "MICKEY";
	tab[14] = "LIMCONE";
	tab[15] = "SKYBOX";
	w->objnames = tab;
}

char	*parser(char *docname, t_world *world)
{
	xmlDocPtr	doc;
	xmlNodePtr	cur;

	xmlKeepBlanksDefault(0);
	doc = xmlParseFile(docname);
	if (doc == NULL)
		ft_error("Document parsing failed.\n");
	cur = xmlDocGetRootElement(doc);
	if (cur == NULL)
		ft_error("Parsing failed.");
	parsedoc(doc, cur, world);
	xmlFreeDoc(doc);
	get_obj_tab(world);
	return (NULL);
}
