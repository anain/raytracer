/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sampler.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 14:06:42 by asavann           #+#    #+#             */
/*   Updated: 2018/04/18 16:08:59 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLER_H
# define SAMPLER_H

# include <math.h>
# include "point2d.h"
# include "point3d.h"
# include "maths.h"
# include <pthread.h>
# include <stdatomic.h>

typedef struct	s_sampler
{
	int				num_samples;
	int				num_sets;
	t_point2d		*samples;
	t_point2d		*disk_samples;
	t_point3d		*hemisphere_samples;
	t_point3d		*sphere_samples;
	int				*shuffled_indices;
	atomic_long		count;
	atomic_int		jump;
	pthread_mutex_t lock;
}				t_sampler;

void			shuffle_x_coordinates(t_sampler *sampler);
void			shuffle_y_coordinates(t_sampler *sampler);
t_point2d		sample_unit_square(t_sampler *sampler);
t_point2d		sample_unit_disk(t_sampler *sampler);
t_point3d		sample_unit_hemishpere(t_sampler *sampler);
t_point3d		sample_unit_sphere(t_sampler *sampler);
void			setup_shuffled_indices(t_sampler *sampler);
void			generate_regular_sample(t_sampler *sampler);
void			generate_multijittered_samples(t_sampler *sampler);
void			map_samples_to_unit_disk(t_sampler *sampler);
void			map_samples_to_hemisphere(t_sampler *sampler, const float e);
void			map_sample_to_sphere(t_sampler *sampler);

#endif
