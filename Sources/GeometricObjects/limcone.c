/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limcone.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 19:54:16 by asavann           #+#    #+#             */
/*   Updated: 2018/04/23 23:01:29 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "limcone.h"
#include "opencylinder.h"
#include <stdio.h>
#include <math.h>

static void	get_valuec(t_quadrac q, const t_limcone *c,\
		double t, t_shaderec *sr)
{
	normalsetvalue(&sr->normal, c->h * c->invradius * (q.ox + t * q.dx), \
	c->h - q.oy - t * q.dy, c->h * c->invradius * (q.oz + t * q.dz));
	normalizen(&sr->normal);
	if (normaldotproduct(&sr->normal, vector3dneg(&q.r.d)) < 0)
		sr->normal = normalneg(&sr->normal);
	sr->local_hit_point = addvector(&q.r.o, multvector3d(&q.r.d, t));
}

static int	quadrasolutionlic(t_quadrac q, const t_limcone *c, double *tmin,\
		t_shaderec *sr)
{
	double	t;
	double	t1;
	double	t2;

	q.e = sqrt(q.disc);
	q.denom = 2.0 * q.a;
	t1 = (-q.b - q.e) / q.denom;
	q.yhit = q.r.o.y + q.r.d.y * t1;
	t2 = (-q.b + q.e) / q.denom;
	t = t2;
	if (t1 > c->kepsilon && (q.yhit > c->y0 && q.yhit < c->y1))
	{
		t = t1;
		q.yhit = q.r.o.y + q.r.d.y * t2;
		if (t2 < t1 && t2 > c->kepsilon && (q.yhit > c->y0 && q.yhit < c->y1))
			t = t2;
	}
	q.yhit = q.r.o.y + q.r.d.y * t;
	if (t > c->kepsilon && (q.yhit > c->y0 && q.yhit < c->y1))
	{
		*tmin = t;
		get_valuec(q, c, t, sr);
		return (1);
	}
	return (0);
}

int			limconehit(\
		const t_object *o, const t_ray ray, double *tmin, t_shaderec *sr)
{
	t_quadrac	q;

	q.ox = ray.o.x;
	q.oy = ray.o.y;
	q.oz = ray.o.z;
	q.dx = ray.d.x;
	q.dy = ray.d.y;
	q.dz = ray.d.z;
	q.a = (o->lcone.h * o->lcone.h * o->lcone.invradius * o->lcone.invradius) \
	* (q.dx * q.dx + q.dz * q.dz) - q.dy * q.dy;
	q.b = 2 * \
	((o->lcone.h * o->lcone.h * o->lcone.invradius * o->lcone.invradius) \
	* (q.dx * q.ox + q.dz * q.oz) + q.dy * (o->lcone.h - q.oy));
	q.c = (o->lcone.h * o->lcone.h * o->lcone.invradius * o->lcone.invradius) \
	* (q.ox * q.ox + q.oz * q.oz) + q.oy * (2 * o->lcone.h - q.oy) - \
	o->lcone.h * o->lcone.h;
	q.disc = q.b * q.b - 4.0 * q.a * q.c;
	q.r.d = vector3deq(&q.r.d, ray.d);
	q.r.o = point3deq(&q.r.o, ray.o);
	if (q.disc < 0)
		return (0);
	else
		return (quadrasolutionlic(q, &o->lcone, tmin, sr));
}

static int	quadrasolutionlics(t_quadrac q, const t_limcone *c, float *tmin)
{
	float	t;
	float	t1;
	float	t2;

	q.e = sqrt(q.disc);
	q.denom = 2.0 * q.a;
	t1 = (-q.b - q.e) / q.denom;
	t2 = (-q.b + q.e) / q.denom;
	q.yhit = q.r.o.y + q.r.d.y * t1;
	t = t2;
	if (t1 > c->kepsilon && (q.yhit > c->y0 && q.yhit < c->y1))
	{
		t = t1;
		q.yhit = q.r.o.y + q.r.d.y * t2;
		if (t2 < t1 && t2 > c->kepsilon && (q.yhit > c->y0 && q.yhit < c->y1))
			t = t2;
	}
	q.yhit = q.r.o.y + q.r.d.y * t;
	if (t > c->kepsilon && (q.yhit >= c->y0 && q.yhit <= c->y1))
	{
		*tmin = t;
		return (1);
	}
	return (0);
}

int			limconehitshadow(\
		const t_object *o, const t_ray ray, float *tmin)
{
	t_quadrac	q;

	q.ox = ray.o.x;
	q.oy = ray.o.y;
	q.oz = ray.o.z;
	q.dx = ray.d.x;
	q.dy = ray.d.y;
	q.dz = ray.d.z;
	q.a = (o->lcone.h * o->lcone.h * o->lcone.invradius * o->lcone.invradius) \
	* (q.dx * q.dx + q.dz * q.dz) - q.dy * q.dy;
	q.b = 2 * \
	((o->lcone.h * o->lcone.h * o->lcone.invradius * o->lcone.invradius) \
	* (q.dx * q.ox + q.dz * q.oz) + q.dy * (o->lcone.h - q.oy));
	q.c = (o->lcone.h * o->lcone.h * o->lcone.invradius * \
	o->lcone.invradius) * (q.ox * q.ox + q.oz * q.oz) + q.oy *\
	(2 * o->lcone.h - q.oy) - o->lcone.h * o->lcone.h;
	q.disc = q.b * q.b - 4.0 * q.a * q.c;
	vector3deq(&q.r.d, ray.d);
	point3deq(&q.r.o, ray.o);
	if (q.disc < 0)
		return (0);
	else
		return (quadrasolutionlics(q, &o->lcone, tmin));
}
