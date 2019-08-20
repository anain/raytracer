/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_objects_materialnoise.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <anain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 15:12:59 by anain             #+#    #+#             */
/*   Updated: 2018/04/21 23:10:06 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	print_xmlnoise_usage(void)
{
	ft_putstr("XML ERROR : NOISE NODE\n--------------------------\n");
	ft_putstr("<noise> NOISE FUNCTION </noise>\n");
	ft_putstr("noise_function :\'cubic_noise\' or \'fbm\' or \'fractalsum\'");
	ft_putstr(" or \'linear_noise\' or \'turbulence\'");
	ft_error("--------------------------\n");
}

void	noisefunc(t_object *obj, char *func)
{
	if (ft_strcmp(func, "fbm") == 0)
		obj->mat.fnoise = fbm;
	else if (ft_strcmp(func, "turbulence") == 0)
		obj->mat.fnoise = turbulence;
	else if (ft_strcmp(func, "linear_noise") == 0)
		obj->mat.fnoise = linear_noise;
	else if (ft_strcmp(func, "cubic_noise") == 0)
		obj->mat.fnoise = cubic_noise;
	else if (ft_strcmp(func, "fractalsum") == 0)
		obj->mat.fnoise = fractalsum;
	else
	{
		ft_putstr("Invalid noise function.\n");
		print_xmlnoise_usage();
	}
}

void	noise(xmlDocPtr doc, t_object *obj, xmlNodePtr node)
{
	xmlChar *xmldata;

	if (node == NULL)
		print_xmlnoise_usage();
	init_value_table(&obj->mat.noise);
	xmldata = xmlNodeListGetString(doc, node, 0);
	if (!xmldata)
		print_xmlnoise_usage();
	noisefunc(obj, (char *)xmldata);
	xmlFree(xmldata);
	obj->mat.mapping = set_noise;
}
