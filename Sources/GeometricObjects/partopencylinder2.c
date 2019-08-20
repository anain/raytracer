/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partopencylinder2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 19:50:51 by asavann           #+#    #+#             */
/*   Updated: 2018/04/24 19:51:35 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "partopencylinder.h"
#include "constants.h"
#include <math.h>
#include <stdio.h>

static int	quadrasolutioncs2(t_quadracp q, const t_partopencylinder *c,\
float *tmin)
{
	float		t;
	float		phi;
	t_point3d	tmp;

	t = (-q.b + q.e) / q.denom;
	tmp = addvector(&q.r.o, multvector3d(&q.r.d, t));
	if (t > c->kepsilon && (tmp.y >= c->y0 && tmp.y <= c->y1))
	{
		phi = atan2(tmp.x, tmp.z);
		if (phi < 0.0)
			phi += TWOPI;
		if (phi >= c->phi_min && phi <= c->phi_max)
		{
			*tmin = t;
			return (1);
		}
	}
	return (0);
}

int			quadrasolutioncs(\
	t_quadracp q, const t_partopencylinder *c, float *tmin)
{
	float		t;
	double		phi;
	t_point3d	tmp;

	q.e = sqrt(q.disc);
	q.denom = 2.0 * q.a;
	t = (-q.b - q.e) / q.denom;
	tmp = addvector(&q.r.o, multvector3d(&q.r.d, t));
	if (t > c->kepsilon && (tmp.y >= c->y0 && tmp.y <= c->y1))
	{
		phi = atan2(tmp.x, tmp.z);
		if (phi < 0.0)
			phi += TWOPI;
		if (phi >= c->phi_min && phi <= c->phi_max)
		{
			*tmin = t;
			return (1);
		}
	}
	return (quadrasolutioncs2(q, c, tmin));
}

int			partopencylinderhitshadow(\
			const t_object *o, const t_ray ray, float *tmin)
{
	t_quadracp quadra;

	quadra.ox = ray.o.x;
	quadra.oz = ray.o.z;
	quadra.dx = ray.d.x;
	quadra.dz = ray.d.z;
	quadra.a = quadra.dx * quadra.dx + quadra.dz * quadra.dz;
	quadra.b = 2.0 * (quadra.ox * quadra.dx + quadra.oz * quadra.dz);
	quadra.c = quadra.ox * quadra.ox + quadra.oz * quadra.oz - \
	o->pocylinder.radius * o->pocylinder.radius;
	quadra.disc = quadra.b * quadra.b - 4.0 * quadra.a * quadra.c;
	vector3deq(&quadra.r.d, ray.d);
	point3deq(&quadra.r.o, ray.o);
	if (quadra.disc < 0)
		return (0);
	else
		return (quadrasolutioncs(quadra, &o->pocylinder, tmin));
	return (0);
}
