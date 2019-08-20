/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_objects_material.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 19:12:26 by anain             #+#    #+#             */
/*   Updated: 2018/04/24 17:17:03 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	print_xmlmat_usage(void)
{
	ft_putstr("XML ERROR : MATERIAL NODE\n--------------------------\n");
	ft_putstr("<basic_material> MATERIAL </basic_material>\n basic_material :");
	ft_putstr("\'matte\' or \'phong\' or \'transparence\' or \'mirror'\n");
	ft_putstr("<special_effect> EFFECT </special_effect>\n special_effect : ");
	ft_putstr("\'texture\' or \'noise\' or \'chess\'.\n ");
	ft_error("--------------------------\n");
}

int		set_basic_mat(xmlDocPtr doc, t_object *object, xmlNodePtr cur,\
int basis)
{
	if (basis == 1)
	{
		ft_putstr("Choose a single basic material.\n");
		print_xmlmat_usage();
	}
	if (xmlStrcmp(cur->name, (const xmlChar *)"phong") == 0)
		phong(doc, object, cur->xmlChildrenNode);
	else if (xmlStrcmp(cur->name, (const xmlChar *)"matte") == 0)
		matte(doc, object, cur->xmlChildrenNode);
	else if (xmlStrcmp(cur->name, (const xmlChar *)"mirror") == 0)
		mirror(doc, object, cur->xmlChildrenNode);
	else if (xmlStrcmp(cur->name, (const xmlChar *)"transparence") == 0)
		transparence(doc, object, cur->xmlChildrenNode);
	return (1);
}

int		set_textures(xmlDocPtr doc, t_object *object, xmlNodePtr cur, int text)
{
	if (text == 1)
	{
		ft_putstr("Choose a single special effect : ");
		ft_error("\'texture\' or \'noise\' or \'chess\'");
		print_xmlmat_usage();
	}
	if (xmlStrcmp(cur->name, (const xmlChar *)"texture") == 0)
		texture(doc, object, cur->xmlChildrenNode);
	else if (xmlStrcmp(cur->name, (const xmlChar *)"noise") == 0)
		noise(doc, object, cur->xmlChildrenNode);
	else if (xmlStrcmp(cur->name, (const xmlChar *)"chess") == 0)
		chess(doc, object, cur->xmlChildrenNode);
	cur = cur->next;
	return (1);
}

void	set_material(xmlDocPtr doc, t_object *object, xmlNodePtr cur)
{
	int basis;
	int text;

	basis = 0;
	text = 0;
	if (!(cur) || !(cur->xmlChildrenNode))
		print_xmlmat_usage();
	while (cur != NULL)
	{
		if (xmlStrcmp(cur->name, (const xmlChar *)"phong") == 0 || \
		xmlStrcmp(cur->name, (const xmlChar *)"matte") == 0 || \
		xmlStrcmp(cur->name, (const xmlChar *)"mirror") == 0 || \
		xmlStrcmp(cur->name, (const xmlChar *)"transparence") == 0)
			basis = set_basic_mat(doc, object, cur, basis);
		else if (xmlStrcmp(cur->name, (const xmlChar *)"texture") == 0 || \
		xmlStrcmp(cur->name, (const xmlChar *)"noise") == 0 || \
		xmlStrcmp(cur->name, (const xmlChar *)"chess") == 0)
		{
			text = set_textures(doc, object, cur, text);
		}
		else
			print_xmlmat_usage();
		cur = cur->next;
	}
}
