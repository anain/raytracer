/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point3d2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:46:10 by asavann           #+#    #+#             */
/*   Updated: 2017/11/10 17:03:40 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point3d.h"
#include <math.h>

/*
** Assignement
*/

t_point3d	point3deq(t_point3d *p, const t_point3d rhs)
{
	if (p == &rhs)
		return (*p);
	p->x = rhs.x;
	p->y = rhs.y;
	p->z = rhs.z;
	return (*p);
}

/*
** Multiplication by a matrix on the left
*/

t_point3d	point3dmultmat(const t_matrix mat,
		const t_point3d rhs)
{
	t_point3d res;

	point3dsetvalue(&res,
		mat.m[0][0] * rhs.x + mat.m[0][1] * rhs.y + mat.m[0][2] * rhs.z
		+ mat.m[0][3],
		mat.m[1][0] * rhs.x + mat.m[1][1] * rhs.y + mat.m[1][2] * rhs.z
		+ mat.m[1][3],
		mat.m[2][0] * rhs.x + mat.m[2][1] * rhs.y + mat.m[2][2] * rhs.z
		+ mat.m[2][3]);
	return (res);
}

/*
** Unary minus
*/

t_point3d	point3dneg(const t_point3d *p)
{
	t_point3d neg;

	point3dsetvalue(&neg, -p->x, -p->y, -p->z);
	return (neg);
}

/*
** Return the vector joining the two points
*/

t_vector3d	getvector(const t_point3d *p, const t_point3d rhs)
{
	t_vector3d v;

	vector3dsetvalue(&v, p->x - rhs.x, p->y - rhs.y, p->z - rhs.z);
	return (v);
}

/*
** Return a new point by the addition of a vector to a point
*/

t_point3d	addvector(const t_point3d *p, const t_vector3d v)
{
	t_point3d res;

	point3dsetvalue(&res, p->x + v.x, p->y + v.y, p->z + v.z);
	return (res);
}
