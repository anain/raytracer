/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 19:28:25 by asavann           #+#    #+#             */
/*   Updated: 2018/04/24 17:05:45 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rectangle.h"
#include "camera.h"
#include <stdio.h>
#include <stdlib.h>

int				rectanglehit(\
		const t_object *o, const t_ray ray, double *tmin, t_shaderec *sr)
{
	float		t;
	t_point3d	p;
	t_vector3d	d;
	float		ddota;
	float		ddotb;

	t = normaldotproduct(&o->rectangle.normal,\
		getvector(&o->rectangle.p0, ray.o)) /\
		normaldotproduct(&o->rectangle.normal, ray.d);
	if (t <= o->rectangle.kepsilon)
		return (0);
	p = addvector(&ray.o, multvector3d(&ray.d, t));
	d = getvector(&p, o->rectangle.p0);
	ddota = dotproduct(&d, o->rectangle.a);
	if (ddota < 0.0 || ddota > o->rectangle.len_squared_a)
		return (0);
	ddotb = dotproduct(&d, o->rectangle.b);
	if (ddotb < 0.0 || ddotb > o->rectangle.len_squared_b)
		return (0);
	*tmin = t;
	sr->normal = o->rectangle.normal;
	sr->local_hit_point = p;
	return (1);
}

int				rectanglehitshadow(const t_object *o, const t_ray ray, \
					float *tmin)
{
	float		t;
	t_point3d	p;
	t_vector3d	d;
	float		ddota;
	float		ddotb;

	t = normaldotproduct(&o->rectangle.normal,\
		getvector(&o->rectangle.p0, ray.o)) /\
		normaldotproduct(&o->rectangle.normal, ray.d);
	if (t <= o->rectangle.kepsilon)
		return (0);
	p = addvector(&ray.o, multvector3d(&ray.d, t));
	d = getvector(&p, o->rectangle.p0);
	ddota = dotproduct(&d, o->rectangle.a);
	if (ddota < 0.0 || ddota > o->rectangle.len_squared_a)
		return (0);
	ddotb = dotproduct(&d, o->rectangle.b);
	if (ddotb < 0.0 || ddotb > o->rectangle.len_squared_b)
		return (0);
	*tmin = t;
	return (1);
}

void			rect_set_sampler(t_rectangle *rectangle, int ns)
{
	rectangle->sampler.num_samples = ns;
	rectangle->sampler.num_sets = 83;
	rectangle->sampler.count = 0;
	rectangle->sampler.jump = 0;
	if (!(rectangle->sampler.samples =\
	(t_point2d*)malloc(sizeof(t_point2d) * ns * 83)))
		exit(EXIT_FAILURE);
	generate_multijittered_samples(&rectangle->sampler);
	setup_shuffled_indices(&rectangle->sampler);
}

t_point3d		rect_sample(t_object *o)
{
	t_point2d	sp;
	t_point3d	sp3d;

	sp = sample_unit_square(&o->rectangle.sampler);
	sp3d = addvector(&o->rectangle.p0, multvector3d(&o->rectangle.a, sp.x));
	sp3d = addvector(&sp3d, multvector3d(&o->rectangle.b, sp.y));
	return (sp3d);
}

t_normal		rect_get_normal(t_object *o, t_point3d *sp)
{
	if (sp)
		;
	return (o->rectangle.normal);
}
