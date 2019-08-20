/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:30:38 by asavann           #+#    #+#             */
/*   Updated: 2018/04/22 15:42:12 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NORMAL_H
# define NORMAL_H

# include "vector3d.h"
# include "point3d.h"
# include "matrix.h"

typedef struct	s_normal
{
	double x;
	double y;
	double z;
}				t_normal;

/*
** Default constructor
*/

void			normalinit(t_normal *n);

/*
** Constructor
*/

void			normalsetvalue(t_normal *n, double x, double y, double z);

/*
** Copy constructor
*/

void			copynormal(t_normal *n, const t_normal m);

/*
**	Construct a normal from a vector
*/

void			vectortonormal(t_normal *n, const t_vector3d v);

/*
**	Normalize the normal
*/

void			normalizen(t_normal *n);

/*
**	Assignment
*/

t_normal		normaleq(t_normal *n, const t_normal rhs);

/*
** Assign a vector to a normal
*/

t_normal		normaleqv(t_normal *n, const t_vector3d v);

/*
**	Assign a point to a vector
*/

t_normal		normaleqp(t_normal *n, const t_point3d p);

/*
** Unary minus
*/

t_normal		normalneg(const t_normal *n);

/*
** Addition of two normals
*/

t_normal		normaladd(const t_normal *n, const t_normal rhs);

/*
**	Compound addition of two normals
*/

t_normal		normaladdc(t_normal *n, const t_normal rhs);

/*
**	Dot product of a vector and a normal
*/

double			normaldotproduct(const t_normal *n, const t_vector3d rhs);

/*
**	Return multiplication by a double
*/

t_normal		normalmult(const t_normal *n, double a);

/*
**	Return a vector constructed from the addition of a vector to a normal
*/

t_vector3d		normaladdvec(const t_normal *n, const t_vector3d v);

/*
**	Return a vector constructed from the subtraction of a normal to a vector
*/

t_vector3d		normalsubvec(const t_normal *n, const t_vector3d v);

/*
**	multiplication by a matrix
*/

t_normal		normalmultmat(const t_matrix mat, const t_normal n);

double			normaldotproduct1(const t_normal *n, const t_vector3d *rhs);

#endif
