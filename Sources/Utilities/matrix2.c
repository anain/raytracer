/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <anain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 15:31:05 by anain             #+#    #+#             */
/*   Updated: 2018/04/22 15:40:57 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

void			round_matrx4(t_matrix *matrix)
{
	int			i;
	int			j;

	i = -1;
	while (++i <= 3)
	{
		j = -1;
		while (++j <= 3)
			matrix->m[i][j] = ((float)((int)(matrix->m[i][j] * 100)) / 100);
	}
}

t_matrix		new_matrx4(void)
{
	t_matrix	matrix;
	int			x;
	int			y;

	x = -1;
	while (++x < 4)
	{
		y = -1;
		while (++y < 4)
			matrix.m[x][y] = 0;
	}
	matrix.m[3][3] = 1;
	return (matrix);
}

t_matrix		rotx_matrx4(float theta)
{
	t_matrix	matrix;

	matrix = new_matrx4();
	matrix.m[0][0] = 1;
	matrix.m[1][1] = cos(theta * DEG2RAD);
	matrix.m[1][2] = -sin(theta * DEG2RAD);
	matrix.m[2][1] = sin(theta * DEG2RAD);
	matrix.m[2][2] = cos(theta * DEG2RAD);
	round_matrx4(&matrix);
	return (matrix);
}

t_matrix		roty_matrx4(float theta)
{
	t_matrix	matrix;

	matrix = new_matrx4();
	matrix.m[0][0] = cos(theta * DEG2RAD);
	matrix.m[0][2] = sin(theta * DEG2RAD);
	matrix.m[1][1] = 1;
	matrix.m[2][0] = -sin(theta * DEG2RAD);
	matrix.m[2][2] = cos(theta * DEG2RAD);
	round_matrx4(&matrix);
	return (matrix);
}

t_matrix		rotz_matrx4(float theta)
{
	t_matrix	matrix;

	matrix = new_matrx4();
	matrix.m[0][0] = cos(theta * DEG2RAD);
	matrix.m[0][1] = -sin(theta * DEG2RAD);
	matrix.m[1][0] = sin(theta * DEG2RAD);
	matrix.m[1][1] = cos(theta * DEG2RAD);
	matrix.m[2][2] = 1;
	round_matrx4(&matrix);
	return (matrix);
}
