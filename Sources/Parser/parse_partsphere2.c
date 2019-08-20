/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_partsphere2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 17:47:36 by jorobin           #+#    #+#             */
/*   Updated: 2018/04/22 23:39:13 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	set_theta2(t_object *object, xmlNodePtr child, xmlChar *xmldata)
{
	double *a;

	a = NULL;
	if (xmlStrcmp(child->name, (const xmlChar *)"thetamax") == 0)
	{
		if ((a = ft_atod_safe((char*)xmldata)) == NULL)
		{
			xmlFree(xmldata);
			ft_partsphere_error();
		}
		free(a);
		a = ft_atod_safe((char*)xmldata);
		object->partsphere.theta_max = *a;
		free(a);
	}
}

void	set_theta(t_object *object, xmlNodePtr child, xmlChar *xmldata)
{
	double *a;

	a = NULL;
	if (xmlStrcmp(child->name, (const xmlChar *)"thetamin") == 0)
	{
		if ((a = ft_atod_safe((char*)xmldata)) == NULL)
		{
			xmlFree(xmldata);
			ft_partsphere_error();
		}
		free(a);
		a = ft_atod_safe((char*)xmldata);
		object->partsphere.theta_min = *a;
		free(a);
	}
	set_theta2(object, child, xmldata);
}

void	set_phi2(t_object *object, xmlNodePtr child, xmlChar *xmldata)
{
	double *a;

	a = NULL;
	if (xmlStrcmp(child->name, (const xmlChar *)"phimax") == 0)
	{
		if ((a = ft_atod_safe((char*)xmldata)) == NULL)
		{
			xmlFree(xmldata);
			ft_partsphere_error();
		}
		free(a);
		a = ft_atod_safe((char*)xmldata);
		object->partsphere.phi_max = *a;
		free(a);
	}
}

void	set_phi(t_object *object, xmlNodePtr child, xmlChar *xmldata)
{
	double *a;

	a = NULL;
	if (xmlStrcmp(child->name, (const xmlChar *)"phimin") == 0)
	{
		if ((a = ft_atod_safe((char*)xmldata)) == NULL)
		{
			xmlFree(xmldata);
			ft_partsphere_error();
		}
		free(a);
		a = ft_atod_safe((char*)xmldata);
		object->partsphere.phi_min = *a;
		free(a);
	}
	set_phi2(object, child, xmldata);
}
