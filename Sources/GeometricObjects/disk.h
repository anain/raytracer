/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disk.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 17:31:26 by asavann           #+#    #+#             */
/*   Updated: 2018/04/22 17:18:34 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISK_H
# define DISK_H
# include "geometricobjects.h"

int			diskhit(const t_object *o, const t_ray ray, double *tmin, \
				t_shaderec *sr);
int			diskhitshadow(const t_object *o, const t_ray ray, float *tmin);
t_point3d	disk_sample(t_object *o);
t_normal	disk_get_normal(t_object *o, t_point3d *sp);
void		disk_set_sampler(t_disk *disk, int ns);
float		disk_pdf(t_object *o, t_shaderec *sr);
void		compute_uvwdisk(t_disk *disk);
void		set_disk_inv_area(t_disk *disk);

#endif
