/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boxes2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <anain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 19:07:27 by anain             #+#    #+#             */
/*   Updated: 2018/04/22 22:17:25 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "box.h"

t_normal	get_normal(int a)
{
	if (a == 0)
		return ((t_normal){-1, 0, 0});
	else if (a == 1)
		return ((t_normal){0, -1, 0});
	else if (a == 2)
		return ((t_normal){0, 0, -1});
	else if (a == 3)
		return ((t_normal){1, 0, 0});
	else if (a == 4)
		return ((t_normal){0, 1, 0});
	else if (a == 5)
		return ((t_normal){0, 0, 1});
	else
		ft_error("Undefined error");
	return ((t_normal){-1, 0, 0});
}

int			boxhitshadow(const t_object *o, const t_ray ray, float *tmin)
{
	t_tminmax	t;
	t_point3d	param;
	double		t0;
	double		t1;

	if (tmin)
		init_val(&t, &o->box, &param, ray);
	t0 = (t.min.x > t.min.y) ? t.min.x : t.min.y;
	if (t.min.z > t0)
		t0 = t.min.z;
	t1 = (t.max.x < t.max.y) ? t.max.x : t.max.y;
	if (t.max.z < t1)
		t1 = t.max.z;
	if (t0 < t1 && t1 > o->box.kepsilon)
	{
		if (t0 > o->box.kepsilon)
			*tmin = t0;
		else
			*tmin = t1;
		return (1);
	}
	else
		return (0);
}

void		find_largest_t(t_tminmax *t, t_point3d *param, t_inter *inter, \
			t_face *face)
{
	if (t->min.x > t->min.y)
	{
		inter->in = t->min.x;
		face->in = (param->x >= 0.0) ? 0 : 3;
	}
	else
	{
		inter->in = t->min.y;
		face->in = (param->y >= 0.0) ? 1 : 4;
	}
	if (t->min.z > inter->in)
	{
		inter->in = t->min.z;
		face->in = (param->z >= 0.0) ? 2 : 5;
	}
}

void		find_smallest_t(t_tminmax *t, t_point3d *param, t_inter *inter, \
			t_face *face)
{
	if (t->max.x < t->max.y)
	{
		inter->out = t->max.x;
		face->out = (param->x >= 0) ? 3 : 0;
	}
	else
	{
		inter->out = t->max.y;
		face->out = (param->y >= 0.0) ? 4 : 1;
	}
	if (t->max.z < inter->out)
	{
		inter->out = t->max.z;
		face->out = (param->z >= 0.0) ? 5 : 2;
	}
}

int			boxhit(const t_object *o, const t_ray ray, double *tmin, \
			t_shaderec *sr)
{
	t_tminmax		t;
	t_point3d		param;
	t_inter			inter;
	t_face			face;

	init_val(&t, &o->box, &param, ray);
	find_largest_t(&t, &param, &inter, &face);
	find_smallest_t(&t, &param, &inter, &face);
	if (inter.in < inter.out && inter.out > o->box.kepsilon)
	{
		if (inter.in > o->box.kepsilon)
		{
			*tmin = inter.in;
			sr->normal = get_normal(face.in);
		}
		else
		{
			*tmin = inter.out;
			sr->normal = get_normal(face.out);
		}
		sr->local_hit_point = addvector(&ray.o, multvector3d(&ray.d, *tmin));
		return (1);
	}
	return (0);
}
