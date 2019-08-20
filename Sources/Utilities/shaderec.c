/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shaderec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:07:01 by asavann           #+#    #+#             */
/*   Updated: 2018/04/22 15:44:42 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shaderec.h"

void	shaderecinit(t_shaderec *r, t_world *wr)
{
	r->hit_an_object = 0;
	point3dinit(&r->hit_point);
	point3dinit(&r->local_hit_point);
	normalinit(&r->normal);
	rayinit(&r->ray);
	r->depth = 0;
	r->t = 0.0;
	r->w = wr;
}

void	shadereccpy(t_shaderec *sr, const t_shaderec rhs)
{
	sr->hit_an_object = rhs.hit_an_object;
	sr->materialptr = rhs.materialptr;
	point3dcpy(&sr->hit_point, rhs.hit_point);
	point3dcpy(&sr->local_hit_point, rhs.local_hit_point);
	copynormal(&sr->normal, rhs.normal);
	raycopy(&sr->ray, rhs.ray);
	sr->depth = rhs.depth;
	sr->t = rhs.t;
	sr->w = rhs.w;
}
