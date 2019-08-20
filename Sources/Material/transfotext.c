/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfotext.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <anain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 15:10:21 by anain             #+#    #+#             */
/*   Updated: 2018/04/21 23:18:06 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mmlx.h"
#include <math.h>
#include "point3d.h"
#include <unistd.h>

void		translate_texture(t_material *m, double dx, double dy, double dz)
{
	t_matrix transfo;

	set_identity(&transfo);
	transfo.m[0][3] = -dx;
	transfo.m[1][3] = -dy;
	transfo.m[2][3] = -dz;
	m->inv_mat = matrixmult(&m->inv_mat, transfo);
}

void		scale_texture(t_material *m, double a, double b, double c)
{
	t_matrix transfo;

	set_identity(&transfo);
	transfo.m[0][0] = 1 / a;
	transfo.m[1][1] = 1 / b;
	transfo.m[2][2] = 1 / c;
	m->inv_mat = matrixmult(&m->inv_mat, transfo);
}

void		rotate_tex_x(t_material *m, double theta)
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
	m->inv_mat = matrixmult(&m->inv_mat, inv_matrix);
}

void		rotate_tex_y(t_material *m, double theta)
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
	m->inv_mat = matrixmult(&m->inv_mat, inv_matrix);
}

void		rotate_tex_z(t_material *m, double theta)
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
	m->inv_mat = matrixmult(&m->inv_mat, inv_matrix);
}
