/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:53:55 by asavann           #+#    #+#             */
/*   Updated: 2018/04/18 17:12:06 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "vector3d.h"
# include "rgbcolor.h"
# include "point3d.h"
# include "shaderec.h"
# include "sampler.h"
# include "geometricobjects.h"

typedef struct	s_environmentlight
{
	t_sampler	sampler;
	t_material	*materialptr;
	t_vector3d	u;
	t_vector3d	v;
	t_vector3d	w;
	t_vector3d	wi;
}				t_environmentlight;

typedef struct	s_spot
{
	float		ls;
	t_rgbcolor	color;
	t_point3d	location;
}				t_spot;

typedef struct	s_ambient
{
	float		ls;
	t_rgbcolor	color;
}				t_ambient;

typedef struct	s_directional
{
	float		ls;
	t_vector3d	dir;
	t_rgbcolor	color;
}				t_directional;

typedef struct	s_ambientoccluder
{
	float		ls;
	t_vector3d	u;
	t_vector3d	v;
	t_vector3d	w;
	t_sampler	sampler;
	t_rgbcolor	c;
	float		min_amount;
}				t_ambientoccluder;

typedef struct	s_arealight
{
	t_object	object;
	t_material	*material;
	t_point3d	sample_point;
	t_normal	light_normal;
	t_vector3d	wi;
}				t_arealight;

typedef struct	s_light
{
	int					shadow;
	t_directional		dlight;
	t_spot				spot;
	t_arealight			arealight;
	t_environmentlight	el;
	t_vector3d			(*get_direction)(struct s_light *, t_shaderec *);
	t_rgbcolor			(*l)(struct s_light *, t_shaderec *);
	int					(*in_shadow)(const struct s_light *, t_ray, t_shaderec);
	float				(*g)(struct s_light *, t_shaderec *);
	float				(*pdf)(struct s_light *, t_shaderec *);
	struct s_light		*next;
}				t_light;

#endif
