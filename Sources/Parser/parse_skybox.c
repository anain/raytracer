/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_skybox.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 22:08:39 by anain             #+#    #+#             */
/*   Updated: 2018/04/24 23:11:17 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_skybox_error(void)
{
	ft_putstr("XML ERROR : SKYBOX NODE\n--------------------------\n<tex");
	ft_putstr("ture>\n<pattern> </pattern>\n\t\t\tOR \n<source> \
		</source>\n</texture>\n");
	ft_error("--------------------------\n");
}

void	set_skybox_generic(xmlDocPtr doc, t_object *object, xmlNodePtr cur)
{
	t_point3d	savcenter;
	float		savradius;

	savcenter = object->sphere.center;
	savradius = object->sphere.radius;
	object->sphere.center = (t_point3d) {0, 0, 0};
	object->sphere.radius = 1;
	object->hittrans = spherehit;
	object->shadow_hittrans = spherehitshadow;
	set_object_generic(doc, object, cur);
	scaling_generic(&object->inv_mat, \
		(t_point3d) {savradius, savradius, savradius});
	scaling_generic(&object->mat.inv_mat,
		(t_point3d) {savradius, savradius, savradius});
	translate(object, savcenter.x, savcenter.y, savcenter.z);
	translate_tex(object, savcenter.x, savcenter.y, savcenter.z);
}

void	set_skybox(xmlDocPtr doc, t_object *object, xmlNodePtr cur)
{
	xmlNodePtr	child;

	if (!cur)
		ft_skybox_error();
	object->type = SKYBOX;
	child = cur;
	object->sphere.center = (t_point3d) {0, 0, 0};
	object->sphere.radius = 99990;
	object->sphere.kepsilon = 0.00001;
	set_skybox_generic(doc, object, cur);
}
