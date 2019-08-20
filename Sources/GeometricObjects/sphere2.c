/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 19:01:35 by asavann           #+#    #+#             */
/*   Updated: 2018/04/22 18:07:30 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"
#include <math.h>
#include <stdio.h>

static int			quadrasolutionshadow(\
						t_quadra q, const t_sphere *sphere, float *tmin)
{
	double		t;

	q.e = sqrt(q.disc);
	q.denom = 2.0 * q.a;
	t = (-q.b - q.e) / q.denom;
	if (t > sphere->kepsilon)
	{
		*tmin = t;
		return (1);
	}
	t = (-q.b + q.e) / q.denom;
	if (t > sphere->kepsilon)
	{
		*tmin = t;
		return (1);
	}
	return (0);
}

int					spherehitshadow(\
						const t_object *o, const t_ray ray, float *tmin)
{
	t_quadra	quadra;

	quadra.tmp = getvector(&ray.o, o->sphere.center);
	quadra.a = dotproduct(&ray.d, ray.d);
	quadra.b = dotproduct(&ray.d, quadra.tmp) * 2;
	quadra.c =
	dotproduct(&quadra.tmp, quadra.tmp) - o->sphere.radius * o->sphere.radius;
	quadra.disc = quadra.b * quadra.b - 4.0 * quadra.a * quadra.c;
	vector3deq(&quadra.r.d, ray.d);
	point3deq(&quadra.r.o, ray.o);
	if (quadra.disc < 0)
		return (0);
	else
		return (quadrasolutionshadow(quadra, &o->sphere, tmin));
	return (0);
}

t_normal			sphere_get_normal(t_object *o, t_point3d *sp)
{
	t_vector3d	v;

	v = getvector(sp, o->sphere.center);
	normalize(&v);
	return ((t_normal){v.x, v.y, v.z});
}

float				sphere_pdf(t_object *o, t_shaderec *sr)
{
	if (sr)
		;
	return (o->sphere.inv_area);
}

t_point3d			sphere_sample(t_object *o)
{
	t_point3d	sp;

	sp = sample_unit_sphere(&o->sphere.sampler);
	sp = addpoint(sp, o->sphere.center);
	sp = multpoint(&sp, o->sphere.radius);
	return (sp);
}
