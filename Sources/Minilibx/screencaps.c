/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screencaps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorobin <jorobin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 19:36:03 by jorobin           #+#    #+#             */
/*   Updated: 2018/04/21 19:43:51 by jorobin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mmlx.h"

void		fill_screencap2(FILE *fd, t_param *p, int y)
{
	int x;
	int c;

	c = 0;
	x = -1;
	while (++x < p->v.resolution.x)
	{
		if (c + 14 >= 70)
		{
			fprintf(fd, "\n");
			c = 0;
		}
		fprintf(fd, "%d %d %d   ", (unsigned char)p->data[(y *\
					p->size_l) + ((p->bpp / 8) * x) + 2],\
				(unsigned char)p->data[(y * p->size_l) +\
				((p->bpp / 8) * x) + 1], (unsigned char)p->data[(y\
					* p->size_l) + ((p->bpp / 8) * x)]);
		c += 14;
	}
}

void		fill_screencap(t_param *p)
{
	FILE	*fd;
	int		i;
	int		y;

	y = -1;
	i = -1;
	fd = fopen("screencap.ppm", "w+");
	if (fd <= 0)
		ft_putstr("fopen error\n");
	fprintf(fd, "P3\n%d %d\n255\n", p->v.vp.win_width, p->v.vp.win_height);
	while (++i < p->v.vp.win_width * p->v.vp.win_height * 4)
	{
		while (++y < p->v.resolution.y)
			fill_screencap2(fd, p, y);
	}
	fclose(fd);
}
