/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glossyspecular.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:56:06 by asavann           #+#    #+#             */
/*   Updated: 2018/04/22 15:38:14 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brdf.h"
#include "material.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void				glossyinit(t_glossyspecular *spec)
{
	spec->ks = 0.0;
	spec->exp = 0.0;
	rgbsetvalue(&spec->cs, 0.0, 0.0, 0.0);
}

void				glossycopy(\
					t_glossyspecular *spec, const t_glossyspecular cpy)
{
	spec->ks = cpy.ks;
	spec->exp = cpy.exp;
	rgbcopy(&spec->cs, cpy.cs);
}

t_glossyspecular	glossynew(\
					t_glossyspecular *spec, const t_glossyspecular cpy)
{
	glossycopy(spec, cpy);
	return (*spec);
}

t_rgbcolor			glossyf(\
					t_glossyspecular *spec, const t_shaderec sr, \
					const t_vector3d wo, const t_vector3d wi)
{
	t_vector3d	r;
	t_rgbcolor	l;
	float		rdotwo;
	float		ndotwi;
	t_normal	tmp;

	rgbinit(&l);
	vector3dcopy(&r, vector3dneg(&wi));
	ndotwi = normaldotproduct(&sr.normal, wi);
	tmp = normalmult(&sr.normal, 2.0 * ndotwi);
	r = normaladdvec(&tmp, r);
	rdotwo = dotproduct(&r, wo);
	if (rdotwo > 0.0)
		l = rgbmult(&spec->cs, spec->ks * pow(rdotwo, spec->exp));
	return (l);
}

t_rgbcolor			glossyfps(\
					t_glossyspecular *spec, const t_shaderec *sr,\
					t_matparam *mp, float *pdf)
{
	float		ndotwo;
	t_normal	tmp;
	t_vector3d	r;
	t_parambrdf	p;
	t_point3d	sp;

	ndotwo = normaldotproduct(&sr->normal, mp->wo);
	tmp = normalmult(&sr->normal, 2.0 * ndotwo);
	r = vecsubnormal(tmp, mp->wo);
	p.w = r;
	normalize(&p.w);
	p.v = crossproduct(&p.w, (t_vector3d){0.0034, 1.0, 0.0071});
	normalize(&p.v);
	p.u = crossproduct(&p.v, p.w);
	sp = sample_unit_hemishpere(&spec->sampler);
	mp->wi.x = sp.x * p.u.x + sp.y * p.v.x + sp.z * p.w.x;
	mp->wi.y = sp.x * p.u.y + sp.y * p.v.y + sp.z * p.w.y;
	mp->wi.z = sp.x * p.u.z + sp.y * p.v.z + sp.z * p.w.z;
	normalize(&mp->wi);
	*pdf = normaldotproduct(&sr->normal, mp->wi);
	return (rgbmult(&spec->cs, spec->ks));
}
