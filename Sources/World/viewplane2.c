/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewplane2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 19:08:55 by asavann           #+#    #+#             */
/*   Updated: 2018/04/25 01:20:52 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "viewplane.h"
#include <stdlib.h>

void			set_size(t_viewplane *v, const float s)
{
	v->s = s;
}

void			set_sample(t_viewplane *v, const int n)
{
	v->numsamples = n;
	v->sampler.num_samples = n;
	v->sampler.num_sets = 83;
	v->sampler.count = 0;
	v->sampler.jump = 0;
	if (!(v->sampler.samples = malloc(sizeof(t_point2d) * n * 83)))
		exit(EXIT_FAILURE);
	setup_shuffled_indices(&v->sampler);
	if (n == 1)
		generate_regular_sample(&v->sampler);
	else
		generate_multijittered_samples(&v->sampler);
}

void			set_gamma(t_viewplane *v, const float gamma)
{
	v->gamma = gamma;
	v->invgamma = 1 / gamma;
}

void			set_gamut(t_viewplane *v, const int show_out_of_gamut)
{
	v->show_out_of_gamut = show_out_of_gamut;
}
