/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concavesphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 16:30:40 by asavann           #+#    #+#             */
/*   Updated: 2018/04/22 17:18:02 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int		quadrasolution(\
	t_quadra q, const t_sphere *sphere, double *tmin, t_shaderec *sr)
{
	double		t;
	t_vector3d	tmp2;

	q.e = sqrt(q.disc);
	q.denom = 2.0 * q.a;
	t = (-q.b - q.e) / q.denom;
	t = (t > sphere->kepsilon) ? t : (-q.b + q.e) / q.denom;
	if (t > sphere->kepsilon)
	{
		*tmin = t;
		tmp2 = addvector3d(&q.tmp, multvector3d(&q.r.d, t));
		normaleqv(&sr->normal, divvector3d(&tmp2, sphere->radius));
		if (normaldotproduct(&sr->normal, vector3dneg(&q.r.d)) < 0)
		{
			sr->normal = normalneg(&sr->normal);
		}
		sr->local_hit_point = addvector(&q.r.o, multvector3d(&q.r.d, t));
		return (1);
	}
	return (0);
}

int				concavespherehit(\
	const t_object *o, const t_ray ray, double *tmin, t_shaderec *sr)
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
		return (quadrasolution(quadra, &o->sphere, tmin, sr));
	return (0);
}

static int		quadrasolutionshadow(\
	t_quadra q, const t_sphere *sphere, float *tmin)
{
	double		t;

	q.e = sqrt(q.disc);
	q.denom = 2.0 * q.a;
	t = (-q.b - q.e) / q.denom;
	if (tmin)
		;
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

int				concavespherehitshadow(\
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
