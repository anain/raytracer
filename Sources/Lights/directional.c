/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directional.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 17:06:28 by asavann           #+#    #+#             */
/*   Updated: 2017/11/30 17:02:23 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "directional.h"

void	set_colord(t_directional *d, \
	const float r, const float g, const float b)
{
	d->color.r = r;
	d->color.g = g;
	d->color.b = b;
}

void	set_directiond(t_directional *d, \
	const float dx, const float dy, const float dz)
{
	d->dir.x = dx;
	d->dir.y = dy;
	d->dir.z = dz;
	normalize(&d->dir);
}

void	scale_radiance(t_directional *d, const float b)
{
	d->ls = b;
}

void	init_d(t_directional *d)
{
	d->ls = 1;
	set_directiond(d, 0, 1, 0);
	set_colord(d, 1, 1, 1);
}

void	cpy_d(t_directional *d, const t_directional rhs)
{
	d->ls = rhs.ls;
	set_directiond(d, rhs.dir.x, rhs.dir.y, rhs.dir.z);
	set_colord(d, rhs.color.r, rhs.color.g, rhs.color.b);
}
