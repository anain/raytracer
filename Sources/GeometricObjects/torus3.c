/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torus3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majulien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 17:19:00 by majulien          #+#    #+#             */
/*   Updated: 2018/04/09 17:19:03 by majulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "torus.h"
#include <math.h>
#include "constants.h"
#include <stdlib.h>
#include <stdio.h>

int			iszero(double x)
{
	double	e;

	e = 1e-9;
	if ((x) > -e && (x) < e)
		return (1);
	return (0);
}

double		cbrt(double x)
{
	double d;

	d = ((x) > 0.0 ? pow((double)(x), 1.0 / 3.0) : \
		-pow((double)-(x), 1.0 / 3.0));
	if (x == 0.0)
		d = 0.0;
	return (d);
}

int			solvequadric(double c[3], double s[4])
{
	double p;
	double q;
	double d;

	p = c[1] / (2 * c[2]);
	q = c[0] / c[2];
	d = p * p - q;
	if (iszero(d))
	{
		s[0] = -p;
		return (1);
	}
	else if (d > 0)
	{
		d = sqrt(d);
		s[0] = d - p;
		s[1] = -d - p;
		return (2);
	}
	else
		return (0);
}
