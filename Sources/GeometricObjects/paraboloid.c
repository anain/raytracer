/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paraboloid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 15:46:03 by majulien          #+#    #+#             */
/*   Updated: 2018/04/22 18:02:20 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "paraboloid.h"
#include <math.h>
#include "constants.h"
#include <stdlib.h>
#include <stdio.h>

int				quadsolution(\
	t_quad q, const t_paraboloid *paraboloid, double *tmin, t_shaderec *sr)
{
	double			t[3];
	t_vector3d		n;
	double			n2;
	t_vector3d		tmp2;

	q.e = sqrt(q.disc);
	q.denom = 2.0 * q.a;
	t[1] = (-q.b - q.e) / q.denom;
	t[2] = (-q.b + q.e) / q.denom;
	t[0] = (t[1] > paraboloid->kepsilon) ? t[1] : t[2];
	if (t[0] > paraboloid->kepsilon)
	{
		*tmin = t[0];
		tmp2 = subvector3d(&q.tmp, multvector3d(&q.r.d, t[0]));
		n = subvector3d(&tmp2, multvector3d(&paraboloid->v, \
			(dotproduct(&tmp2, paraboloid->v) + paraboloid->k)));
		n2 = sqrt(dotproduct(&n, n));
		normaleqv(&sr->normal, divvector3d(&n, n2));
		sr->local_hit_point = addvector(&q.r.o, multvector3d(&q.r.d, t[0]));
		return (1);
	}
	return (0);
}

void			paraboloidinit(t_paraboloid *paraboloid)
{
	paraboloid->kepsilon = 0.00001;
}

int				paraboloidhit(const t_object *o, const t_ray ray, double *tmin,\
		t_shaderec *sr)
{
	t_quad			quad;

	quad.tmp = getvector(&ray.o, o->paraboloid.c);
	quad.a = dotproduct(&ray.d, ray.d) - dotproduct(&ray.d, o->paraboloid.v)\
	* dotproduct(&ray.d, o->paraboloid.v);
	quad.b = (dotproduct(&ray.d, quad.tmp) - \
	dotproduct(&ray.d, o->paraboloid.v) * \
	(dotproduct(&quad.tmp, o->paraboloid.v) + 2 * o->paraboloid.k)) * 2;
	quad.c = dotproduct(&quad.tmp, quad.tmp) - \
	dotproduct(&quad.tmp, o->paraboloid.v) * \
	(dotproduct(&quad.tmp, o->paraboloid.v) + 4 * o->paraboloid.k);
	quad.disc = quad.b * quad.b - 4.0 * quad.a * quad.c;
	vector3deq(&quad.r.d, ray.d);
	point3deq(&quad.r.o, ray.o);
	if (quad.disc < 0)
		return (0);
	else
		return (quadsolution(quad, &o->paraboloid, tmin, sr));
	return (0);
}

int				quadsolutionshadow(\
	t_quad q, const t_paraboloid *paraboloid, float *tmin)
{
	double			t;
	double			t1;
	double			t2;

	q.e = sqrt(q.disc);
	q.denom = 2.0 * q.a;
	t1 = (-q.b - q.e) / q.denom;
	t2 = (-q.b + q.e) / q.denom;
	t = (t1 > paraboloid->kepsilon) ? t1 : t2;
	if (t > paraboloid->kepsilon)
	{
		*tmin = t;
		return (1);
	}
	return (0);
}

int				paraboloidhitshadow(const t_object *o, const t_ray ray,\
		float *tmin)
{
	t_quad				quad;

	quad.tmp = getvector(&ray.o, o->paraboloid.c);
	quad.a = dotproduct(&ray.d, ray.d) - dotproduct(&ray.d, o->paraboloid.v)\
	* dotproduct(&ray.d, o->paraboloid.v);
	quad.b = (dotproduct(&ray.d, quad.tmp) - \
	dotproduct(&ray.d, o->paraboloid.v) * \
	(dotproduct(&quad.tmp, o->paraboloid.v) + 2 * o->paraboloid.k)) * 2;
	quad.c = dotproduct(&quad.tmp, quad.tmp) - \
	dotproduct(&quad.tmp, o->paraboloid.v) * \
	(dotproduct(&quad.tmp, o->paraboloid.v) + 4 * o->paraboloid.k);
	quad.disc = quad.b * quad.b - 4.0 * quad.a * quad.c;
	vector3deq(&quad.r.d, ray.d);
	point3deq(&quad.r.o, ray.o);
	if (quad.disc < 0)
		return (0);
	else
		return (quadsolutionshadow(quad, &o->paraboloid, tmin));
	return (0);
}
