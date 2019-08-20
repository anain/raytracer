/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   worldbuild.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 17:18:57 by anain             #+#    #+#             */
/*   Updated: 2018/04/24 15:12:56 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "point3d.h"
#include "world.h"

void	next_child(t_childlst *cur, char *new)
{
	if (!(cur->next = (t_childlst *)malloc(sizeof(t_childlst))))
		ft_error(MALLOC_ERR);
	cur = cur->next;
	cur->child = new;
	cur->next = NULL;
}

void	worldbuild(t_world *w, char *scene)
{
	w->vp.gamma = 1;
	w->light = NULL;
	w->object = NULL;
	w->tracer.t = whitted_trace_ray;
	parser(scene, w);
	w->begin = w->object;
	w->tracer.world_ptr = w;
	w->vp.win_width = w->vp.hres;
	w->vp.win_height = w->vp.vres;
}
