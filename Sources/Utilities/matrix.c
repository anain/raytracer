/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:36:52 by asavann           #+#    #+#             */
/*   Updated: 2018/03/25 16:38:52 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

void		set_identity(t_matrix *matrix)
{
	int x;
	int y;

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (x == y)
				matrix->m[x][y] = 1;
			else
				matrix->m[x][y] = 0;
			y++;
		}
		x++;
	}
}

void		matrixcpy(t_matrix *matrix, const t_matrix mat)
{
	int x;
	int y;

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			matrix->m[x][y] = mat.m[x][y];
			y++;
		}
		x++;
	}
}

t_matrix	matrixequal(t_matrix *matrix, const t_matrix rhs)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (matrix == &rhs)
		return (*matrix);
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			matrix->m[x][y] = rhs.m[x][y];
			y++;
		}
		x++;
	}
	return (*matrix);
}

t_matrix	matrixmult(const t_matrix *matrix, const t_matrix rhs)
{
	t_matrix	product;
	int			x;
	int			y;
	int			j;
	double		sum;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			sum = 0.0;
			j = 0;
			while (j < 4)
			{
				sum += matrix->m[x][j] * rhs.m[j][y];
				j++;
			}
			product.m[x][y] = sum;
			x++;
		}
		y++;
	}
	return (product);
}

t_matrix	matrixdiv(t_matrix *matrix, const double d)
{
	int x;
	int y;

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			matrix->m[x][y] = matrix->m[x][y] / d;
			y++;
		}
		x++;
	}
	return (*matrix);
}
