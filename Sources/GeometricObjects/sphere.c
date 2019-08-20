/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 20:02:29 by asavann           #+#    #+#             */
/*   Updated: 2018/04/24 17:05:34 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"
#include "libft.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

static int	quadrasolution(\
	t_quadra q, const t_sphere *sphere, double *tmin, t_shaderec *sr)
{
	double		t;
	t_vector3d	tmp2;

	q.e = sqrt(q.disc);
	q.denom = 2.0 * q.a;
	t = (-q.b - q.e) / q.denom;
	if (t > sphere->kepsilon)
	{
		*tmin = t;
		tmp2 = addvector3d(&q.tmp, multvector3d(&q.r.d, t));
		normaleqv(&sr->normal, divvector3d(&tmp2, sphere->radius));
		sr->local_hit_point = addvector(&q.r.o, multvector3d(&q.r.d, t));
		return (1);
	}
	t = (-q.b + q.e) / q.denom;
	if (t > sphere->kepsilon)
	{
		*tmin = t;
		tmp2 = addvector3d(&q.tmp, multvector3d(&q.r.d, t));
		normaleqv(&sr->normal, divvector3d(&tmp2, sphere->radius));
		sr->local_hit_point = addvector(&q.r.o, multvector3d(&q.r.d, t));
		return (1);
	}
	return (0);
}

int			spherehit(\
	const t_object *o, const t_ray ray, double *tmin, t_shaderec *sr)
{
	t_quadra	quadra;

	quadra.tmp = getvector(&ray.o, o->sphere.center);
	quadra.a = dotproduct(&ray.d, ray.d);
	quadra.b = dotproduct(&ray.d, quadra.tmp) * 2;
	quadra.c =
	dotproduct(&quadra.tmp, quadra.tmp) - o->sphere.radius * o->sphere.radius;
	quadra.disc = quadra.b * quadra.b - 4.0 * quadra.a * quadra.c;
	vector3deq(&quadra.r.d, ray.d);
	point3deq(&quadra.r.o, ray.o);
	if (quadra.disc < 0)
		return (0);
	else
		return (quadrasolution(quadra, &o->sphere, tmin, sr));
	return (0);
}

void		sphere_set_center(t_sphere *sphere,\
		const double x, const double y, const double z)
{
	sphere->center.x = x;
	sphere->center.y = y;
	sphere->center.z = z;
	sphere->kepsilon = 0.00001;
}

void		sphere_set_radius(t_sphere *sphere, const double r)
{
	sphere->radius = r;
}

void		sphere_set_sampler(t_sphere *sphere, int ns)
{
	sphere->sampler.num_samples = ns;
	sphere->sampler.num_sets = 83;
	sphere->sampler.count = 0;
	sphere->sampler.jump = 0;
	if (!(sphere->sampler.samples =\
	(t_point2d*)malloc(sizeof(t_point2d) * ns * 83)))
		exit(EXIT_FAILURE);
	generate_multijittered_samples(&sphere->sampler);
	setup_shuffled_indices(&sphere->sampler);
	map_sample_to_sphere(&sphere->sampler);
	free(sphere->sampler.samples);
}
