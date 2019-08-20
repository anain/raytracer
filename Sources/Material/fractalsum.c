/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractalsum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <anain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 15:31:05 by anain             #+#    #+#             */
/*   Updated: 2018/04/21 23:32:54 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "noise.h"
#include <stdio.h>

#define FS_MAX NUM_OCTAVES
#define FS_MIN -NUM_OCTAVES
#define NUM_OCTAVES 6

float			fractalsum(t_shaderec *sr)
{
	float		amplitude;
	float		frequency;
	float		fractalsum;
	int			j;

	j = -1;
	amplitude = 1.0;
	frequency = 1.0;
	fractalsum = 0.0;
	while (++j < NUM_OCTAVES)
	{
		sr->local_hit_point = multpoint(&sr->local_hit_point, frequency);
		fractalsum += amplitude * (cubic_noise(sr));
		amplitude *= 0.5;
		frequency *= 2.0;
	}
	fractalsum = (fractalsum - FS_MIN) / (FS_MAX - FS_MIN);
	return (fractalsum);
}
