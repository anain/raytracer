/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_limcone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 20:00:40 by asavann           #+#    #+#             */
/*   Updated: 2018/04/24 22:37:30 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "limcone.h"

void	set_limcone5(t_object *object, xmlNodePtr child, xmlChar *xmldata)
{
	double *a;

	if (xmlStrcmp(child->name, (const xmlChar *)"top") == 0)
	{
		if ((a = ft_atod_safe((char*)xmldata)) == NULL)
		{
			xmlFree(xmldata);
			ft_cone_error();
		}
		free(a);
		a = ft_atod_safe((char*)xmldata);
		object->lcone.y1 = *a;
		free(a);
	}
}

void	set_limcone4(t_object *object, xmlNodePtr child, xmlChar *xmldata)
{
	double *a;

	a = NULL;
	if (xmlStrcmp(child->name, (const xmlChar *)"bottom") == 0)
	{
		if ((a = ft_atod_safe((char*)xmldata)) == NULL)
		{
			xmlFree(xmldata);
			ft_cone_error();
		}
		free(a);
		a = ft_atod_safe((char*)xmldata);
		object->lcone.y0 = *a;
		free(a);
	}
	set_limcone5(object, child, xmldata);
}

void	set_limcone3(t_object *object, xmlNodePtr child, xmlChar *xmldata)
{
	double *a;

	if (xmlStrcmp(child->name, (const xmlChar *)"height") == 0)
	{
		if ((a = ft_atod_safe((char*)xmldata)) == NULL)
		{
			xmlFree(xmldata);
			ft_cone_error();
		}
		free(a);
		a = ft_atod_safe((char*)xmldata);
		object->lcone.h = *a;
		free(a);
	}
	set_limcone4(object, child, xmldata);
}

void	set_limcone2(t_object *object, xmlNodePtr child, xmlChar *xmldata)
{
	double *a;

	a = NULL;
	if (xmlStrcmp(child->name, (const xmlChar *)"radius") == 0)
	{
		if ((a = ft_atod_safe((char*)xmldata)) == NULL)
		{
			xmlFree(xmldata);
			ft_cone_error();
		}
		free(a);
		a = ft_atod_safe((char*)xmldata);
		object->lcone.radius = *a;
		free(a);
	}
	set_limcone3(object, child, xmldata);
}

void	set_limcone(xmlDocPtr doc, t_object *object, xmlNodePtr cur)
{
	xmlChar		*xmldata;
	xmlNodePtr	child;

	object->type = 14;
	child = cur;
	object->lcone.radius = 0;
	if (!(cur))
		ft_cone_error();
	while (child != NULL)
	{
		xmldata = xmlNodeListGetString(doc, child->xmlChildrenNode, 0);
		if (xmldata)
		{
			set_limcone2(object, child, xmldata);
			xmlFree(xmldata);
		}
		child = child->next;
	}
	if (!object->lcone.radius)
		ft_cone_error();
	set_limcone6(object);
	xmlFree(xmldata);
	set_object_generic(doc, object, cur);
}
