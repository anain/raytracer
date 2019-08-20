/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometricobjects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <anain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 17:20:19 by anain             #+#    #+#             */
/*   Updated: 2018/04/22 17:21:33 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometricobjects.h"
#include <stdio.h>

int		shadow_hittransform(const t_object *obj, const t_ray ray, float *tmin)
{
	t_ray inv_ray;

	inv_ray.o = point3dmultmat(obj->inv_mat, ray.o);
	inv_ray.d = matxvectord3d(obj->inv_mat, ray.d);
	if (obj->shadow_hittrans(obj, inv_ray, tmin))
		return (1);
	return (0);
}

int		hittransform(\
		const t_object *obj, const t_ray ray, double *tmin, t_shaderec *sr)
{
	t_ray inv_ray;

	inv_ray.o = point3dmultmat(obj->inv_mat, ray.o);
	inv_ray.d = matxvectord3d(obj->inv_mat, ray.d);
	if (obj->hittrans(obj, inv_ray, tmin, sr))
	{
		sr->normal = normalmultmat(obj->inv_mat, sr->normal);
		normalizen(&sr->normal);
		sr->local_hit_point = addvector(&inv_ray.o, \
			multvector3d(&ray.d, *tmin));
		return (1);
	}
	return (0);
}
