/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_disk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 17:48:02 by jorobin           #+#    #+#             */
/*   Updated: 2018/04/22 23:47:58 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_disk_error(void)
{
	ft_putstr("XML ERROR : DISK NODE\n--------------------------\n<cen");
	ft_putstr("ter> { X, Y, Z } </center>\n<radius> RADIUS");
	ft_putstr(" </radius>\n<normal> { X, Y, Z } </normal>\n");
	ft_putstr("--------------------------\n");
	ft_putstr("Radius must be > 0 && < int max\n");
	ft_error("Disk center at { 0, 0, 0 } if none\n");
}

void	set_disk3(t_object *object, xmlNodePtr child, xmlChar *xmldata)
{
	double *a;

	a = NULL;
	if (xmlStrcmp(child->name, (const xmlChar *)"radius") == 0)
	{
		if ((a = ft_atod_safe((char*)xmldata)) == NULL)
		{
			xmlFree(xmldata);
			ft_disk_error();
		}
		free(a);
		a = ft_atod_safe((char*)xmldata);
		object->disk.r = *a;
		free(a);
	}
}

void	set_disk2(t_object *object, xmlNodePtr child, xmlChar *xmldata)
{
	double *a;

	a = NULL;
	if (xmlStrcmp(child->name, (const xmlChar *)"center") == 0)
	{
		if (!set_point(xmldata, &object->disk.center))
		{
			xmlFree(xmldata);
			ft_disk_error();
		}
	}
	else if (xmlStrcmp(child->name, (const xmlChar *)"normal") == 0)
	{
		if (!set_normal(xmldata, &object->disk.normal))
		{
			xmlFree(xmldata);
			ft_disk_error();
		}
	}
	set_disk3(object, child, xmldata);
}

void	set_disk(xmlDocPtr doc, t_object *object, xmlNodePtr cur)
{
	xmlChar		*xmldata;
	xmlNodePtr	child;

	object->type = 7;
	object->disk.r = 0;
	child = cur;
	if (!(cur))
		ft_error("Error in the definition of disk.\n");
	while (child != NULL)
	{
		xmldata = xmlNodeListGetString(doc, child->xmlChildrenNode, 0);
		if (xmldata)
		{
			set_disk2(object, child, xmldata);
			xmlFree(xmldata);
		}
		child = child->next;
	}
	if (object->disk.r <= 0 || !(object->disk.r < INT_MAX))
		ft_disk_error();
	object->disk.r_squared = pow(object->disk.r, 2);
	object->disk.kepsilon = 0.00001;
	object->d = object->disk.center;
	set_object_generic(doc, object, cur);
}
