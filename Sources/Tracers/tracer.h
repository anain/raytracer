/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:05:33 by asavann           #+#    #+#             */
/*   Updated: 2018/04/23 16:35:34 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACER_H
# define TRACER_H

# define BLACK (t_rgbcolor){0, 0, 0}

# include "ray.h"
# include "rgbcolor.h"
# include "geometricobjects.h"

typedef struct s_world		t_world;
typedef struct s_shaderec	t_shaderec;
typedef struct	s_tracer
{
	t_world		*world_ptr;
	t_rgbcolor	(*t)(struct s_tracer *, const t_ray, int);
}				t_tracer;

t_rgbcolor		trace_singlesphere(const t_tracer *t, const t_ray ray);
t_rgbcolor		trace_ray(const t_tracer *t, const t_ray ray, int depth);
t_rgbcolor		whitted_trace_ray(t_tracer *t, const t_ray ray, int depth);
t_rgbcolor		path_trace(t_tracer *t, const t_ray ray, int depth);

#endif
