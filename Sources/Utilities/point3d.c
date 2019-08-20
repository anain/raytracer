/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:16:17 by asavann           #+#    #+#             */
/*   Updated: 2017/11/10 17:15:35 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point3d.h"
#include <math.h>

/*
** Default constructor
*/

void	point3dinit(t_point3d *p)
{
	p->x = 0.0;
	p->y = 0.0;
	p->z = 0.0;
}

/*
** Constructor
*/

void	point3dsetvalue(t_point3d *p, const double a, const double b,
	const double c)
{
	p->x = a;
	p->y = b;
	p->z = c;
}

/*
** Copy constructor
*/

void	point3dcpy(t_point3d *p, const t_point3d cpy)
{
	p->x = cpy.x;
	p->y = cpy.y;
	p->z = cpy.z;
}

/*
** Return the square of the distance between two points
*/

double	d_squared(const t_point3d *p, const t_point3d rhs)
{
	return ((p->x - rhs.x) * (p->x - rhs.x)
			+ (p->y - rhs.y) * (p->y - rhs.y)
			+ (p->z - rhs.z) * (p->z - rhs.z));
}

/*
** Return the distance between two points
*/

double	distance(const t_point3d *p, const t_point3d rhs)
{
	return (sqrt((p->x - rhs.x) * (p->x - rhs.x)
				+ (p->y - rhs.y) * (p->y - rhs.y)
				+ (p->z - rhs.z) * (p->z - rhs.z)));
}
