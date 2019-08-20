/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgbcolor2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:00:26 by asavann           #+#    #+#             */
/*   Updated: 2017/11/13 15:48:04 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rgbcolor.h"

/*
** Addition of two colors
*/

t_rgbcolor	rgbadd(const t_rgbcolor *c, const t_rgbcolor rhs)
{
	t_rgbcolor res;

	rgbsetvalue(&res, c->r + rhs.r, c->g + rhs.g, c->b + rhs.b);
	return (res);
}

/*
** Compound addition of two colors
*/

t_rgbcolor	rgbaddc(t_rgbcolor *c, const t_rgbcolor rhs)
{
	c->r += rhs.r;
	c->g += rhs.g;
	c->b += rhs.b;
	return (*c);
}

/*
** Multiplication by a float
*/

t_rgbcolor	rgbmult(const t_rgbcolor *c, const float a)
{
	t_rgbcolor res;

	rgbsetvalue(&res, c->r * a, c->g * a, c->b * a);
	return (res);
}

/*
** Compound multiplication by a float
*/

t_rgbcolor	rgbmultc(t_rgbcolor *c, const float a)
{
	c->r *= a;
	c->g *= a;
	c->b *= a;
	return (*c);
}

/*
** Multiplication of two colors
*/

t_rgbcolor	rgbmultrgb(const t_rgbcolor *c, const t_rgbcolor rhs)
{
	t_rgbcolor res;

	rgbsetvalue(&res, c->r * rhs.r, c->g * rhs.g, c->b * rhs.b);
	return (res);
}
