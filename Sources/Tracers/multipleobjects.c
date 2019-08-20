/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multipleobjects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 20:16:42 by asavann           #+#    #+#             */
/*   Updated: 2018/04/22 15:19:09 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracer.h"
#include "world.h"
#include "shaderec.h"
#include "material.h"
#include <stdio.h>

t_rgbcolor	whitted_trace_ray(t_tracer *t, const t_ray ray, int depth)
{
	t_shaderec sr;

	if (depth > t->world_ptr->vp.max_depth)
		return (BLACK);
	else
	{
		sr = hit_objects(t->world_ptr, ray);
		t->world_ptr->sr = &sr;
		if (sr.hit_an_object == 1)
		{
			sr.depth = depth;
			sr.ray = ray;
			return (sr.materialptr->shade(sr.materialptr, &sr));
		}
		else
		{
			return (t->world_ptr->vp.background_color);
		}
	}
}

t_rgbcolor	path_trace(t_tracer *t, const t_ray ray, int depth)
{
	t_shaderec sr;

	if (depth > t->world_ptr->vp.max_depth)
		return (BLACK);
	else
	{
		sr = hit_objects(t->world_ptr, ray);
		if (sr.hit_an_object == 1)
		{
			sr.depth = depth;
			sr.ray = ray;
			return (sr.materialptr->path_shade(sr.materialptr, &sr));
		}
		else
			return (t->world_ptr->backgroundcolor);
	}
}
