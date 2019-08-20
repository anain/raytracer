/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_noise.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <anain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 18:11:04 by anain             #+#    #+#             */
/*   Updated: 2018/04/22 14:44:01 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "noise.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "mmlx.h"

#define MIN_VALUE 0
#define MAX_VALUE 0.8
#define COEF 1

int			perm(int k, t_world *w)
{
	return (w->permt[(k) & KTABLEMASK]);
}

int			ft_index(int ix, int iy, int iz, t_world *w)
{
	return (perm((ix) + perm((iy) + perm(iz, w), w), w));
}

void		init_value_table(t_latticenoise *latticenoise)
{
	int i;

	i = -1;
	srand(253);
	while (++i < KTABLESIZE)
		latticenoise->value_table[i] = 1.0 - 2.0 * rand_float();
}

float		lerp1(float x, float a, float b)
{
	return (a + x * (b - a));
}

t_rgbcolor	set_noise(t_shaderec *sr)
{
	float			value;
	t_rgbcolor		l;

	l = sr->saved_color;
	value = sr->materialptr->fnoise(sr);
	l = rgbmult(&l, value);
	if (value < 0.0 || value > 1.0)
		return (max_to_one(l));
	else
		return (l);
}
