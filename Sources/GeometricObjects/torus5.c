/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torus5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majulien <majulien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 18:57:26 by majulien          #+#    #+#             */
/*   Updated: 2018/04/22 17:58:09 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "torus.h"
#include <math.h>
#include "constants.h"
#include <stdlib.h>
#include <stdio.h>

void		initquartic(double a[5], double z[6], double c[5])
{
	a[0] = c[3] / c[4];
	a[1] = c[2] / c[4];
	a[2] = c[1] / c[4];
	a[3] = c[0] / c[4];
	a[4] = a[0] * a[0];
	z[3] = -3.0 / 8 * a[4] + a[1];
	z[4] = 1.0 / 8 * a[4] * a[0] - 1.0 / 2 * a[0] * a[1] + a[2];
	z[5] = -3.0 / 256 * a[4] * a[4] + 1.0 / 16 * a[4] * a[1] - 1.0 / 4 * a[0]\
		* a[2] + a[3];
}

void		elsequartic(double coeffs[4], double z[6], double s[4])
{
	coeffs[0] = 1.0 / 2 * z[5] * z[3] - 1.0 / 8 * z[4] * z[4];
	coeffs[1] = -z[5];
	coeffs[2] = -1.0 / 2 * z[3];
	coeffs[3] = 1;
	solvecubic(coeffs, s);
	z[0] = s[0];
	z[1] = z[0] * z[0] - z[5];
	z[2] = 2 * z[0] - z[3];
}

int			elsequartic2(double coeffs[4], double z[6])
{
	if (iszero(z[1]))
		z[1] = 0;
	else if (z[1] > 0)
		z[1] = sqrt(z[1]);
	else
		return (0);
	if (iszero(z[2]))
		z[2] = 0;
	else if (z[2] > 0)
		z[2] = sqrt(z[2]);
	else
		return (0);
	coeffs[0] = z[0] - z[1];
	coeffs[1] = z[4] < 0 ? -z[2] : z[2];
	coeffs[2] = 1;
	return (1);
}

void		whilefinquad(int num, double a[5], double s[4])
{
	int i;

	i = 0;
	while (i < num)
	{
		s[i] -= 1.0 / 4 * a[0];
		i++;
	}
}
