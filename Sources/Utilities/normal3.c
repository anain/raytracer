/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:25:21 by asavann           #+#    #+#             */
/*   Updated: 2018/04/22 15:42:48 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "normal.h"

/*
**	Compound addition of two normals
*/

t_normal	normaladdc(t_normal *n, const t_normal rhs)
{
	n->x += rhs.x;
	n->y += rhs.y;
	n->z += rhs.z;
	return (*n);
}

/*
**	Dot product of a vector and a normal
*/

double		normaldotproduct(const t_normal *n, const t_vector3d rhs)
{
	return (n->x * rhs.x + n->y * rhs.y + n->z * rhs.z);
}

/*
**	Dot product of a vector and a normal
*/

double		normaldotproduct1(const t_normal *n, const t_vector3d *rhs)
{
	return (n->x * rhs->x + n->y * rhs->y + n->z * rhs->z);
}

/*
**	Return multiplication by a double
*/

t_normal	normalmult(const t_normal *n, double a)
{
	t_normal res;

	normalsetvalue(&res, n->x * a, n->y * a, n->z * a);
	return (res);
}

/*
** Return a vector constructed from the addition of a vector to a normal
*/

t_vector3d	normaladdvec(const t_normal *n, const t_vector3d v)
{
	t_vector3d res;

	vector3dsetvalue(&res, n->x + v.x, n->y + v.y, n->z + v.z);
	return (res);
}
