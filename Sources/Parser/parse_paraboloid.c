/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_paraboloid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 17:47:48 by jorobin           #+#    #+#             */
/*   Updated: 2018/04/22 23:48:50 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_paraboloid_error(void)
{
	ft_putstr("hint :   scale can't be <= 0 !\n\t direction can't\
			be 0, 0, 0 !\n");
	ft_putstr("XML ERROR : PARABOLOID NODE\n--------------");
	ft_putstr("------------\n<diameter> DIAMETER </diam");
	ft_putstr("eter>\n<scale> SCALE </scale>\n");
	ft_putstr("<direction> X Y Z </direction>\n");
	ft_error("--------------------------\n");
}

void	set_paraboloid3(t_object *object, xmlNodePtr child, xmlChar *xmldata)
{
	double *a;

	a = NULL;
	if (xmlStrcmp(child->name, (const xmlChar *)"scale") == 0)
	{
		if ((a = ft_atod_safe((char*)xmldata)) == NULL)
		{
			xmlFree(xmldata);
			ft_paraboloid_error();
		}
		free(a);
		a = ft_atod_safe((char*)xmldata);
		object->paraboloid.k = *ft_atod_safe((char*)xmldata);
		free(a);
	}
}

void	set_paraboloid2(t_object *object, xmlNodePtr child, xmlChar *xmldata)
{
	if (xmlStrcmp(child->name, (const xmlChar *)"position") == 0)
	{
		if (!set_point(xmldata, &object->paraboloid.c))
		{
			xmlFree(xmldata);
			ft_paraboloid_error();
		}
	}
	else if (xmlStrcmp(child->name, (const xmlChar *)"direction") == 0)
	{
		if (!set_vector(xmldata, &object->paraboloid.v))
		{
			xmlFree(xmldata);
			ft_paraboloid_error();
		}
	}
	set_paraboloid3(object, child, xmldata);
}

void	set_paraboloid(xmlDocPtr doc, t_object *object, xmlNodePtr cur)
{
	xmlChar		*xmldata;
	xmlNodePtr	child;

	object->type = 11;
	child = cur;
	object->paraboloid.v = (t_vector3d) {0, 0, 0};
	object->paraboloid.k = 0;
	if (!(cur))
		ft_paraboloid_error();
	while (child != NULL)
	{
		xmldata = xmlNodeListGetString(doc, child->xmlChildrenNode, 0);
		if (xmldata)
		{
			set_paraboloid2(object, child, xmldata);
			xmlFree(xmldata);
		}
		child = child->next;
	}
	if ((object->paraboloid.k <= 0) || (!(object->paraboloid.v.x) &&\
		!(object->paraboloid.v.y) && !(object->paraboloid.v.z)))
		ft_paraboloid_error();
	object->paraboloid.kepsilon = 0.00001;
	object->d = object->paraboloid.c;
	set_object_generic(doc, object, cur);
}
