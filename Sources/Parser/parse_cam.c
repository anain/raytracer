/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cam.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 22:15:49 by anain             #+#    #+#             */
/*   Updated: 2018/04/25 00:02:13 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	print_xmlcam_usage(void)
{
	ft_putstr("XML ERROR : CAMERA NODE\n--------------------------\n<h");
	ft_putstr("<eye> COORDINATES x y z </eye>\n");
	ft_putstr("<look_at> COORDINATES x y z </look_at>\n");
	ft_putstr("<zoom> ZOOM </zoom>\n");
	ft_putstr("<direction> DIRECTIONAL VECTOR x y z </direction>\n");
	ft_error("--------------------------\n");
}

void	parse_cam1(xmlDocPtr doc, xmlNodePtr cur, t_world *world)
{
	xmlChar *xmldata;

	xmldata = find_data(doc, cur, "../eye");
	if (!xmldata)
		print_xmlcam_usage();
	set_point(xmldata, &world->camera.eye);
	xmlFree(xmldata);
	xmldata = find_data(doc, cur, "../distance");
	if (!xmldata)
		print_xmlcam_usage();
	world->camera.pin.d = ft_atod((char *)xmldata);
	xmlFree(xmldata);
}

void	parse_cam2(xmlDocPtr doc, xmlNodePtr cur, t_world *world)
{
	xmlChar *xmldata;

	xmldata = find_data(doc, cur, "../look_at");
	if (!xmldata)
		print_xmlcam_usage();
	set_point(xmldata, &world->camera.look_at);
	xmlFree(xmldata);
	xmldata = find_data(doc, cur, "../zoom");
	if (!xmldata)
		print_xmlcam_usage();
	world->camera.pin.zoom = ft_atod((char *)xmldata);
	xmlFree(xmldata);
	xmldata = find_data(doc, cur, "../direction");
	if (!xmldata)
		print_xmlcam_usage();
	set_vector(xmldata, &world->camera.up);
	normalize(&world->camera.up);
	xmlFree(xmldata);
}

void	parse_cam(xmlDocPtr doc, xmlNodePtr cur, t_world *world)
{
	if (!cur)
		print_xmlcam_usage();
	parse_cam1(doc, cur, world);
	parse_cam2(doc, cur, world);
	compute_uvw(&world->camera);
	world->camera.eye_lookat_dist = \
	distance(&world->camera.look_at, world->camera.eye);
}
