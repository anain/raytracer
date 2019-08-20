/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spot2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:48:02 by asavann           #+#    #+#             */
/*   Updated: 2018/04/23 18:50:19 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "spot.h"
#include "world.h"
#include <stdio.h>

t_vector3d			get_directions(t_light *l, t_shaderec *sr)
{
	t_vector3d res;

	res = getvector(&l->spot.location, sr->hit_point);
	return (hat(&res));
}

t_rgbcolor			lspot(t_light *l, t_shaderec *sr)
{
	if (sr)
		;
	return (rgbmult(&l->spot.color, l->spot.ls));
}

void				set_location(t_spot *spot, \
		const float x, const float y, const float z)
{
	point3dsetvalue(&spot->location, x, y, z);
}

int					in_shadows(\
		const t_light *light, const t_ray ray, const t_shaderec sr)
{
	float		t;
	float		d;
	int			j;
	t_object	*tmp;

	j = 0;
	d = distance(&light->spot.location, ray.o);
	tmp = sr.w->begin;
	while (tmp != NULL)
	{
		if (tmp->shadow == 1 && tmp->shadow_hit(tmp, ray, &t) && t < d)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

float				pdfspot(t_light *light, t_shaderec *sr)
{
	if (light && sr)
		;
	return (1);
}
