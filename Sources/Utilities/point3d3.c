/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point3d3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:19:01 by asavann           #+#    #+#             */
/*   Updated: 2018/04/22 15:43:50 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point3d.h"
#include <stdio.h>

/*
** Return a new point from the subtraction of a vector from a point
*/

t_point3d	subvector(const t_point3d *p, const t_vector3d v)
{
	t_point3d res;

	point3dsetvalue(&res, p->x - v.x, p->y - v.y, p->z - v.z);
	return (res);
}

/*
**	Return a new point from the multipliaction by a double
*/

t_point3d	multpoint(t_point3d *p, double a)
{
	t_point3d res;

	point3dsetvalue(&res, p->x * a, p->y * a, p->z * a);
	return (res);
}

t_point3d	addpoint(t_point3d p, t_point3d n)
{
	t_point3d res;

	point3dsetvalue(&res, p.x + n.x, p.y + n.y, p.z + n.z);
	return (res);
}

t_point3d	multpointvec(t_point3d *p, t_vector3d v)
{
	t_point3d res;

	point3dsetvalue(&res, p->x * v.x, p->y * v.y, p->z * v.z);
	return (res);
}

t_point3d	multvecdouble(t_vector3d *p, double a)
{
	t_point3d res;

	point3dsetvalue(&res, p->x * a, p->y * a, p->z * a);
	return (res);
}
