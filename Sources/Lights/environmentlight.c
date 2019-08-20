/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environmentlight.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:16:43 by asavann           #+#    #+#             */
/*   Updated: 2018/04/24 17:05:03 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "environmentlight.h"
#include "world.h"
#include "constants.h"
#include <stdlib.h>
#include <pthread.h>

void			set_samplerel(t_environmentlight *el, const int ns)
{
	el->sampler.num_samples = ns;
	el->sampler.num_sets = 83;
	el->sampler.count = 0;
	el->sampler.jump = 0;
	if (!(el->sampler.samples =\
	(t_point2d*)malloc(sizeof(t_point2d) * ns * 83)))
		exit(EXIT_FAILURE);
	generate_multijittered_samples(&el->sampler);
	setup_shuffled_indices(&el->sampler);
	map_samples_to_hemisphere(&el->sampler, 1);
	free(el->sampler.samples);
}

t_vector3d		get_directionel(t_light *light, t_shaderec *sr)
{
	t_point3d		sp;
	t_vector3d		tmp;

	tmp = (t_vector3d){0.0034, 1, 0.0071};
	light->el.w = vector3deqn(&light->el.w, sr->normal);
	light->el.v = crossproduct(&tmp, light->el.w);
	normalize(&light->el.v);
	light->el.u = crossproduct(&light->el.v, light->el.w);
	sp = sample_unit_hemishpere(&light->el.sampler);
	light->el.wi.x = sp.x * light->el.u.x + sp.y * \
		light->el.v.x + sp.z * light->el.w.x;
	light->el.wi.y = sp.x * light->el.u.y + sp.y * \
		light->el.v.y + sp.z * light->el.w.y;
	light->el.wi.z = sp.x * light->el.u.z + sp.y * \
		light->el.v.z + sp.z * light->el.w.z;
	return (light->el.wi);
}

t_rgbcolor		lel(t_light *light, t_shaderec *sr)
{
	return (light->el.materialptr->get_le(light->el.materialptr, sr));
}

int				in_shadowel(\
			const t_light *light, const t_ray ray, const t_shaderec sr)
{
	float		t;
	t_object	*tmp;

	if (light)
		;
	tmp = sr.w->begin;
	while (tmp != NULL)
	{
		if (tmp->shadow == 1 && tmp->shadow_hit(tmp, ray, &t))
			return (1);
		tmp = tmp->next;
	}
	tmp = sr.w->begin;
	return (0);
}

float			pdfel(t_light *light, t_shaderec *sr)
{
	float ndotwi;

	ndotwi = normaldotproduct(&sr->normal, light->el.wi);
	return (ndotwi * INVPI);
}
