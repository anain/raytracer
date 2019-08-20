/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matte.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 19:12:04 by asavann           #+#    #+#             */
/*   Updated: 2018/04/22 14:35:28 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matte.h"
#include "world.h"
#include "../Minilibx/mmlx.h"
#include "ambient.h"
#include "ambientoccluder.h"
#include "vector3d.h"
#include <stdio.h>

static void			mattecolor(t_matparam *mp, t_light *current, \
						t_material *m, t_shaderec *sr)
{
	mp->c = lambf(&m->matte.diffuse_brdf);
	mp->c = rgbmultrgb(&mp->c, current->l(current, sr));
	mp->c = rgbmult(&mp->c, current->g(current, sr));
	mp->c = rgbmult(&mp->c, mp->ndotwi);
	mp->c = rgbdiv(&mp->c, current->pdf(current, sr));
	mp->l = rgbaddc(&mp->l, mp->c);
}

void				reset_color(t_material *m, t_shaderec *sr)
{
	m->matte.ambient_brdf.cd = sr->saved_color;
	m->matte.diffuse_brdf.cd = sr->saved_color;
}

static void			prepare_color(t_material *m, t_shaderec *sr, \
						t_matparam *mp)
{
	sr->saved_color = m->matte.ambient_brdf.cd;
	m->matte.ambient_brdf.cd = m->mapping(sr);
	m->matte.diffuse_brdf.cd = m->matte.ambient_brdf.cd;
	mp->c = lambrho(&m->matte.ambient_brdf);
	mp->l = rgbmultrgb(&mp->c, sr->w->ambient(sr->w, sr));
}

t_rgbcolor			shadematte(t_material *m, t_shaderec *sr)
{
	t_matparam		mp;
	t_light			*current;
	int				in_shadow;

	prepare_color(m, sr, &mp);
	current = sr->w->light;
	while (current != NULL)
	{
		mp.wi = current->get_direction(current, sr);
		mp.ndotwi = normaldotproduct(&sr->normal, mp.wi);
		if (mp.ndotwi > 0.0)
		{
			in_shadow = 0;
			if (current->shadow)
			{
				raysetvalue(&mp.ray, sr->hit_point, mp.wi);
				in_shadow = current->in_shadow(current, mp.ray, *sr);
			}
			if (!in_shadow)
				mattecolor(&mp, current, m, sr);
		}
		current = current->next;
	}
	reset_color(m, sr);
	return (mp.l);
}

t_rgbcolor			pathshadematte(t_material *m, t_shaderec *sr)
{
	t_matparam		mp;
	t_vector3d		wi;
	float			pdf;
	t_rgbcolor		f;

	sr->saved_color = m->matte.ambient_brdf.cd;
	m->matte.ambient_brdf.cd = m->mapping(sr);
	m->matte.diffuse_brdf.cd = m->matte.ambient_brdf.cd;
	mp.wo = vector3dneg(&sr->ray.d);
	f = lambfps(&m->matte.diffuse_brdf, sr, &wi, &pdf);
	mp.ndotwi = normaldotproduct(&sr->normal, wi);
	raysetvalue(&mp.ray, sr->hit_point, wi);
	f = rgbmult(&f, mp.ndotwi / pdf);
	m->matte.ambient_brdf.cd = sr->saved_color;
	m->matte.diffuse_brdf.cd = sr->saved_color;
	return (rgbmultrgb(&f, path_trace(&sr->w->tracer, mp.ray, sr->depth + 1)));
}
