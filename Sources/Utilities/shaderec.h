/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shaderec.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:06:56 by asavann           #+#    #+#             */
/*   Updated: 2018/04/23 15:31:53 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADEREC_H
# define SHADEREC_H

# include "point3d.h"
# include "normal.h"
# include "ray.h"
# include "rgbcolor.h"

typedef struct s_material	t_material;
typedef struct s_world		t_world;
typedef struct s_object		t_object;

typedef struct	s_shaderec
{
	int			hit_an_object;
	t_material	*materialptr;
	t_point3d	hit_point;
	t_point3d	local_hit_point;
	t_normal	normal;
	t_ray		ray;
	int			depth;
	float		t;
	float		u;
	float		v;
	t_world		*w;
	t_rgbcolor	saved_color;
	float		ndotwi;
	int			compound;
	t_object	*hitobj;
}				t_shaderec;

/*
** Constructor
*/

void			shaderecinit(t_shaderec *r, t_world *wr);

/*
** Copy constructor
*/

void			shadereccpy(t_shaderec *sr, const t_shaderec rhs);
#endif
