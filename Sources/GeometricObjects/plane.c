/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:02:54 by asavann           #+#    #+#             */
/*   Updated: 2018/04/22 18:09:24 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plane.h"
#include "normal.h"
#include <math.h>
#include "shaderec.h"
#include <stdio.h>

int		planehit(const t_object *o, const t_ray ray, double *tmin, \
		t_shaderec *sr)
{
	double		t;
	double		dot;

	dot = normaldotproduct(&o->plane.normal, ray.d);
	if (fabs(dot) > 0.0001f)
	{
		t = normaldotproduct(\
			&o->plane.normal, getvector(&o->plane.point, ray.o)) / dot;
		if (t > o->plane.kepsilon)
		{
			*tmin = t;
			sr->normal = o->plane.normal;
			sr->local_hit_point = addvector(&ray.o, multvector3d(&ray.d, t));
			return (1);
		}
	}
	return (0);
}

int		planehitshadow(const t_object *o, const t_ray ray, float *tmin)
{
	double		t;
	double		dot;

	dot = normaldotproduct(&o->plane.normal, ray.d);
	if (fabs(dot) > 0.0001f)
	{
		t = normaldotproduct(\
			&o->plane.normal, getvector(&o->plane.point, ray.o)) / dot;
		if (t > o->plane.kepsilon)
		{
			*tmin = t;
			return (1);
		}
	}
	return (0);
}

void	planeinit(t_plane *plane)
{
	point3dsetvalue(&plane->point, 0.0, 0.0, 0.0);
	normalsetvalue(&plane->normal, 0.0, 1.0, 0.0);
}
