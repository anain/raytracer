/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:39:18 by asavann           #+#    #+#             */
/*   Updated: 2018/04/22 17:08:02 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "spot.h"

void	init_spot(t_spot *spot)
{
	spot->ls = 1;
	rgbsetvalue(&spot->color, 1.0, 1.0, 1.0);
	point3dsetvalue(&spot->location, 0.0, 1.0, 0.0);
}

void	cpy_spot(t_spot *spot, const t_spot rhs)
{
	spot->ls = rhs.ls;
	rgbcopy(&spot->color, rhs.color);
	point3dcpy(&spot->location, rhs.location);
}

t_spot	eq_spot(t_spot *spot, const t_spot rhs)
{
	if (spot == &rhs)
		return (*spot);
	cpy_spot(spot, rhs);
	return (*spot);
}

void	set_colors(t_spot *spot, \
			const float r, const float g, const float b)
{
	spot->color.r = r;
	spot->color.g = g;
	spot->color.b = b;
}

float	gspot(t_light *light, t_shaderec *sr)
{
	if (light && sr)
		;
	return (1);
}
