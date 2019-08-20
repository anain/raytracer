/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubic_noise.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <anain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 16:18:52 by anain             #+#    #+#             */
/*   Updated: 2018/04/22 14:52:43 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "noise.h"
#include "chess.h"

float			four_knot_spline(float x, float knots[4])
{
	float		c3;
	float		c2;
	float		c1;
	float		c0;

	c3 = -0.5 * knots[0] + 1.5 * knots[1] - 1.5 * knots[2] + 0.5 * knots[3];
	c2 = knots[0] - 2.5 * knots[1] + 2.0 * knots[2] - 0.5 * knots[3];
	c1 = 0.5 * (-knots[0] + knots[2]);
	c0 = knots[1];
	return (((c3 * x + c2) * x + c1) * x + c0);
}

float			clamp(float x, float min, float max)
{
	if (x < min)
		return (min);
	else if (x > max)
		return (max);
	return (x);
}

void			init_floornoise(t_shaderec *sr, t_intpt2 *p)
{
	p->k.x = -2;
	p->i.x = (int)ft_floor(sr->local_hit_point.x);
	p->i.y = (int)ft_floor(sr->local_hit_point.y);
	p->i.z = (int)ft_floor(sr->local_hit_point.z);
}

float			cubic_noise(t_shaderec *sr)
{
	t_intpt2		p;
	t_point3d		f;
	float			xknots[4];
	float			yknots[4];
	float			zknots[4];

	init_floornoise(sr, &p);
	f.x = sr->local_hit_point.x - p.i.x;
	f.y = sr->local_hit_point.y - p.i.y;
	f.z = sr->local_hit_point.z - p.i.z;
	while (++p.k.x <= 2)
	{
		p.k.y = -2;
		while (++p.k.y <= 2)
		{
			p.k.z = -2;
			while (++p.k.z <= 2)
				xknots[p.k.z + 1] = \
				sr->materialptr->noise.value_table[ft_index(p.i.x \
			+ p.k.z, p.i.y + p.k.y, p.i.z + p.k.x, sr->w)];
			yknots[p.k.y + 1] = four_knot_spline(f.x, xknots);
		}
		zknots[p.k.x + 1] = four_knot_spline(f.y, yknots);
	}
	return (four_knot_spline(f.z, zknots));
}
