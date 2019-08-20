/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sampler2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 14:34:48 by asavann           #+#    #+#             */
/*   Updated: 2018/04/25 01:15:18 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sampler.h"
#include "camera.h"
#include "maths.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

t_point2d		sample_unit_disk(t_sampler *sampler)
{
	t_point2d	sample;
	int			i;

	if (sampler->count % sampler->num_samples == 0)
		sampler->jump = (rand() % sampler->num_sets) * sampler->num_samples;
	i = sampler->shuffled_indices[(sampler->jump +
	sampler->count) % sampler->num_samples];
	sample = sampler->disk_samples[sampler->jump + i];
	sampler->count = sampler->count + 1;
	return (sample);
}

t_point3d		sample_unit_hemishpere(t_sampler *sampler)
{
	t_point3d		sample;
	int				i;

	if (sampler->count % sampler->num_samples == 0)
		sampler->jump = (rand() % sampler->num_sets) * sampler->num_samples;
	i = sampler->shuffled_indices[(sampler->jump +
	sampler->count) % sampler->num_samples];
	sample = sampler->hemisphere_samples[sampler->jump + i];
	sampler->count = sampler->count + 1;
	return (sample);
}

t_point3d		sample_unit_sphere(t_sampler *sampler)
{
	t_point3d		sample;
	int				i;

	if (sampler->count % sampler->num_samples == 0)
		sampler->jump = (rand() % sampler->num_sets) * sampler->num_samples;
	i = sampler->shuffled_indices[(sampler->jump +
	sampler->count) % sampler->num_samples];
	sample = sampler->sphere_samples[sampler->jump + i];
	sampler->count = sampler->count + 1;
	return (sample);
}
