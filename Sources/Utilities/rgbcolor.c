/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgbcolor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:35:24 by asavann           #+#    #+#             */
/*   Updated: 2017/11/13 15:36:02 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rgbcolor.h"
#include <math.h>

/*
** Default contructor
*/

void		rgbinit(t_rgbcolor *c)
{
	c->r = 0.0f;
	c->g = 0.0f;
	c->b = 0.0f;
}

/*
** Constructor
*/

void		rgbsetvalue(t_rgbcolor *c, float r, float g, float b)
{
	c->r = r;
	c->g = g;
	c->b = b;
}

/*
** Copy constructor
*/

void		rgbcopy(t_rgbcolor *c, const t_rgbcolor v)
{
	c->r = v.r;
	c->g = v.g;
	c->b = v.b;
}

/*
**	Assign
*/

t_rgbcolor	rgbeq(t_rgbcolor *c, const t_rgbcolor rhs)
{
	if (c == &rhs)
		return (*c);
	c->r = rhs.r;
	c->g = rhs.g;
	c->b = rhs.b;
	return (*c);
}

/*
** Raise each component to the specified power
*/

t_rgbcolor	rgbpow(const t_rgbcolor *c, float p)
{
	t_rgbcolor res;

	rgbsetvalue(&res, pow(c->r, p), pow(c->g, p), pow(c->b, p));
	return (res);
}
