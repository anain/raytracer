/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transparence.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 16:25:08 by anain             #+#    #+#             */
/*   Updated: 2018/04/22 16:35:35 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transparence.h"

t_rgbcolor				shadetransp(t_material *m, t_shaderec *sr)
{
	t_transparam		tp;
	t_rgbcolor			l;

	l = shadephong(m, sr);
	vector3dcopy(&tp.wo, vector3dneg(&sr->ray.d));
	tp.fr = sample_f(&m->reflective.perfectspecular, *sr, tp.wo, &tp.wi);
	raysetvalue(&tp.reflected_ray, sr->hit_point, tp.wi);
	if (transmitter_tir(sr, m) > 0)
		l = rgbadd(&l, whitted_trace_ray(&sr->w->tracer, tp.reflected_ray, \
			sr->depth + 1));
	else
	{
		tp.ft = sample_ft(&m->transparence.perft, *sr, tp.wo, &tp.wt);
		raysetvalue(&tp.transmitted_ray, sr->hit_point, tp.wt);
		tp.fr = rgbmultrgb(&tp.fr, whitted_trace_ray(&sr->w->tracer, \
			tp.reflected_ray, sr->depth + 1));
		tp.fr = rgbmult(&tp.fr, fabs(normaldotproduct1(&sr->normal, &tp.wi)));
		l = rgbadd(&l, tp.fr);
		tp.ft = rgbmultrgb(&tp.ft, whitted_trace_ray(&sr->w->tracer, \
			tp.transmitted_ray, sr->depth + 1));
		tp.ft = rgbmult(&tp.ft, fabs(normaldotproduct1(&sr->normal, &tp.wt)));
		l = rgbadd(&l, tp.ft);
	}
	return (l);
}

t_rgbcolor				pathtransp(t_material *m, t_shaderec *sr)
{
	t_transparam		tp;
	float				pdf;
	t_rgbcolor			l;

	vector3dcopy(&tp.wo, vector3dneg(&sr->ray.d));
	tp.fr = sample_fps(&m->reflective.perfectspecular, sr, &tp, &pdf);
	raysetvalue(&tp.reflected_ray, sr->hit_point, tp.wi);
	if (transmitter_tir(sr, m) > 0)
		return (rgbmultrgb(&tp.fr, path_trace(&sr->w->tracer, \
			tp.reflected_ray, sr->depth + 1)));
	else
	{
		tp.fr = rgbmult(&tp.fr, \
			fabs(normaldotproduct(&sr->normal, tp.wi) / pdf));
		tp.fr = rgbmultrgb(&tp.fr, path_trace(&sr->w->tracer, \
			tp.reflected_ray, sr->depth + 1));
		tp.ft = sample_ftps(&m->transparence.perft, *sr, &tp, &pdf);
		raysetvalue(&tp.transmitted_ray, sr->hit_point, tp.wt);
		tp.ft = rgbmult(&tp.ft, \
			fabs(normaldotproduct(&sr->normal, tp.wt) / pdf));
		tp.ft = rgbmultrgb(&tp.ft, path_trace(&sr->w->tracer, \
			tp.transmitted_ray, sr->depth + 1));
		l = rgbadd(&tp.fr, tp.ft);
	}
	return (l);
}
