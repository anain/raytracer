/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:53:52 by asavann           #+#    #+#             */
/*   Updated: 2017/11/08 17:37:42 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3d.h"
#include "normal.h"
#include "point3d.h"

/*
** Default constructor
*/

void	vector3dinit(t_vector3d *v)
{
	v->x = 0.0;
	v->y = 0.0;
	v->z = 0.0;
}

/*
** Constructor
*/

void	vector3dsetvalue(t_vector3d *v, double x, double y, double z)
{
	v->x = x;
	v->y = y;
	v->z = z;
}

/*
** Copy Constructor
*/

void	vector3dcopy(t_vector3d *cp, const t_vector3d v)
{
	cp->x = v.x;
	cp->y = v.y;
	cp->z = v.z;
}

/*
** Constructs a vector from a Normal
*/

void	normaltovector(t_vector3d *v, const t_normal n)
{
	v->x = n.x;
	v->y = n.y;
	v->z = n.z;
}

/*
** Construct a vector from a point
*/

void	pointtovector(t_vector3d *v, const t_point3d p)
{
	v->x = p.x;
	v->y = p.y;
	v->z = p.z;
}
