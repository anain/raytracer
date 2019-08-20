/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:16:43 by asavann           #+#    #+#             */
/*   Updated: 2017/11/10 17:34:47 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

/*
**	Default constructor
*/

void	rayinit(t_ray *ray)
{
	point3dinit(&ray->o);
	vector3dsetvalue(&ray->d, 0.0, 0.0, 1.0);
}

/*
**	Constructor
*/

void	raysetvalue(t_ray *ray, const t_point3d origin, const t_vector3d dir)
{
	point3dcpy(&ray->o, origin);
	vector3dcopy(&ray->d, dir);
}

/*
**	Copy constructor
*/

void	raycopy(t_ray *ray, const t_ray rhs)
{
	point3dcpy(&ray->o, rhs.o);
	vector3dcopy(&ray->d, rhs.d);
}

/*
**	Assignment
*/

t_ray	rayeq(t_ray *ray, const t_ray rhs)
{
	if (ray == &rhs)
		return (*ray);
	ray->o = rhs.o;
	ray->d = rhs.d;
	return (*ray);
}
