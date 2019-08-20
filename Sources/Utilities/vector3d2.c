/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3d2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:38:47 by asavann           #+#    #+#             */
/*   Updated: 2017/11/17 19:54:16 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3d.h"
#include "normal.h"
#include "point3d.h"
#include <math.h>

/*
** Assignement
*/

t_vector3d	vector3deq(t_vector3d *v, const t_vector3d rhs)
{
	if (v == &rhs)
		return (*v);
	v->x = rhs.x;
	v->y = rhs.y;
	v->z = rhs.z;
	return (*v);
}

/*
** Assign a Normal to a vector
*/

t_vector3d	vector3deqn(t_vector3d *v, const t_normal rhs)
{
	v->x = rhs.x;
	v->y = rhs.y;
	v->z = rhs.z;
	return (*v);
}

/*
** Assign a point to a vector
*/

t_vector3d	vector3deqp(t_vector3d *v, const t_point3d rhs)
{
	v->x = rhs.x;
	v->y = rhs.y;
	v->z = rhs.z;
	return (*v);
}

/*
** Unary minus
*/

t_vector3d	vector3dneg(const t_vector3d *v)
{
	t_vector3d res;

	vector3dsetvalue(&res, -v->x, -v->y, -v->z);
	return (res);
}

/*
**	Length
*/

double		length(t_vector3d *v)
{
	return (sqrt(v->x * v->x + v->y * v->y + v->z * v->z));
}
