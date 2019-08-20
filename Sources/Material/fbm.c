/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fbm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <anain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 18:33:41 by anain             #+#    #+#             */
/*   Updated: 2018/04/21 23:32:21 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "noise.h"
#include <stdio.h>

#define FBM_MAX 10.0
#define FBM_MIN 0.0
#define LACUNARITY 2
#define GAIN 0.5
#define EXPANSION 15.0
#define NUM_OCTAVES 6.0

float			fbm(t_shaderec *sr)
{
	float		amplitude;
	float		frequency;
	float		fbm;
	int			j;
	t_point3d	hit;

	j = -1;
	amplitude = 1.0;
	frequency = 1.0;
	fbm = 0.0;
	hit = point3dmultmat(sr->materialptr->inv_mat, sr->local_hit_point);
	while (++j < NUM_OCTAVES)
	{
		sr->local_hit_point = multpoint(&hit, frequency);
		fbm += amplitude * (linear_noise(sr));
		amplitude *= GAIN;
		frequency *= LACUNARITY;
	}
	fbm = (fbm - FBM_MIN) / (FBM_MAX - FBM_MIN);
	fbm = EXPANSION * fbm;
	return (fbm - ft_floor(fbm));
}
