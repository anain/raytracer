/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perfecttransmitter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 18:33:21 by anain             #+#    #+#             */
/*   Updated: 2018/04/22 16:44:34 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brdf.h"
#include <math.h>
#include "world.h"
#include <stdio.h>

/*
** Check for total internal reflection
*/

int			transmitter_tir(const t_shaderec *sr, t_material *m)
{
	t_vector3d	wo;
	float		cos_thetai;
	float		eta;

	wo = vector3dneg(&sr->ray.d);
	cos_thetai = normaldotproduct(&sr->normal, wo);
	eta = m->transparence.perft.ior;
	if (cos_thetai < 0.0)
		eta = 1.0 / eta;
	return (1.0 - ((1.0 - cos_thetai * cos_thetai) / (eta * eta)) < 0.0);
}

t_rgbcolor	sample_ft(t_transparence *perft, const t_shaderec sr, \
	const t_vector3d wo, t_vector3d *wt)
{
	t_normal	n;
	t_parambrdf	p;
	t_rgbcolor	l;

	p.eta = perft->ior;
	n = sr.normal;
	p.cos_theta_i = normaldotproduct(&n, wo);
	if (p.cos_theta_i < 0.0)
	{
		p.cos_theta_i = -p.cos_theta_i;
		n.x = -n.x;
		n.y = -n.y;
		n.z = -n.z;
		p.eta = 1.0 / p.eta;
	}
	p.tmp = 1.0 - ((1.0 - p.cos_theta_i * p.cos_theta_i) / (p.eta * p.eta));
	p.cos_theta2 = sqrt(p.tmp);
	*wt = vector3dneg(&wo);
	*wt = divvector3d(wt, p.eta);
	n = normalmult(&n, p.cos_theta2 - p.cos_theta_i / p.eta);
	*wt = normalsubvec(&n, *wt);
	l = rgbmult(&WHITE, perft->kt / (p.eta * p.eta));
	l = rgbdiv(&l, fabs(normaldotproduct1(&sr.normal, wt)));
	return (l);
}

t_rgbcolor	sample_ftps(t_transparence *perft, const t_shaderec sr, \
	t_transparam *mp, float *pdf)
{
	t_normal	n;
	t_parambrdf	p;
	t_rgbcolor	l;

	p.eta = perft->ior;
	n = sr.normal;
	p.cos_theta_i = normaldotproduct(&n, mp->wo);
	if (p.cos_theta_i < 0.0)
	{
		p.cos_theta_i = -p.cos_theta_i;
		n.x = -n.x;
		n.y = -n.y;
		n.z = -n.z;
		p.eta = 1.0 / p.eta;
	}
	p.tmp = 1.0 - ((1.0 - p.cos_theta_i * p.cos_theta_i) / (p.eta * p.eta));
	p.cos_theta2 = sqrt(p.tmp);
	mp->wt = vector3dneg(&mp->wo);
	mp->wt = divvector3d(&mp->wt, p.eta);
	n = normalmult(&n, p.cos_theta2 - p.cos_theta_i / p.eta);
	mp->wt = normalsubvec(&n, mp->wt);
	l = rgbmult(&WHITE, perft->kt / (p.eta * p.eta));
	*pdf = fabs(normaldotproduct1(&sr.normal, &mp->wt));
	return (l);
}
