/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turbulence.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <anain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 18:00:09 by anain             #+#    #+#             */
/*   Updated: 2018/04/21 23:18:49 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "noise.h"
#include <stdio.h>

#define FS_MAX 10.0
#define NUM_OCTAVES 4.0

float		turbulence(t_shaderec *sr)
{
	float		amplitude;
	float		frequency;
	float		turbulence;
	int			j;
	t_point3d	hit;

	j = -1;
	amplitude = 1.0;
	frequency = 1.0;
	turbulence = 2.0;
	hit = sr->local_hit_point;
	while (++j < NUM_OCTAVES)
	{
		sr->local_hit_point = multpoint(&hit, frequency);
		turbulence += amplitude * fabs(cubic_noise(sr));
		amplitude *= 0.5;
		frequency *= 2.0;
	}
	turbulence /= FS_MAX;
	return (turbulence);
}
