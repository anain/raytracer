/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opencylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 18:03:09 by asavann           #+#    #+#             */
/*   Updated: 2018/04/22 18:01:54 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opencylinder.h"
#include <math.h>
#include <stdio.h>

void	opencylinder_init(t_opencylinder *c, const double r, \
			const double bottom, const double top)
{
	c->radius = r;
	c->invradius = 1.0 / r;
	c->y0 = bottom;
	c->y1 = top;
	c->kepsilon = 0.00001;
}

int		quadrasolutioncy(\
	t_quadrac q, const t_opencylinder *c, double *tmin, t_shaderec *sr)
{
	double		t;
	double		t1;
	double		t2;

	q.e = sqrt(q.disc);
	q.denom = 2.0 * q.a;
	t1 = (-q.b - q.e) / q.denom;
	t2 = (-q.b + q.e) / q.denom;
	q.yhit = q.r.o.y + q.r.d.y * t1;
	t = (t1 > c->kepsilon && (q.yhit > c->y0 && q.yhit < c->y1)) ? t1 : t2;
	q.yhit = q.r.o.y + q.r.d.y * t;
	if (t > c->kepsilon && (q.yhit > c->y0 && q.yhit < c->y1))
	{
		*tmin = t;
		normalsetvalue(&sr->normal, (q.ox + t * q.dx) * c->invradius, 0.0, \
		(q.oz + t * q.dz) * c->invradius);
		if (normaldotproduct(&sr->normal, vector3dneg(&q.r.d)) < 0)
			sr->normal = normalneg(&sr->normal);
		sr->local_hit_point = addvector(&q.r.o, multvector3d(&q.r.d, *tmin));
		return (1);
	}
	return (0);
}

int		opencylinderhit(\
			const t_object *o, const t_ray ray, double *tmin, t_shaderec *sr)
{
	t_quadrac quadra;

	quadra.ox = ray.o.x;
	quadra.oz = ray.o.z;
	quadra.dx = ray.d.x;
	quadra.dz = ray.d.z;
	quadra.a = quadra.dx * quadra.dx + quadra.dz * quadra.dz;
	quadra.b = 2.0 * (quadra.ox * quadra.dx + quadra.oz * quadra.dz);
	quadra.c = quadra.ox * quadra.ox + quadra.oz * quadra.oz - \
	o->ocylinder.radius * o->ocylinder.radius;
	quadra.disc = quadra.b * quadra.b - 4.0 * quadra.a * quadra.c;
	vector3deq(&quadra.r.d, ray.d);
	point3deq(&quadra.r.o, ray.o);
	if (quadra.disc < 0)
		return (0);
	else
		return (quadrasolutioncy(quadra, &o->ocylinder, tmin, sr));
	return (0);
}

int		quadrasolutioncsy(\
	t_quadrac q, const t_opencylinder *c, float *tmin)
{
	double		t;

	q.e = sqrt(q.disc);
	q.denom = 2.0 * q.a;
	t = (-q.b - q.e) / q.denom;
	q.yhit = q.r.o.y + q.r.d.y * t;
	if (t > c->kepsilon && (q.yhit >= c->y0 && q.yhit <= c->y1))
	{
		*tmin = t;
		return (1);
	}
	t = (-q.b + q.e) / q.denom;
	q.yhit = q.r.o.y + q.r.d.y * t;
	if (t > c->kepsilon && (q.yhit >= c->y0 && q.yhit <= c->y1))
	{
		*tmin = t;
		return (1);
	}
	return (0);
}

int		opencylinderhitshadow(\
			const t_object *o, const t_ray ray, float *tmin)
{
	t_quadrac quadra;

	quadra.ox = ray.o.x;
	quadra.oz = ray.o.z;
	quadra.dx = ray.d.x;
	quadra.dz = ray.d.z;
	quadra.a = quadra.dx * quadra.dx + quadra.dz * quadra.dz;
	quadra.b = 2.0 * (quadra.ox * quadra.dx + quadra.oz * quadra.dz);
	quadra.c = quadra.ox * quadra.ox + quadra.oz * quadra.oz - \
	o->ocylinder.radius * o->ocylinder.radius;
	quadra.disc = quadra.b * quadra.b - 4.0 * quadra.a * quadra.c;
	vector3deq(&quadra.r.d, ray.d);
	point3deq(&quadra.r.o, ray.o);
	if (quadra.disc < 0)
		return (0);
	else
		return (quadrasolutioncsy(quadra, &o->ocylinder, tmin));
	return (0);
}
