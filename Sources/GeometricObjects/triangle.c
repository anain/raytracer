/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorobin <jorobin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:09:16 by jorobin           #+#    #+#             */
/*   Updated: 2018/04/22 18:00:02 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "triangle.h"
#include "geometricobjects.h"
#include "../../libft/libft.h"
#include <stdio.h>

t_triangle	*set_triangle_normal(t_triangle *t)
{
	t_vector3d tmp;

	tmp = getvector(&t->v1, t->v0);
	normaleqv(&t->normal, crossproduct(&tmp, getvector(&t->v2, t->v0)));
	normalizen(&t->normal);
	return (t);
}

void		set_var(t_trivar *tr, const t_object *o, const t_ray *ray)
{
	tr->a = o->triangle.v0.x - o->triangle.v1.x;
	tr->b = o->triangle.v0.x - o->triangle.v2.x;
	tr->c = ray->d.x;
	tr->d = o->triangle.v0.x - ray->o.x;
	tr->e = o->triangle.v0.y - o->triangle.v1.y;
	tr->f = o->triangle.v0.y - o->triangle.v2.y;
	tr->g = ray->d.y;
	tr->h = o->triangle.v0.y - ray->o.y;
	tr->i = o->triangle.v0.z - o->triangle.v1.z;
	tr->j = o->triangle.v0.z - o->triangle.v2.z;
	tr->k = ray->d.z;
	tr->l = o->triangle.v0.z - ray->o.z;
	tr->m = tr->f * tr->k - tr->g * tr->j;
	tr->n = tr->h * tr->k - tr->g * tr->l;
	tr->p = tr->f * tr->l - tr->h * tr->j;
	tr->q = tr->g * tr->i - tr->e * tr->k;
	tr->s = tr->e * tr->j - tr->f * tr->i;
	tr->inv_denom = 1.0 / (tr->a * tr->m + tr->b * tr->q + tr->c * tr->s);
	tr->e1 = tr->d * tr->m - tr->b * tr->n - tr->c * tr->p;
	tr->beta = tr->e1 * tr->inv_denom;
}

int			trianglehitshadow(const t_object *o, const t_ray ray, float *tmin)
{
	double		t;
	t_trivar	tr;

	tr.kepsilon = 0.00001;
	set_var(&tr, o, &ray);
	if (tr.beta < 0.0)
		return (0);
	tr.r = tr.e * tr.l - tr.h * tr.i;
	tr.e2 = tr.a * tr.n + tr.d * tr.q + tr.c * tr.r;
	tr.gamma = tr.e2 * tr.inv_denom;
	if (tr.gamma < 0.0)
		return (0);
	if (tr.beta + tr.gamma > 1.0)
		return (0);
	tr.e3 = tr.a * tr.p - tr.b *\
					tr.r + tr.d * tr.s;
	t = tr.e3 * tr.inv_denom;
	if (t < tr.kepsilon)
		return (0);
	*tmin = t;
	return (1);
}

int			trianglehit(const t_object *o, const t_ray ray, \
				double *tmin, t_shaderec *sr)
{
	double			t;
	t_trivar		tr;

	tr.kepsilon = 0.00001;
	set_var(&tr, o, &ray);
	if (tr.beta < 0.0)
		return (0);
	tr.r = tr.e * tr.l - tr.h * tr.i;
	tr.e2 = tr.a * tr.n + tr.d * tr.q + tr.c * tr.r;
	tr.gamma = tr.e2 * tr.inv_denom;
	if (tr.gamma < 0.0)
		return (0);
	if (tr.beta + tr.gamma > 1.0)
		return (0);
	tr.e3 = tr.a * tr.p - tr.b *\
					tr.r + tr.d * tr.s;
	t = tr.e3 * tr.inv_denom;
	if (t < tr.kepsilon)
		return (0);
	*tmin = t;
	sr->normal = o->triangle.normal;
	sr->local_hit_point = addvector(&ray.o, multvector3d(&ray.d, t));
	return (1);
}
