/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multijittered.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 17:08:12 by asavann           #+#    #+#             */
/*   Updated: 2018/02/21 19:30:14 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sampler.h"
#include <stdio.h>

static void	shuffle_coordinate_x_multijittered(t_sampler *sampler, int n)
{
	int		p;
	int		i;
	int		j;
	int		k;
	float	t;

	p = -1;
	while (++p < sampler->num_sets)
	{
		i = -1;
		while (++i < n)
		{
			j = -1;
			while (++j < n)
			{
				k = rand_arg(j, n - 1);
				t = sampler->samples[i * n + j + p * sampler->num_samples].x;
				sampler->samples[i * n + j + p * sampler->num_samples].x =\
				sampler->samples[i * n + k + p * sampler->num_samples].x;
				sampler->samples[i * n + k + p * sampler->num_samples].x = t;
			}
		}
	}
}

static void	shuffle_coordinate_y_multijittered(t_sampler *sampler, int n)
{
	int		p;
	int		i;
	int		j;
	int		k;
	float	t;

	p = -1;
	while (++p < sampler->num_sets)
	{
		i = -1;
		while (++i < n)
		{
			j = -1;
			while (++j < n)
			{
				k = rand_arg(j, n - 1);
				t = sampler->samples[i * n + j + p * sampler->num_samples].y;
				sampler->samples[i * n + j + p * sampler->num_samples].y =\
				sampler->samples[i * n + k + p * sampler->num_samples].y;
				sampler->samples[i * n + k + p * sampler->num_samples].y = t;
			}
		}
	}
}

static void	initsampler(t_sampler *sampler, int n, float subcell_width)
{
	int	p;
	int	i;
	int	j;

	p = -1;
	while (++p < sampler->num_sets)
	{
		i = -1;
		while (++i < n)
		{
			j = -1;
			while (++j < n)
			{
				sampler->samples[i * n + j + p *\
				sampler->num_samples].x =\
				(i * n + j) * subcell_width + rand_floatarg(0, subcell_width);
				sampler->samples[i * n + j + p *\
				sampler->num_samples].y =\
				(j * n + i) * subcell_width + rand_floatarg(0, subcell_width);
			}
		}
	}
}

void		generate_multijittered_samples(t_sampler *sampler)
{
	int		n;
	float	subcell_width;
	int		p;

	n = (int)sqrt((float)sampler->num_samples);
	subcell_width = 1.0 / ((float)sampler->num_samples);
	p = -1;
	initsampler(sampler, n, subcell_width);
	shuffle_coordinate_x_multijittered(sampler, n);
	shuffle_coordinate_y_multijittered(sampler, n);
}
