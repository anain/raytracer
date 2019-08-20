/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometricobjects2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 19:22:06 by asavann           #+#    #+#             */
/*   Updated: 2018/04/22 18:07:13 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometricobjects.h"
#include <math.h>
#include "constants.h"

void	rotate_x(t_matrix *inv_mat, double theta)
{
	double		cos_theta;
	double		sin_theta;
	t_matrix	inv_matrix;

	cos_theta = cos(theta * PI / 180.0);
	sin_theta = sin(theta * PI / 180.0);
	set_identity(&inv_matrix);
	inv_matrix.m[1][1] = cos_theta;
	inv_matrix.m[1][2] = sin_theta;
	inv_matrix.m[2][1] = -sin_theta;
	inv_matrix.m[2][2] = cos_theta;
	inv_matrix = matrixmult(inv_mat, inv_matrix);
	*inv_mat = inv_matrix;
}

void	rotate_y(t_matrix *inv_mat, double theta)
{
	double		cos_theta;
	double		sin_theta;
	t_matrix	inv_matrix;

	cos_theta = cos(theta * PI / 180.0);
	sin_theta = sin(theta * PI / 180.0);
	set_identity(&inv_matrix);
	inv_matrix.m[0][0] = cos_theta;
	inv_matrix.m[0][2] = -sin_theta;
	inv_matrix.m[2][0] = sin_theta;
	inv_matrix.m[2][2] = cos_theta;
	inv_matrix = matrixmult(inv_mat, inv_matrix);
	*inv_mat = inv_matrix;
}

void	rotate_z(t_matrix *inv_mat, double theta)
{
	double		cos_theta;
	double		sin_theta;
	t_matrix	inv_matrix;

	cos_theta = cos(theta * PI / 180.0);
	sin_theta = sin(theta * PI / 180.0);
	set_identity(&inv_matrix);
	inv_matrix.m[0][0] = cos_theta;
	inv_matrix.m[0][1] = sin_theta;
	inv_matrix.m[1][0] = -sin_theta;
	inv_matrix.m[1][1] = cos_theta;
	inv_matrix = matrixmult(inv_mat, inv_matrix);
	*inv_mat = inv_matrix;
}
