/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3d3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:11:23 by asavann           #+#    #+#             */
/*   Updated: 2017/11/08 18:31:04 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3d.h"

/*
** Return square of the length
*/

double		len_square(t_vector3d *v)
{
	return (v->x * v->x + v->y * v->y + v->z * v->z);
}

/*
** Multiplication by a double
*/

t_vector3d	multvector3d(const t_vector3d *v, const double a)
{
	t_vector3d res;

	vector3dsetvalue(&res, v->x * a, v->y * a, v->z * a);
	return (res);
}

/*
**	Division by a double
*/

t_vector3d	divvector3d(const t_vector3d *v, const double a)
{
	t_vector3d res;

	vector3dsetvalue(&res, v->x / a, v->y / a, v->z / a);
	return (res);
}

/*
** Addition
*/

t_vector3d	addvector3d(const t_vector3d *v, const t_vector3d rhs)
{
	t_vector3d res;

	vector3dsetvalue(&res, v->x + rhs.x, v->y + rhs.y, v->z + rhs.z);
	return (res);
}

/*
** Subtraction
*/

t_vector3d	subvector3d(const t_vector3d *v, const t_vector3d rhs)
{
	t_vector3d res;

	vector3dsetvalue(&res, v->x - rhs.x, v->y - rhs.y, v->z - rhs.z);
	return (res);
}
