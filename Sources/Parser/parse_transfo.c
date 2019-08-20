/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_transfo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <anain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 14:01:10 by anain             #+#    #+#             */
/*   Updated: 2018/04/24 22:16:07 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	scaling_generic(t_matrix *matrix, t_point3d p)
{
	t_matrix transfo;

	if (p.x == 0 || p.y == 0 || p.z == 0)
	{
		ft_putstr("Scaling by 0 not authorized.\n");
		print_xmltransfo_usage();
	}
	set_identity(&transfo);
	transfo.m[0][0] = 1 / p.x;
	transfo.m[1][1] = 1 / p.y;
	transfo.m[2][2] = 1 / p.z;
	*matrix = matrixmult(matrix, transfo);
}

void	parserot(xmlDocPtr doc, t_object *o,\
	xmlNodePtr transfonode)
{
	xmlChar		*xmldata;
	t_point3d	p;

	xmldata = find_optional_data(doc, transfonode, "../rotation");
	if (xmldata)
	{
		if (!set_point(xmldata, &p))
			print_xmltransfo_usage();
		rotate_x(&o->mat.inv_mat, p.x);
		rotate_y(&o->mat.inv_mat, p.y);
		rotate_z(&o->mat.inv_mat, p.z);
		rotate_x(&o->inv_mat, p.x);
		rotate_y(&o->inv_mat, p.y);
		rotate_z(&o->inv_mat, p.z);
	}
	xmlFree(xmldata);
}

void	parsescale(xmlDocPtr doc, t_object *o,\
	xmlNodePtr transfonode)
{
	xmlChar		*xmldata;
	t_point3d	p;

	xmldata = find_optional_data(doc, transfonode, "../scaling");
	if (!xmldata)
		return ;
	if (!set_point(xmldata, &p))
		print_xmltransfo_usage();
	scale(o, p.x, p.y, p.z);
	scaling_generic(&o->mat.inv_mat, p);
	xmlFree(xmldata);
}

void	parsetranslate(xmlDocPtr doc, t_object *o,\
	xmlNodePtr transfonode)
{
	xmlChar		*xmldata;
	t_point3d	p;
	float		r;

	r = o->sphere.radius;
	o->sphere.radius = 1;
	xmldata = find_optional_data(doc, transfonode, "../translation");
	if (!(char *)xmldata)
		return ;
	if (!set_point(xmldata, &p))
		print_xmltransfo_usage();
	translate(o, p.x, p.y, p.z);
	translate_tex(o, p.x, p.y, p.z);
	o->sphere.radius = r;
	xmlFree(xmldata);
}
