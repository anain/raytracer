/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infcone.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 15:36:00 by asavann           #+#    #+#             */
/*   Updated: 2018/04/23 22:44:42 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infcone.h"
#include "opencylinder.h"
#include <stdio.h>
#include <math.h>

void	infcone_init(t_infcone *c, const double r, const double height)
{
	c->radius = r;
	c->invradius = 1 / r;
	c->h = height;
	c->kepsilon = 0.000001;
}

int		quadrasolutionic(t_quadrac q, const t_infcone *c, double *tmin,\
		t_shaderec *sr)
{
	double	t;
	double	t1;
	double	t2;

	q.e = sqrt(q.disc);
	q.denom = 2.0 * q.a;
	t1 = (-q.b - q.e) / q.denom;
	t2 = (-q.b + q.e) / q.denom;
	t = t2;
	if (t1 > c->kepsilon)
	{
		t = t1;
		if (t2 < t1 && t2 > c->kepsilon)
			t = t2;
	}
	if (t > c->kepsilon)
	{
		*tmin = t;
		normalsetvalue(&sr->normal, c->h * c->invradius * (q.ox + t * q.dx), \
		c->h - q.oy - t * q.dy, c->h * c->invradius * (q.oz + t * q.dz));
		normalizen(&sr->normal);
		sr->local_hit_point = addvector(&q.r.o, multvector3d(&q.r.d, *tmin));
		return (1);
	}
	return (0);
}

int		infconehit(\
		const t_object *o, const t_ray ray, double *tmin, t_shaderec *sr)
{
	t_quadrac	q;

	q.ox = ray.o.x;
	q.oy = ray.o.y;
	q.oz = ray.o.z;
	q.dx = ray.d.x;
	q.dy = ray.d.y;
	q.dz = ray.d.z;
	q.a = (o->icone.h * o->icone.h * o->icone.invradius * o->icone.invradius) \
	* (q.dx * q.dx + q.dz * q.dz) - q.dy * q.dy;
	q.b = 2 * \
	((o->icone.h * o->icone.h * o->icone.invradius * o->icone.invradius) \
	* (q.dx * q.ox + q.dz * q.oz) + q.dy * (o->icone.h - q.oy));
	q.c = (o->icone.h * o->icone.h * o->icone.invradius * o->icone.invradius) \
	* (q.ox * q.ox + q.oz * q.oz) + q.oy * (2 * o->icone.h - q.oy) - \
	o->icone.h * o->icone.h;
	q.disc = q.b * q.b - 4.0 * q.a * q.c;
	q.r.d = vector3deq(&q.r.d, ray.d);
	q.r.o = point3deq(&q.r.o, ray.o);
	if (q.disc < 0)
		return (0);
	else
		return (quadrasolutionic(q, &o->icone, tmin, sr));
}

int		quadrasolutionics(t_quadrac q, const t_infcone *c, float *tmin)
{
	float	t;
	float	t1;
	float	t2;

	q.e = sqrt(q.disc);
	q.denom = 2.0 * q.a;
	t1 = (-q.b - q.e) / q.denom;
	t2 = (-q.b + q.e) / q.denom;
	t = t2;
	if (t1 > c->kepsilon)
	{
		t = t1;
		if (t2 < t1 && t2 > c->kepsilon)
			t = t2;
	}
	if (t > c->kepsilon)
	{
		*tmin = t;
		return (1);
	}
	return (0);
}

int		infconehitshadow(\
		const t_object *o, const t_ray ray, float *tmin)
{
	t_quadrac	q;

	q.ox = ray.o.x;
	q.oy = ray.o.y;
	q.oz = ray.o.z;
	q.dx = ray.d.x;
	q.dy = ray.d.y;
	q.dz = ray.d.z;
	q.a = (o->icone.h * o->icone.h * o->icone.invradius * o->icone.invradius) \
	* (q.dx * q.dx + q.dz * q.dz) - q.dy * q.dy;
	q.b = 2 * \
	((o->icone.h * o->icone.h * o->icone.invradius * o->icone.invradius) \
	* (q.dx * q.ox + q.dz * q.oz) + q.dy * (o->icone.h - q.oy));
	q.c = (o->icone.h * o->icone.h * o->icone.invradius * o->icone.invradius) \
	* (q.ox * q.ox + q.oz * q.oz) + q.oy * (2 * o->icone.h - q.oy) - \
	o->icone.h * o->icone.h;
	q.disc = q.b * q.b - 4.0 * q.a * q.c;
	vector3deq(&q.r.d, ray.d);
	point3deq(&q.r.o, ray.o);
	if (q.disc < 0)
		return (0);
	else
		return (quadrasolutionics(q, &o->icone, tmin));
}
