/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torus2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majulien <majulien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 14:21:14 by majulien          #+#    #+#             */
/*   Updated: 2018/04/22 17:57:52 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "torus.h"
#include <math.h>
#include "constants.h"
#include <stdlib.h>
#include <stdio.h>

void		ifcub(double s[4], double p[8])
{
	s[0] = (iszero(p[1])) ? 0 : 2 * p[3];
	if (!(iszero(p[1])))
	{
		p[3] = cbrt(-p[1]);
		s[1] = -p[3];
	}
}

void		ifquad(double coeffs[4], double z[6])
{
	coeffs[0] = z[4];
	coeffs[1] = z[3];
	coeffs[2] = 0;
	coeffs[3] = 1;
}

int			solvecubic(double c[4], double s[4])
{
	int		num;
	double	a[4];
	double	p[8];

	coefcubic(c, a);
	initcubic(a, p);
	if (iszero(p[7]))
	{
		num = (iszero(p[1])) ? 1 : 2;
		ifcub(s, p);
	}
	else if (p[7] < 0)
	{
		elsifcubic(p, s);
		num = 3;
	}
	else
	{
		elcubic(p, s);
		num = 1;
	}
	whilefincub(num, a, s);
	return (num);
}

int			solvequartic(double c[5], double s[4])
{
	double	coeffs[4];
	double	z[6];
	double	a[5];
	int		num;

	initquartic(a, z, c);
	if (iszero(z[5]))
	{
		ifquad(coeffs, z);
		num = solvecubic(coeffs, s);
		s[num++] = 0;
	}
	else
	{
		elsequartic(coeffs, z, s);
		if (elsequartic2(coeffs, z) == 0)
			return (0);
		num = solvequadric(coeffs, s);
		coeffs[0] = z[0] + z[1];
		coeffs[1] = z[4] < 0 ? z[2] : -z[2];
		coeffs[2] = 1;
		num += solvequadric(coeffs, (s + num));
	}
	whilefinquad(num, a, s);
	return (num);
}

t_normal	computenormal(t_point3d hit, const t_object *o)
{
	t_normal n;

	n.x = 4.0 * hit.x * (hit.x * hit.x + hit.y * hit.y + hit.z * hit.z - \
		(o->torus.a * o->torus.a + o->torus.b * o->torus.b));
	n.y = 4.0 * hit.y * (hit.x * hit.x + hit.y * hit.y + hit.z * hit.z - \
		(o->torus.a * o->torus.a + o->torus.b * o->torus.b) + 2.0 * \
		o->torus.a * o->torus.a);
	n.z = 4.0 * hit.z * (hit.x * hit.x + hit.y * hit.y + hit.z * hit.z - \
		(o->torus.a * o->torus.a + o->torus.b * o->torus.b));
	normalizen(&n);
	return (n);
}
