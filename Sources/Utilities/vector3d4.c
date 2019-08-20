/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3d4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:31:38 by asavann           #+#    #+#             */
/*   Updated: 2017/11/10 15:01:59 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3d.h"
#include <math.h>

/*
** Compound addition
*/

t_vector3d	compaddvector3d(t_vector3d *v, const t_vector3d rhs)
{
	v->x += rhs.x;
	v->y += rhs.y;
	v->z += rhs.z;
	return (*v);
}

/*
** dot product
*/

double		dotproduct(const t_vector3d *v, const t_vector3d b)
{
	return (v->x * b.x + v->y * b.y + v->z * b.z);
}

/*
** cross product
*/

t_vector3d	crossproduct(const t_vector3d *v, const t_vector3d b)
{
	t_vector3d	res;

	vector3dsetvalue(&res, v->y * b.z - v->z * b.y,
					v->z * b.x - v->x * b.z,
					v->x * b.y - v->y * b.x);
	return (res);
}

/*
** convert the vector to a unit vector
*/

void		normalize(t_vector3d *v)
{
	double length;

	length = sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
	v->x /= length;
	v->y /= length;
	v->z /= length;
}

/*
** convert the vector to a unit vector and return the vector
*/

t_vector3d	hat(t_vector3d *v)
{
	double length;

	length = sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
	v->x /= length;
	v->y /= length;
	v->z /= length;
	return (*v);
}
