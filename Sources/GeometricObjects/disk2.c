/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disk2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 16:28:49 by asavann           #+#    #+#             */
/*   Updated: 2018/04/22 17:18:59 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disk.h"
#include "libft.h"
#include "constants.h"

void	compute_uvwdisk(t_disk *disk)
{
	disk->w = vector3deqn(&disk->w, disk->normal);
	disk->v = crossproduct(&disk->w, (t_vector3d){0.0072, 1.0, 0.0034});
	normalize(&disk->v);
	disk->u = crossproduct(&disk->v, disk->w);
}

float	disk_pdf(t_object *o, t_shaderec *sr)
{
	if (sr)
		;
	return (o->disk.inv_area);
}

void	set_disk_inv_area(t_disk *disk)
{
	if (disk->k == 1)
		disk->inv_area = 1 / (disk->r_squared * PI);
	else
		disk->inv_area = 1 / disk->k;
}
