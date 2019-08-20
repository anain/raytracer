/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 19:25:29 by asavann           #+#    #+#             */
/*   Updated: 2018/04/22 15:36:49 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phong.h"
#include "world.h"
#include "ambient.h"
#include "reflective.h"
#include "ambientoccluder.h"
#include <stdio.h>
#include "noise.h"

static void			phongcolor(t_matparam *pp, t_light *current, \
						t_material *m, t_shaderec *sr)
{
	pp->c = lambf(&m->phong.diffuse_brdf);
	pp->c = rgbadd(&pp->c, glossyf(&m->phong.specular_brdf, \
		*sr, pp->wo, pp->wi));
	pp->c = rgbmultrgb(&pp->c, current->l(current, sr));
	pp->c = rgbmult(&pp->c, current->g(current, sr));
	pp->c = rgbmult(&pp->c, pp->ndotwi);
	pp->c = rgbdiv(&pp->c, current->pdf(current, sr));
	pp->l = rgbadd(&pp->l, pp->c);
}

static void			prepare_color(t_material *m, t_shaderec *sr, \
						t_matparam *pp)
{
	pp->wo = vector3dneg(&sr->ray.d);
	sr->saved_color = m->phong.ambient_brdf.cd;
	m->phong.ambient_brdf.cd = m->mapping(sr);
	m->phong.diffuse_brdf.cd = m->phong.ambient_brdf.cd;
	pp->c = lambrho(&m->phong.ambient_brdf);
	pp->l = rgbmultrgb(&pp->c, sr->w->ambient(sr->w, sr));
}

t_rgbcolor			shadephong(t_material *m, t_shaderec *sr)
{
	t_matparam		pp;
	int				in_shadow;
	t_light			*current;

	prepare_color(m, sr, &pp);
	current = sr->w->light;
	while (current != NULL)
	{
		pp.wi = current->get_direction(current, sr);
		pp.ndotwi = normaldotproduct(&sr->normal, pp.wi);
		if (pp.ndotwi > 0.0)
		{
			in_shadow = 0;
			if (current->shadow)
			{
				raysetvalue(&pp.ray, sr->hit_point, pp.wi);
				in_shadow = current->in_shadow(current, pp.ray, *sr);
			}
			if (!in_shadow)
				phongcolor(&pp, current, m, sr);
		}
		current = current->next;
	}
	reset_color(m, sr);
	return (pp.l);
}

t_rgbcolor			pathphong(t_material *m, t_shaderec *sr)
{
	t_matparam		pp;
	t_rgbcolor		fr;
	float			pdf;
	float			u;

	sr->saved_color = m->phong.ambient_brdf.cd;
	m->phong.ambient_brdf.cd = m->mapping(sr);
	m->phong.diffuse_brdf.cd = m->phong.ambient_brdf.cd;
	u = rand_float();
	vector3dcopy(&pp.wo, vector3dneg(&sr->ray.d));
	if (u < m->phong.diffuse_brdf.kd)
		fr = lambfps(&m->phong.diffuse_brdf, sr, &pp.wi, &pdf);
	else
		fr = glossyfps(&m->phong.specular_brdf, sr, &pp, &pdf);
	raysetvalue(&pp.ray, sr->hit_point, pp.wi);
	fr = rgbmult(&fr, normaldotproduct(&sr->normal, pp.wi) / pdf);
	m->phong.ambient_brdf.cd = sr->saved_color;
	m->phong.diffuse_brdf.cd = sr->saved_color;
	return (rgbmultrgb(&fr, path_trace(&sr->w->tracer, \
		pp.ray, sr->depth + 1)));
}
