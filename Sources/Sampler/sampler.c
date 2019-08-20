/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sampler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 14:24:52 by asavann           #+#    #+#             */
/*   Updated: 2018/04/24 16:57:05 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sampler.h"
#include "camera.h"
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

void		shuffle_x_coordinates(t_sampler *sampler)
{
	int		p;
	int		i;
	int		target;
	float	tmp;

	p = -1;
	while (++p < sampler->num_sets)
	{
		i = -1;
		while (++i < sampler->num_samples - 1)
		{
			target = rand() % sampler->num_samples + p * sampler->num_samples;
			tmp = sampler->samples[i + p * sampler->num_samples + 1].x;
			sampler->samples[i + p * sampler->num_samples + 1].x =\
			sampler->samples[target].x;
			sampler->samples[target].x = tmp;
		}
	}
}

void		shuffle_y_coordinates(t_sampler *sampler)
{
	int		p;
	int		i;
	int		target;
	float	tmp;

	p = -1;
	while (++p < sampler->num_sets)
	{
		i = -1;
		while (++i < sampler->num_samples - 1)
		{
			target = rand() % sampler->num_samples + p * sampler->num_samples;
			tmp = sampler->samples[i + p * sampler->num_samples + 1].y;
			sampler->samples[i + p * sampler->num_samples + 1].y =
			sampler->samples[target].y;
			sampler->samples[target].y = tmp;
		}
	}
}

t_point2d	sample_unit_square(t_sampler *sampler)
{
	t_point2d	sample;
	int			i;

	if (sampler->count % sampler->num_samples == 0)
		sampler->jump = (rand() % sampler->num_sets) * sampler->num_samples;
	i = sampler->shuffled_indices[(sampler->jump +
	sampler->count) % sampler->num_samples];
	sample = sampler->samples[sampler->jump + i];
	sampler->count = sampler->count + 1;
	return (sample);
}

static int	*shuffle_indices(const t_sampler *sampler, int *indices)
{
	size_t	j;
	size_t	i;
	size_t	k;
	int		t;

	j = -1;
	while (++j < (size_t)sampler->num_sets)
	{
		i = -1;
		while (++i < (size_t)sampler->num_samples - 1)
		{
			k = i + rand() / (RAND_MAX / (sampler->num_samples - i) + 1);
			t = indices[k];
			indices[k] = indices[i];
			indices[i] = t;
		}
	}
	return (indices);
}

void		setup_shuffled_indices(t_sampler *sampler)
{
	int	*indices;
	int	j;

	j = -1;
	if (!(sampler->shuffled_indices = (int *)malloc(sizeof(int)
	* sampler->num_samples * sampler->num_sets + 1)))
		exit(EXIT_FAILURE);
	if (!(indices = (int *)malloc(sizeof(int) * sampler->num_samples + 1)))
		exit(EXIT_FAILURE);
	while (++j < sampler->num_samples)
		indices[j] = j;
	indices = shuffle_indices(sampler, indices);
	j = -1;
	while (++j < sampler->num_samples)
		sampler->shuffled_indices[j] = indices[j];
	free(indices);
}
