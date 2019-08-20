/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:06:31 by asavann           #+#    #+#             */
/*   Updated: 2017/11/10 15:32:51 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "normal.h"
#include <math.h>

/*
** Default constructor
*/

void	normalinit(t_normal *n)
{
	n->x = 0.0;
	n->y = 0.0;
	n->z = 0.0;
}

/*
** Constructor
*/

void	normalsetvalue(t_normal *n, double x, double y, double z)
{
	n->x = x;
	n->y = y;
	n->z = z;
}

/*
** Copy constructor
*/

void	copynormal(t_normal *n, const t_normal m)
{
	n->x = m.x;
	n->y = m.y;
	n->z = m.z;
}

/*
** Construct a normal from a vector
*/

void	vectortonormal(t_normal *n, const t_vector3d v)
{
	n->x = v.x;
	n->y = v.y;
	n->z = v.z;
}

/*
** Normalize the normal
*/

void	normalizen(t_normal *n)
{
	double length;

	length = sqrt(n->x * n->x + n->y * n->y + n->z * n->z);
	n->x /= length;
	n->y /= length;
	n->z /= length;
}
