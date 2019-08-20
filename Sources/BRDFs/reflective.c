/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflective.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 16:48:56 by anain             #+#    #+#             */
/*   Updated: 2018/04/22 16:39:57 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brdf.h"
#include "transparence.h"
#include <stdio.h>

t_rgbcolor	sample_f(t_perfectspecular *perf, const t_shaderec sr,\
	const t_vector3d wo, t_vector3d *wi)
{
	t_normal	tmp;
	t_rgbcolor	l;
	float		ndotwo;
	double		t;
	t_vector3d	vec;

	ndotwo = normaldotproduct(&sr.normal, wo);
	tmp = normalmult(&sr.normal, 2.0 * ndotwo);
	vec = vecsubnormal(tmp, wo);
	wi->x = vec.x;
	wi->y = vec.y;
	wi->z = vec.z;
	l = rgbmult(&perf->cr, perf->kr);
	t = normaldotproduct1(&sr.normal, wi);
	l = rgbdiv(&l, t);
	return (l);
}

t_rgbcolor	sample_fps(t_perfectspecular *perf, const t_shaderec *sr,\
	t_transparam *p, float *pdf)
{
	float		ndotwo;
	t_normal	tmp;
	t_vector3d	vec;

	ndotwo = normaldotproduct(&sr->normal, p->wo);
	tmp = normalmult(&sr->normal, 2.0 * ndotwo);
	vec = vecsubnormal(tmp, p->wo);
	p->wi.x = vec.x;
	p->wi.y = vec.y;
	p->wi.z = vec.z;
	normalize(&p->wi);
	*pdf = normaldotproduct(&sr->normal, p->wi);
	return (rgbmult(&perf->cr, perf->kr));
}
