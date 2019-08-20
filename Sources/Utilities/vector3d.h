/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:18:33 by asavann           #+#    #+#             */
/*   Updated: 2018/04/22 15:45:34 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR3D_H
# define VECTOR3D_H
# include "maths.h"
# include "matrix.h"

typedef struct s_matrix		t_matrix;
typedef struct s_point3d	t_point3d;
typedef struct s_normal		t_normal;

typedef struct	s_vector3d
{
	double	x;
	double	y;
	double	z;
}				t_vector3d;

/*
** Default constructor
*/

void			vector3dinit(t_vector3d *v);

/*
** Constructor
*/

void			vector3dsetvalue(t_vector3d *v, double x, double y, double z);

/*
** Copy Constructor
*/

void			vector3dcopy(t_vector3d *cp, const t_vector3d v);

/*
** Constructs a vector from a Normal
*/

void			normaltovector(t_vector3d *v, const t_normal n);

/*
** Construct a vector from a point
*/

void			pointtovector3d(t_vector3d *v, const t_point3d p);

/*
** Assignement
*/

t_vector3d		vector3deq(t_vector3d *v, const t_vector3d rhs);

/*
** Assign a Normal to a vector
*/

t_vector3d		vector3deqn(t_vector3d *v, const t_normal rhs);

/*
** Assign a point to a vector
*/

t_vector3d		vector3deqp(t_vector3d *v, const t_point3d rhs);

/*
**	Unary minus
*/

t_vector3d		vector3dneg(const t_vector3d *v);

/*
**	Length
*/

double			length(t_vector3d *v);

/*
** Return square of the length
*/

double			len_square(t_vector3d *v);

/*
** Multiplication by a double
*/

t_vector3d		multvector3d(const t_vector3d *v, const double a);

/*
**	Division by a double
*/

t_vector3d		divvector3d(const t_vector3d *v, const double a);

/*
** Addition
*/

t_vector3d		addvector3d(const t_vector3d *v, const t_vector3d rhs);

/*
** Subtraction
*/

t_vector3d		subvector3d(const t_vector3d *v, const t_vector3d rhs);

/*
** Compound addition
*/

t_vector3d		compaddvector3d(t_vector3d *v, const t_vector3d rhs);

/*
** dot product
*/

double			dotproduct(const t_vector3d *v, const t_vector3d b);

/*
** cross product
*/

t_vector3d		crossproduct(const t_vector3d *v, const t_vector3d b);

/*
** convert a vector to a unit vector
*/

void			normalize(t_vector3d *v);

/*
** Converts the vector to a unit vector and returns the vector
*/

t_vector3d		hat(t_vector3d *v);

/*
** Return multiplication by a matrix on the left
*/

t_vector3d		matxvectord3d(const t_matrix mat, const t_vector3d v);

/*
** Return subtraction of a vector from a normal
*/

t_vector3d		vecsubnormal(const t_normal n, const t_vector3d v);

#endif
