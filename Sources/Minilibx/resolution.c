/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorobin <jorobin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:06:16 by jorobin           #+#    #+#             */
/*   Updated: 2018/04/24 22:06:20 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mmlx.h"

void	display_res(t_param *p, const int x, const int y, \
		const t_rgbcolor pixel_color)
{
	int				i;
	int				j;
	int				start_x;
	int				start_y;
	t_rgbcolor		c;

	j = 0;
	c = pixel_color;
	start_x = x - (p->v.pix_per_case.x / 2);
	start_y = y - (p->v.pix_per_case.y / 2);
	while (j != p->v.pix_per_case.y)
	{
		i = 0;
		while (i != p->v.pix_per_case.x)
		{
			display_pixel(p, (int)start_y + j, (int)start_x + i, pixel_color);
			i++;
		}
		j++;
	}
}

void	change_res(int keycode, t_param *e)
{
	if (keycode == MINUS && e->v.resolution.x / 2 > 20 && \
			e->v.resolution.y / 2 > 20)
	{
		e->v.resolution.x /= 2;
		e->v.resolution.y /= 2;
	}
	if (keycode == PLUS && e->v.resolution.x * 2 \
			<= e->v.vp.win_width && e->v.resolution.y * 2 <= e->v.vp.win_height)
	{
		e->v.resolution.x *= 2;
		e->v.resolution.y *= 2;
	}
}
