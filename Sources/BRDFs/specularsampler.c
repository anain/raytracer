/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specularsampler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 15:34:57 by asavann           #+#    #+#             */
/*   Updated: 2018/04/24 17:01:36 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brdf.h"
#include <stdlib.h>

void	set_samplerphong(t_glossyspecular *spec, const int ns)
{
	spec->sampler.num_samples = ns;
	spec->sampler.num_sets = 83;
	spec->sampler.count = 0;
	spec->sampler.jump = 0;
	if (!(spec->sampler.samples =\
	(t_point2d*)malloc(sizeof(t_point2d) * ns * 83)))
		exit(EXIT_FAILURE);
	generate_multijittered_samples(&spec->sampler);
	setup_shuffled_indices(&spec->sampler);
	map_samples_to_hemisphere(&spec->sampler, 1);
	free(spec->sampler.samples);
}
