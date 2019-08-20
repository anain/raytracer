/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mmlx.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 18:27:11 by asavann           #+#    #+#             */
/*   Updated: 2018/04/24 17:13:40 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mmlx.h"
#include "maths.h"
#include "world.h"
#include <stdlib.h>
#include <math.h>

void		open_window(t_param *p)
{
	p->v.n = (int)sqrt((float)p->world.vp.numsamples);
	p->v.vp = p->world.vp;
	p->v.resolution.x = p->world.vp.hres;
	p->v.resolution.y = p->world.vp.vres;
	point3dcpy(&p->v.ray.o, p->world.camera.eye);
	if (!(p->mlx = mlx_init()))
		exit(EXIT_FAILURE);
	if (!(p->win = mlx_new_window(p->mlx, p->v.vp.win_width, \
		p->v.vp.win_height, "rt")))
		exit(EXIT_FAILURE);
	if (!(p->img = mlx_new_image(p->mlx, p->v.vp.win_width,\
		p->v.vp.win_height)))
		exit(EXIT_FAILURE);
	p->data = mlx_get_data_addr(p->img, &p->bpp, &p->size_l, &p->endian);
}

t_rgbcolor	max_to_one(const t_rgbcolor c)
{
	double		maxvalue;

	maxvalue = max(c.r, max(c.g, c.b));
	if (maxvalue > 1.0)
		return (rgbdiv(&c, maxvalue));
	return (c);
}

t_rgbcolor	clamp_to_color(const t_rgbcolor raw_color)
{
	t_rgbcolor mapped_color;

	rgbcopy(&mapped_color, raw_color);
	if (raw_color.r > 1.0 || raw_color.g > 1.0 || raw_color.b > 1.0)
	{
		mapped_color.r = 1;
		mapped_color.g = 0;
		mapped_color.b = 0;
	}
	return (mapped_color);
}

void		pixel_draw(t_param *e, int x, int y, t_rgbcolor *color)
{
	float	moy;
	int		i;

	moy = (color->b + color->g + color->r) / 3.0;
	i = (y * e->size_l) + ((e->bpp / 8) * x);
	if (y >= 0 && x >= 0 && y < e->v.vp.win_height && x < e->v.vp.win_width)
	{
		if (e->filter == BLACKNWHITE)
			color = &((t_rgbcolor) { moy, moy, moy});
		if (e->filter == BLUE)
			color = &((t_rgbcolor) { color->r, (color->g + 0.1) / 2,\
			(color->b + 2) / 3});
		if (e->filter == SEPIA)
			color = &((t_rgbcolor) { (moy + 0.8) / 2, (moy + 0.5) / 2, moy});
		e->data[i] = (int)(color->b * 255);
		e->data[++i] = (int)(color->g * 255);
		e->data[++i] = (int)(color->r * 255);
	}
}

void		display_pixel(t_param *p, const int row, const int column, \
			const t_rgbcolor pixel_color)
{
	t_rgbcolor	mapped_color;
	int			x;
	int			y;

	x = column;
	y = p->v.vp.win_height - row - 1;
	if (p->world.vp.show_out_of_gamut)
		mapped_color = clamp_to_color(pixel_color);
	else
		mapped_color = max_to_one(pixel_color);
	if (p->world.vp.gamma != 1.0)
		mapped_color = rgbpow(&pixel_color, p->world.vp.invgamma);
	pixel_draw(p, x, y, &mapped_color);
}
