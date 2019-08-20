/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point3d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:00:38 by asavann           #+#    #+#             */
/*   Updated: 2018/03/26 17:12:06 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT3D_H
# define POINT3D_H

# include "maths.h"
# include "matrix.h"
# include "vector3d.h"

typedef struct	s_point3d
{
	double x;
	double y;
	double z;
}				t_point3d;

/*
** Default constructor
*/

void			point3dinit(t_point3d *p);

/*
** Constructor
*/

void			point3dsetvalue(t_point3d *p, const double a, const double b,
		const double c);

/*
** Copy constructor
*/

void			point3dcpy(t_point3d *p, const t_point3d cpy);

/*
** Return the square of the distance between two points
*/

double			d_squared(const t_point3d *p, const t_point3d rhs);

/*
** Return the distance between two points
*/

double			distance(const t_point3d *p, const t_point3d rhs);

/*
** Assignement
*/

t_point3d		point3deq(t_point3d *p, const t_point3d rhs);

/*
** Multiplication by a matrix on the left
*/

t_point3d		point3dmultmat(const t_matrix mat,
		const t_point3d rhs);

/*
** Unary minus
*/

t_point3d		point3dneg(const t_point3d *p);

/*
** Return the vector joining the two points
*/

t_vector3d		getvector(const t_point3d *p, const t_point3d rhs);

/*
** Return a new point from the addition of a vector to a point
*/

t_point3d		addvector(const t_point3d *p, const t_vector3d v);

/*
** Return a new point from the subtraction of a vector from a point
*/

t_point3d		subvector(const t_point3d *p, const t_vector3d v);

/*
** Return a new point from the addition of two points
*/

t_point3d		addpoint(t_point3d p, t_point3d n);

/*
** Return a new point from the multiplication of a point and a vector
*/

t_point3d		multpointvec(t_point3d *p, t_vector3d v);

/*
** Return a new point from the multiplication of a point by a double
*/

t_point3d		multpoint(t_point3d *p, double a);

t_point3d		multvecdouble(t_vector3d *p, double a);

#endif
