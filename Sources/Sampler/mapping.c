/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 13:14:35 by asavann           #+#    #+#             */
/*   Updated: 2018/04/24 17:06:15 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sampler.h"
#include "constants.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

static void		get_phi_and_r2(t_point2d sp, float *phi, float *r)
{
	if (sp.x < sp.y)
	{
		*r = -sp.x;
		*phi = 4.0f + (sp.y / sp.x);
	}
	else
	{
		*r = -sp.y;
		if (sp.y != 0)
			*phi = 6.0f - (sp.x / sp.y);
		else
			*phi = 0.0f;
	}
}

static void		get_phi_and_r(t_point2d sp, float *phi, float *r)
{
	if (sp.x > -sp.y)
	{
		if (sp.x > sp.y)
		{
			*r = sp.x;
			*phi = sp.y / sp.x;
		}
		else
		{
			*r = sp.y;
			*phi = 2.0f - (sp.x / sp.y);
		}
	}
	else
		get_phi_and_r2(sp, phi, r);
	*phi *= M_PI / 4.0f;
}

void			map_samples_to_unit_disk(t_sampler *sampler)
{
	int			size;
	float		r;
	float		phi;
	t_point2d	sp;
	int			j;

	size = sampler->num_samples * sampler->num_sets;
	if (!(sampler->disk_samples = \
		(t_point2d *)malloc(sizeof(t_point2d) * size)))
		exit(EXIT_FAILURE);
	j = -1;
	while (++j < size)
	{
		sp.x = 2.0f * sampler->samples[j].x - 1.0f;
		sp.y = 2.0f * sampler->samples[j].y - 1.0f;
		get_phi_and_r(sp, &r, &phi);
		sampler->disk_samples[j].x = r * cos(phi);
		sampler->disk_samples[j].y = r * sin(phi);
	}
}

void			map_samples_to_hemisphere(t_sampler *sampler, const float e)
{
	float	cos_theta;
	float	sin_theta;
	int		j;
	int		size;

	size = sampler->num_samples * sampler->num_sets;
	if (!(sampler->hemisphere_samples =\
	(t_point3d *)malloc(sizeof(t_point3d) * size)))
		exit(EXIT_FAILURE);
	j = -1;
	while (++j < size)
	{
		cos_theta = pow(1 - sampler->samples[j].y, 1 / (e + 1));
		sin_theta = sqrt(1 - cos_theta * cos_theta);
		point3dsetvalue(&sampler->hemisphere_samples[j],
		sin_theta * cos(2.0 * M_PI * sampler->samples[j].x),
		sin_theta * sin(2.0 * M_PI * sampler->samples[j].x), cos_theta);
	}
}

void			map_sample_to_sphere(t_sampler *sampler)
{
	float		r;
	t_point3d	sphere_sample;
	float		phi;
	int			j;
	int			size;

	size = sampler->num_samples * sampler->num_sets;
	if (!(sampler->sphere_samples =\
	(t_point3d *)malloc(sizeof(t_point3d) * size)))
		exit(EXIT_FAILURE);
	j = -1;
	while (++j < size)
	{
		sphere_sample.z = 1.0 - 2.0 * sampler->samples[j].x;
		r = sqrt(1.0 - sphere_sample.z * sphere_sample.z);
		phi = TWOPI * sampler->samples[j].y;
		sphere_sample.x = r * cos(phi);
		sphere_sample.y = r * sin(phi);
		sampler->sphere_samples[j] = sphere_sample;
	}
}
