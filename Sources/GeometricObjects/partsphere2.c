/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partsphere2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 18:30:20 by asavann           #+#    #+#             */
/*   Updated: 2018/04/21 14:11:53 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "partsphere.h"
#include "constants.h"

static int		root(t_quadra q, const t_partsphere *partsphere, float t)
{
	t_point3d	tmp;
	t_vector3d	hit;
	float		phi;

	tmp = addvector(&q.r.o, multvector3d(&q.r.d, t));
	hit = getvector(&tmp, partsphere->center);
	phi = atan2(hit.x, hit.z);
	if (phi < 0.0)
		phi += TWOPI;
	if (hit.x <= partsphere->radius * partsphere->cos_theta_min &&
	hit.y >= partsphere->radius * partsphere->cos_theta_max &&
	phi >= partsphere->phi_min && phi <= partsphere->phi_max)
		return (1);
	return (0);
}

static int		quadrasolution(\
	t_quadra q, const t_partsphere *partsphere, float *tmin)
{
	float		t;

	q.e = sqrt(q.disc);
	q.denom = 2.0 * q.a;
	t = (-q.b - q.e) / q.denom;
	if (t > partsphere->kepsilon)
	{
		if (root(q, partsphere, t) == 1)
		{
			*tmin = t;
			return (1);
		}
	}
	t = (-q.b + q.e) / q.denom;
	if (t > partsphere->kepsilon)
	{
		if (root(q, partsphere, t) == 1)
		{
			*tmin = t;
			return (1);
		}
	}
	return (0);
}

int				partspherehitshadow(\
	const t_object *o, const t_ray ray, float *tmin)
{
	t_quadra	quadra;

	quadra.tmp = getvector(&ray.o, o->partsphere.center);
	quadra.a = dotproduct(&ray.d, ray.d);
	quadra.b = dotproduct(&ray.d, quadra.tmp) * 2;
	quadra.c =
	dotproduct(&quadra.tmp, quadra.tmp)\
	- o->partsphere.radius * o->partsphere.radius;
	quadra.disc = quadra.b * quadra.b - 4.0 * quadra.a * quadra.c;
	vector3deq(&quadra.r.d, ray.d);
	point3deq(&quadra.r.o, ray.o);
	if (quadra.disc < 0)
		return (0);
	else
		return (quadrasolution(quadra, &o->partsphere, tmin));
	return (0);
}
