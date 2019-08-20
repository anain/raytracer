/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgbcolor3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:38:19 by asavann           #+#    #+#             */
/*   Updated: 2017/11/13 16:06:30 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rgbcolor.h"

/*
** Division by float
*/

t_rgbcolor	rgbdiv(const t_rgbcolor *c, const float a)
{
	t_rgbcolor res;

	rgbsetvalue(&res, c->r / a, c->g / a, c->b / a);
	return (res);
}

/*
** Compound division by float
*/

t_rgbcolor	rgbdivc(t_rgbcolor *c, const float a)
{
	c->r /= a;
	c->g /= a;
	c->b /= a;
	return (*c);
}

/*
** Compare two colors
*/

int			rgbcomp(const t_rgbcolor *c, const t_rgbcolor rhs)
{
	int a;

	a = 0;
	if (c->r == rhs.r && c->g == rhs.g && c->b == rhs.b)
		a = 1;
	return (a);
}

/*
** Return the average of the 3 components
*/

float		average(const t_rgbcolor *c)
{
	return (0.333333333333 * (c->r + c->g + c->b));
}
