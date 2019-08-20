/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_mapping.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <anain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:44:50 by anain             #+#    #+#             */
/*   Updated: 2018/04/23 15:57:26 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mmlx.h"
#include <math.h>
#include "point3d.h"
#include <unistd.h>
#include "constants.h"

t_rgbcolor		basic_mapping(t_shaderec *sr)
{
	return (sr->saved_color);
}

t_rgbcolor		sphere_mapping(t_shaderec *sr)
{
	int			row;
	int			column;
	float		theta;
	float		phi;
	t_point3d	hit;

	hit = point3dmultmat(sr->materialptr->inv_mat, sr->hit_point);
	theta = acos(hit.y);
	phi = atan2(hit.x, hit.z);
	if (phi < 0.0f)
		phi += TWOPI;
	sr->u = phi / TWOPI;
	sr->v = 1.0f - theta / PI;
	column = fabs(fmod((int)(sr->v * (sr->materialptr->tex.marb_sizey - 1)), \
	sr->materialptr->tex.marb_sizey));
	row = fabs(fmod((int)(sr->u * (sr->materialptr->tex.marb_sizex - 1)), \
	sr->materialptr->tex.marb_sizey));
	return (get_texture_pix(sr->materialptr, row, column));
}

t_rgbcolor		probe_mapping(t_shaderec *sr)
{
	float		d;
	t_point3d	hit;
	int			column;
	int			row;

	hit = point3dmultmat(sr->materialptr->inv_mat, sr->hit_point);
	d = sqrt(hit.x * hit.x + hit.y * hit.y);
	d = acos(hit.z) / PI;
	sr->u = (1.0 + d * hit.x / d) * 0.5;
	sr->v = (1.0 + d * hit.y / d) * 0.5;
	column = fabs(fmod((int)(sr->v * (sr->materialptr->tex.marb_sizey - 1)), \
	sr->materialptr->tex.marb_sizey));
	row = fabs(fmod((int)(sr->u * (sr->materialptr->tex.marb_sizex - 1)), \
	sr->materialptr->tex.marb_sizex));
	return (get_texture_pix(sr->materialptr, row, column));
}

t_rgbcolor		cylindrical_mapping(t_shaderec *sr)
{
	int			row;
	int			column;
	float		phi;
	t_point3d	hit;

	hit = point3dmultmat(sr->materialptr->inv_mat, sr->hit_point);
	phi = atan2(hit.x, hit.z);
	sr->u = phi / (2 * M_PI);
	sr->v = (hit.y + 1) / 2;
	column = fabs(fmod((int)(sr->v * (sr->materialptr->tex.marb_sizey - 1)), \
	sr->materialptr->tex.marb_sizey));
	row = fabs(fmod((int)(sr->u * (sr->materialptr->tex.marb_sizex - 1)), \
	sr->materialptr->tex.marb_sizex));
	return (get_texture_pix(sr->materialptr, row, column));
}

t_rgbcolor		rectangular_mapping(t_shaderec *sr)
{
	int			row;
	int			column;
	t_point3d	hit;

	hit = point3dmultmat(sr->materialptr->inv_mat, sr->hit_point);
	sr->u = (hit.x) / sr->hitobj->rectangle.len_b;
	sr->v = (hit.y) / sr->hitobj->rectangle.len_a;
	column = fabs(fmod((int)(sr->v * (sr->materialptr->tex.marb_sizey - 1)), \
	sr->materialptr->tex.marb_sizey));
	row = fabs(fmod((int)(sr->u * (sr->materialptr->tex.marb_sizex - 1)), \
	sr->materialptr->tex.marb_sizex));
	return (get_texture_pix(sr->materialptr, row, column));
}
