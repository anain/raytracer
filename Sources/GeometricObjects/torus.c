/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 16:06:45 by majulien          #+#    #+#             */
/*   Updated: 2018/04/24 17:38:09 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "torus.h"
#include <math.h>
#include "constants.h"
#include <stdlib.h>
#include <stdio.h>

void	rootszero(double roots[4])
{
	roots[0] = 0;
	roots[1] = 0;
	roots[2] = 0;
	roots[3] = 0;
}

void	rootsinit(const t_ray ray, const t_object *o,\
	double e[4], double coef[5])
{
	t_vector3d	oa;

	oa.x = ray.o.x;
	oa.y = ray.o.y;
	oa.z = ray.o.z;
	e[2] = dotproduct(&ray.d, ray.d);
	e[0] = dotproduct(&oa, oa) - (o->torus.a * o->torus.a) \
		- (o->torus.b * o->torus.b);
	e[1] = dotproduct(&ray.d, oa);
	e[3] = 4.0 * o->torus.a * o->torus.a;
	coef[0] = e[0] * e[0] - e[3] * \
		(o->torus.b * o->torus.b - oa.y * oa.y);
	coef[1] = 4.0 * e[1] * e[0] + \
		2.0 * e[3] * oa.y * ray.d.y;
	coef[2] = 2.0 * e[2] * e[0] + \
		4.0 * e[1] * e[1] + e[3] * ray.d.y * ray.d.y;
	coef[3] = 4.0 * e[2] * e[1];
	coef[4] = e[2] * e[2];
}

int		rootsval(double roots[4], const t_object *o, \
	int internum[2], double *t)
{
	int			j;

	j = 0;
	while (j < internum[1])
	{
		if (roots[j] > o->torus.kepsilon)
		{
			internum[0] = 1;
			if (roots[j] < *t)
				*t = roots[j];
		}
		j++;
	}
	return (internum[0] == 1 ? 1 : 0);
}

int		torushitshadow(const t_object *o, const t_ray ray,\
	float *tmin)
{
	int				internum[2];
	double			roots[4];
	double			coeffs[5];
	double			e[4];
	double			t;

	rootsinit(ray, o, e, coeffs);
	internum[1] = solvequartic(coeffs, roots);
	internum[0] = 0;
	t = KHUGEVALUE;
	if (internum[1] == 0)
		return (0);
	internum[0] = rootsval(roots, o, internum, &t);
	if (internum[0] == 0)
		return (0);
	*tmin = t;
	return (1);
}

int		torushit(const t_object *o, const t_ray ray, double *tmin, \
		t_shaderec *sr)
{
	int				internum[2];
	double			roots[4];
	double			coeffs[5];
	double			e[4];
	double			t;

	rootsinit(ray, o, e, coeffs);
	internum[1] = solvequartic(coeffs, roots);
	internum[0] = 0;
	t = KHUGEVALUE;
	if (internum[1] == 0)
		return (0);
	internum[0] = rootsval(roots, o, internum, &t);
	if (internum[0] == 0)
		return (0);
	*tmin = t;
	sr->local_hit_point = addvector(&ray.o, multvector3d(&ray.d, t));
	sr->normal = computenormal(sr->local_hit_point, o);
	return (1);
}
