/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torus4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majulien <majulien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 18:53:35 by majulien          #+#    #+#             */
/*   Updated: 2018/04/22 17:57:58 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "torus.h"
#include <math.h>
#include "constants.h"
#include <stdlib.h>
#include <stdio.h>

void		coefcubic(double c[4], double a[4])
{
	a[0] = c[2] / c[3];
	a[1] = c[1] / c[3];
	a[2] = c[0] / c[3];
}

void		initcubic(double a[4], double p[8])
{
	p[3] = 0;
	a[3] = a[0] * a[0];
	p[0] = 1.0 / 3 * (-1.0 / 3 * a[3] + a[1]);
	p[1] = 1.0 / 2 * (2.0 / 27 * a[0] * a[3] - 1.0 / 3 * a[0] * a[1] + a[2]);
	p[2] = p[0] * p[0] * p[0];
	p[7] = p[1] * p[1] + p[2];
}

void		elsifcubic(double p[8], double s[4])
{
	p[5] = 1.0 / 3 * acos(-p[1] / sqrt(-p[2]));
	p[6] = 2 * sqrt(-p[0]);
	s[0] = p[6] * cos(p[5]);
	s[1] = -p[6] * cos(p[5] + M_PI / 3);
	s[2] = -p[6] * cos(p[5] - M_PI / 3);
}

void		elcubic(double p[8], double s[4])
{
	p[7] = sqrt(p[7]);
	p[3] = cbrt(p[7] - p[1]);
	p[4] = -cbrt(p[7] + p[1]);
	s[0] = p[3] + p[4];
}

void		whilefincub(int num, double a[4], double s[4])
{
	int i;

	i = 0;
	while (i < num)
	{
		s[i] -= 1.0 / 3 * a[0];
		i++;
	}
}
