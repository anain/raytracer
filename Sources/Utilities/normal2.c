/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:29:57 by asavann           #+#    #+#             */
/*   Updated: 2017/11/10 16:25:56 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "normal.h"

/*
** Assignment
*/

t_normal	normaleq(t_normal *n, const t_normal rhs)
{
	if (n == &rhs)
		return (*n);
	n->x = rhs.x;
	n->y = rhs.y;
	n->z = rhs.z;
	return (*n);
}

/*
**	Assign a vector to a normal
*/

t_normal	normaleqv(t_normal *n, const t_vector3d v)
{
	n->x = v.x;
	n->y = v.y;
	n->z = v.z;
	return (*n);
}

/*
** Assign a point to a normal
*/

t_normal	normaleqp(t_normal *n, const t_point3d p)
{
	n->x = p.x;
	n->y = p.y;
	n->z = p.z;
	return (*n);
}

/*
**	Unary minus
*/

t_normal	normalneg(const t_normal *n)
{
	t_normal neg;

	normalsetvalue(&neg, -n->x, -n->y, -n->z);
	return (neg);
}

/*
**	Addition of two normals
*/

t_normal	normaladd(const t_normal *n, const t_normal rhs)
{
	t_normal res;

	normalsetvalue(&res, n->x + rhs.x, n->y + rhs.y, n->z + rhs.z);
	return (res);
}
