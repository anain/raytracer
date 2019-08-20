/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lambertian2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:29:04 by asavann           #+#    #+#             */
/*   Updated: 2018/04/24 17:01:48 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brdf.h"
#include "constants.h"
#include <stdio.h>
#include <stdlib.h>

t_rgbcolor	lambrho(t_lambertian *lamb)
{
	return (rgbmult(&lamb->cd, lamb->kd));
}

t_rgbcolor	lambfps(t_lambertian *lamb,\
	const t_shaderec *sr, t_vector3d *wi, float *pdf)
{
	t_vector3d	w;
	t_vector3d	v;
	t_vector3d	u;
	t_vector3d	tmp;
	t_point3d	sp;

	tmp = (t_vector3d){0.0034, 1.0, 0.0071};
	w = (t_vector3d){sr->normal.x, sr->normal.y, sr->normal.z};
	v = crossproduct(&tmp, w);
	normalize(&v);
	u = crossproduct(&v, w);
	sp = sample_unit_hemishpere(&lamb->sampler);
	wi->x = sp.x * u.x + sp.y * v.x + sp.z * w.x;
	wi->y = sp.x * u.y + sp.y * v.y + sp.z * w.y;
	wi->z = sp.x * u.z + sp.y * v.z + sp.z * w.z;
	normalize(wi);
	*pdf = normaldotproduct(&sr->normal, *wi) * INVPI;
	return (rgbmult(&lamb->cd, lamb->kd * INVPI));
}

void		set_samplerlamb(t_lambertian *l, const int ns)
{
	l->sampler.num_samples = ns;
	l->sampler.num_sets = 83;
	l->sampler.count = 0;
	l->sampler.jump = 0;
	if (!(l->sampler.samples = \
	(t_point2d*)malloc(sizeof(t_point2d) * ns * 83)))
		exit(EXIT_FAILURE);
	generate_multijittered_samples(&l->sampler);
	setup_shuffled_indices(&l->sampler);
	map_samples_to_hemisphere(&l->sampler, 1);
	free(l->sampler.samples);
}
