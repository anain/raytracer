/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objtransfo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <anain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 17:20:49 by anain             #+#    #+#             */
/*   Updated: 2018/04/23 14:34:43 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometricobjects.h"
#include <stdio.h>

void	translate(t_object *obj, \
		const double dx, const double dy, const double dz)
{
	t_matrix	inv_matrix;

	set_identity(&inv_matrix);
	inv_matrix.m[0][3] = -dx;
	inv_matrix.m[1][3] = -dy;
	inv_matrix.m[2][3] = -dz;
	obj->d = addpoint(obj->d, (t_point3d) {dx, dy, dz});
	obj->inv_mat = matrixmult(&obj->inv_mat, inv_matrix);
}

void	translate_tex(t_object *obj, \
		const double dx, const double dy, const double dz)
{
	t_matrix	inv_matrix;

	set_identity(&inv_matrix);
	inv_matrix.m[0][3] = -dx;
	inv_matrix.m[1][3] = -dy;
	inv_matrix.m[2][3] = -dz;
	obj->mat.inv_mat = matrixmult(&obj->mat.inv_mat, inv_matrix);
}

void	translatevec(t_object *obj, const t_vector3d vec)
{
	t_matrix inv_matrix;

	set_identity(&inv_matrix);
	inv_matrix.m[0][3] = -vec.x;
	inv_matrix.m[1][3] = -vec.y;
	inv_matrix.m[2][3] = -vec.z;
	obj->inv_mat = matrixmult(&obj->inv_mat, inv_matrix);
}

void	scale(t_object *obj, double a, double b, double c)
{
	t_matrix inv_matrix;

	set_identity(&inv_matrix);
	inv_matrix.m[0][0] = 1 / a;
	inv_matrix.m[1][1] = 1 / b;
	inv_matrix.m[2][2] = 1 / c;
	obj->inv_mat = matrixmult(&obj->inv_mat, inv_matrix);
}
