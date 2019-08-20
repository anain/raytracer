/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regular.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 17:46:59 by asavann           #+#    #+#             */
/*   Updated: 2018/02/20 14:00:18 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sampler.h"
#include "point2d.h"
#include <math.h>
#include <stdio.h>

void	generate_regular_sample(t_sampler *sampler)
{
	int n;
	int p;
	int k;
	int j;
	int i;

	p = -1;
	i = 0;
	n = sqrt(sampler->num_samples);
	while (++p < sampler->num_sets)
	{
		j = -1;
		while (++j < n)
		{
			k = -1;
			while (++k < n)
			{
				point2dsetvalue(&sampler->samples[i],\
				(k + 0.5) / n, (j + 0.5) / n);
				i++;
			}
		}
	}
}
