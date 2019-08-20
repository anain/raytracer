/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boxes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 17:26:47 by anain             #+#    #+#             */
/*   Updated: 2018/03/09 16:33:47 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "box.h"

void	init_points(t_point3d *or, t_point3d *param, const t_ray ray)
{
	or->x = ray.o.x;
	or->y = ray.o.y;
	or->z = ray.o.z;
	param->x = 1.0 / ray.d.x;
	param->y = 1.0 / ray.d.y;
	param->z = 1.0 / ray.d.z;
}

void	init_val_x(t_tminmax *t, const t_box *box, double or, double param)
{
	if (param > 0)
	{
		t->min.x = (box->lim.x0 - or) * param;
		t->max.x = (box->lim.x1 - or) * param;
	}
	else
	{
		t->min.x = (box->lim.x1 - or) * param;
		t->max.x = (box->lim.x0 - or) * param;
	}
}

void	init_val_y(t_tminmax *t, const t_box *box, double or, double param)
{
	if (param > 0)
	{
		t->min.y = (box->lim.y0 - or) * param;
		t->max.y = (box->lim.y1 - or) * param;
	}
	else
	{
		t->min.y = (box->lim.y1 - or) * param;
		t->max.y = (box->lim.y0 - or) * param;
	}
}

void	init_val_z(t_tminmax *t, const t_box *box, double or, double param)
{
	if (param > 0)
	{
		t->min.z = (box->lim.z0 - or) * param;
		t->max.z = (box->lim.z1 - or) * param;
	}
	else
	{
		t->min.z = (box->lim.z1 - or) * param;
		t->max.z = (box->lim.z0 - or) * param;
	}
}

void	init_val(t_tminmax *t, const t_box *box, t_point3d *param, \
		const t_ray ray)
{
	t_point3d or;

	init_points(&or, param, ray);
	init_val_x(t, box, or.x, param->x);
	init_val_y(t, box, or.y, param->y);
	init_val_z(t, box, or.z, param->z);
}
