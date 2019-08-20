/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mirror.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:29:21 by anain             #+#    #+#             */
/*   Updated: 2018/04/22 16:33:27 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reflective.h"
#include "transparence.h"

t_rgbcolor			reflective(t_material *m, t_shaderec *sr)
{
	t_vector3d		wi;
	t_vector3d		wo;
	t_rgbcolor		phong;
	t_rgbcolor		fr;
	t_ray			reflectedray;

	phong = shadephong(m, sr);
	vector3dcopy(&wo, vector3dneg(&sr->ray.d));
	fr = sample_f(&m->reflective.perfectspecular, *sr, wo, &wi);
	raysetvalue(&reflectedray, sr->hit_point, wi);
	fr = rgbmultrgb(&fr, whitted_trace_ray(&sr->w->tracer, \
		reflectedray, sr->depth + 1));
	fr = rgbmult(&fr, normaldotproduct(&sr->normal, wi));
	fr = rgbaddc(&phong, fr);
	return (fr);
}

t_rgbcolor			pathreflective(t_material *m, t_shaderec *sr)
{
	t_transparam	p;
	t_rgbcolor		fr;
	float			pdf;
	t_ray			reflectedray;

	vector3dcopy(&p.wo, vector3dneg(&sr->ray.d));
	fr = sample_fps(&m->reflective.perfectspecular, sr, &p, &pdf);
	raysetvalue(&reflectedray, sr->hit_point, p.wi);
	fr = rgbmult(&fr, normaldotproduct(&sr->normal, p.wi) / pdf);
	return (rgbmultrgb(&fr, path_trace(&sr->w->tracer, \
		reflectedray, sr->depth + 1)));
}
