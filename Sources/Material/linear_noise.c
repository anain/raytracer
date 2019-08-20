/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linear_noise.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <anain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 18:37:47 by anain             #+#    #+#             */
/*   Updated: 2018/04/21 23:41:19 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "noise.h"
#include "chess.h"

float				linear_noise_result(t_point3d *f, float d[2][2][2], \
					float x[4], float y[2])
{
	float			z0;

	x[0] = lerp1(f->x, d[0][0][0], d[0][0][1]);
	x[1] = lerp1(f->x, d[0][1][0], d[0][1][1]);
	x[2] = lerp1(f->x, d[1][0][0], d[1][0][1]);
	x[3] = lerp1(f->x, d[1][1][0], d[1][1][1]);
	y[0] = lerp1(f->y, x[0], x[1]);
	y[1] = lerp1(f->y, x[2], x[3]);
	z0 = lerp1(f->z, y[0], y[1]);
	return (z0);
}

float				linear_noise(t_shaderec *sr)
{
	t_intpt2		p;
	t_point3d		f;
	float			d[2][2][2];
	float			x[4];
	float			y[2];

	init_floornoise(sr, &p);
	p.k = (t_intpt){-1, -1, -1};
	f.x = sr->local_hit_point.x - p.i.x;
	f.y = sr->local_hit_point.y - p.i.y;
	f.z = sr->local_hit_point.z - p.i.z;
	while (++p.k.x <= 1)
	{
		p.k.y = -1;
		while (++p.k.y <= 1)
		{
			p.k.z = -1;
			while (++p.k.z <= 1)
				d[p.k.x][p.k.y][p.k.z] = \
			sr->materialptr->noise.value_table[ft_index(p.i.x + \
			p.k.z, p.i.y + p.k.y, p.i.z + p.k.x, sr->w)];
		}
	}
	return (linear_noise_result(&f, d, x, y));
}
