/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_partocylinder2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 17:47:42 by jorobin           #+#    #+#             */
/*   Updated: 2018/04/22 23:37:16 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	set_partocylinder7(t_object *object, xmlNodePtr child, xmlChar *xmldata)
{
	double *a;

	a = NULL;
	if (xmlStrcmp(child->name, (const xmlChar *)"phimax") == 0)
	{
		if ((a = ft_atod_safe((char*)xmldata)) == NULL)
		{
			xmlFree(xmldata);
			ft_partocylinder_error();
		}
		free(a);
		a = ft_atod_safe((char*)xmldata);
		object->pocylinder.phi_max = *a * M_PI / 180.0;
		free(a);
	}
}

void	set_partocylinder5(t_object *object, xmlNodePtr child, xmlChar *xmldata)
{
	double *a;

	a = NULL;
	if (xmlStrcmp(child->name, (const xmlChar *)"phimin") == 0)
	{
		if ((a = ft_atod_safe((char*)xmldata)) == NULL)
		{
			xmlFree(xmldata);
			ft_partocylinder_error();
		}
		free(a);
		a = ft_atod_safe((char*)xmldata);
		object->pocylinder.phi_min = *a * M_PI / 180.0;
		free(a);
	}
	set_partocylinder7(object, child, xmldata);
}

void	set_partocylinder4(t_object *object, xmlNodePtr child, xmlChar *xmldata)
{
	double *a;

	a = NULL;
	if (xmlStrcmp(child->name, (const xmlChar *)"radius") == 0)
	{
		if ((a = ft_atod_safe((char*)xmldata)) == NULL)
		{
			xmlFree(xmldata);
			ft_partocylinder_error();
		}
		free(a);
		a = ft_atod_safe((char*)xmldata);
		object->pocylinder.radius = *a;
		free(a);
	}
	set_partocylinder5(object, child, xmldata);
}
