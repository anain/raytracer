/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambientoccluder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:40:05 by asavann           #+#    #+#             */
/*   Updated: 2018/04/24 17:04:55 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ambientoccluder.h"
#include "world.h"
#include <stdlib.h>
#include <stdio.h>

void				set_samplerao(t_ambientoccluder *ao, const int ns)
{
	ao->sampler.num_samples = ns;
	ao->sampler.num_sets = 83;
	ao->sampler.count = 0;
	ao->sampler.jump = 0;
	if (!(ao->sampler.samples =\
	(t_point2d*)malloc(sizeof(t_point2d) * ns * 83)))
		exit(EXIT_FAILURE);
	generate_multijittered_samples(&ao->sampler);
	setup_shuffled_indices(&ao->sampler);
	map_samples_to_hemisphere(&ao->sampler, 1);
	free(ao->sampler.samples);
}

static t_vector3d	get_directionao(t_ambientoccluder *ao)
{
	t_point3d	sp;
	t_vector3d	d;

	point3dcpy(&sp, sample_unit_hemishpere(&ao->sampler));
	d.x = sp.x * ao->u.x + sp.y * ao->v.x + sp.z * ao->w.x;
	d.y = sp.x * ao->u.y + sp.y * ao->v.y + sp.z * ao->w.y;
	d.z = sp.x * ao->u.z + sp.y * ao->v.z + sp.z * ao->w.z;
	return (d);
}

static int			in_shadowao(const t_ray ray, const t_shaderec *sr)
{
	float		t;
	t_object	*tmp;

	tmp = sr->w->begin;
	while (tmp != NULL)
	{
		if (tmp->shadow == 1 && tmp->shadow_hit(tmp, ray, &t))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

t_rgbcolor			lao(t_world *w, t_shaderec *sr)
{
	t_ray		shadow_ray;
	t_rgbcolor	pixel;

	w->ao.w = vector3deqn(&w->ao.w, sr->normal);
	w->ao.v = crossproduct(&w->ao.w, (t_vector3d){0.0072, 1.0, 0.0034});
	normalize(&w->ao.v);
	w->ao.u = crossproduct(&w->ao.v, w->ao.w);
	raysetvalue(&shadow_ray, sr->hit_point, get_directionao(&w->ao));
	pixel = rgbmult(&w->ao.c, w->ao.ls);
	if (in_shadowao(shadow_ray, sr) == 1)
		return (rgbmult(&pixel, w->ao.min_amount));
	return (pixel);
}
