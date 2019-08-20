/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arealight.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 20:09:10 by asavann           #+#    #+#             */
/*   Updated: 2018/04/23 18:49:34 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arealight.h"
#include "world.h"
#include <stdio.h>
#include "camera.h"

t_vector3d		get_direction_arealight(t_light *light, t_shaderec *sr)
{
	light->arealight.sample_point =\
	light->arealight.object.sample(&light->arealight.object);
	light->arealight.light_normal =\
	light->arealight.object.get_normal(&light->arealight.object,\
		&light->arealight.sample_point);
	light->arealight.wi = getvector(&light->arealight.sample_point, \
		sr->hit_point);
	normalize(&light->arealight.wi);
	return (light->arealight.wi);
}

int				in_shadowarea(const t_light *light, \
	const t_ray ray, const t_shaderec sr)
{
	float		t;
	float		ts;
	t_object	*head;
	t_vector3d	d;

	d = getvector(&light->arealight.sample_point, ray.o);
	ts = dotproduct(&d, ray.d);
	head = sr.w->begin;
	while (head != NULL)
	{
		if (head->shadow == 1 && head->shadow_hit(head, ray, &t) && t < ts)
			return (1);
		head = head->next;
	}
	return (0);
}

t_rgbcolor		larea(t_light *light, t_shaderec *sr)
{
	float		ndotd;
	t_normal	nneg;

	nneg = normalneg(&light->arealight.light_normal);
	ndotd = normaldotproduct(&nneg, light->arealight.wi);
	if (ndotd > 0.0)
	{
		return (light->arealight.material->get_le(light->arealight.material, \
			sr));
	}
	return ((t_rgbcolor){0.0, 0.0, 0.0});
}

float			garea(t_light *light, t_shaderec *sr)
{
	float		ndotd;
	float		d2;
	t_normal	nneg;

	nneg = normalneg(&light->arealight.light_normal);
	ndotd = normaldotproduct(&nneg, light->arealight.wi);
	d2 = d_squared(&light->arealight.sample_point, sr->hit_point);
	return (ndotd / d2);
}

float			pdfarea(t_light *light, t_shaderec *sr)
{
	return (light->arealight.object.pdfo(&light->arealight.object, sr));
}
