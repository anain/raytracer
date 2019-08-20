/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 17:30:47 by asavann           #+#    #+#             */
/*   Updated: 2018/04/24 17:07:08 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disk.h"
#include <stdlib.h>

int			diskhit(const t_object *o, const t_ray ray, double *tmin,\
			t_shaderec *sr)
{
	float		t;
	t_point3d	p;

	t = normaldotproduct(&o->disk.normal, getvector(&o->disk.center, ray.o)) /
	normaldotproduct(&o->disk.normal, ray.d);
	if (t <= o->disk.kepsilon)
		return (0);
	p = addvector(&ray.o, multvector3d(&ray.d, t));
	if (d_squared(&o->disk.center, p) < o->disk.r_squared)
	{
		*tmin = t;
		sr->normal = o->disk.normal;
		sr->local_hit_point = p;
		return (1);
	}
	else
		return (0);
}

int			diskhitshadow(const t_object *o, const t_ray ray, float *tmin)
{
	float		t;
	t_point3d	p;

	t = normaldotproduct(&o->disk.normal, getvector(&o->disk.center, ray.o)) /
	normaldotproduct(&o->disk.normal, ray.d);
	if (t <= o->disk.kepsilon)
		return (0);
	p = addvector(&ray.o, multvector3d(&ray.d, t));
	if (d_squared(&o->disk.center, p) < o->disk.r_squared)
	{
		*tmin = t;
		return (1);
	}
	else
		return (0);
}

void		disk_set_sampler(t_disk *disk, int ns)
{
	disk->sampler.num_samples = ns;
	disk->sampler.num_sets = 83;
	disk->sampler.count = 0;
	disk->sampler.jump = 0;
	if (!(disk->sampler.samples =\
	(t_point2d *)malloc(sizeof(t_point2d) * ns * 83)))
		exit(EXIT_FAILURE);
	generate_multijittered_samples(&disk->sampler);
	setup_shuffled_indices(&disk->sampler);
	map_samples_to_unit_disk(&disk->sampler);
	free(disk->sampler.samples);
}

t_point3d	disk_sample(t_object *o)
{
	t_point2d	sp;
	t_point3d	sp3d;

	sp = sample_unit_disk(&o->disk.sampler);
	sp3d.x = sp.x * o->disk.u.x + sp.y * o->disk.v.x + o->disk.w.x;
	sp3d.y = sp.x * o->disk.u.y + sp.y * o->disk.v.y + o->disk.w.y;
	sp3d.z = sp.x * o->disk.u.z + sp.y * o->disk.v.z + o->disk.w.z;
	return (addpoint(sp3d, o->disk.center));
}

t_normal	disk_get_normal(t_object *o, t_point3d *sp)
{
	if (sp)
		;
	return (o->disk.normal);
}
