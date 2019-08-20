/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:41:45 by asavann           #+#    #+#             */
/*   Updated: 2018/04/24 17:52:10 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

# include "viewplane.h"
# include "rgbcolor.h"
# include "tracer.h"
# include "geometricobjects.h"
# include "sphere.h"
# include "ray.h"
# include "plane.h"
# include "camera.h"
# include "light.h"
# include "opencylinder.h"
# include "infcone.h"
# include "constants.h"
# include "ambient.h"
# include "spot.h"
# include "directional.h"
# include "matte.h"
# include "phong.h"
# include <stdio.h>
# include <stdlib.h>
# include "reflective.h"
# include "transparence.h"
# include "ambientoccluder.h"
# include "box.h"

typedef struct			s_wvar
{
	t_shaderec			sr;
	double				t;
	double				tmin;
	t_normal			normal;
	t_point3d			local_hit_point;
	t_object			*head;
}						t_wvar;

typedef struct			s_world
{
	t_viewplane			vp;
	t_rgbcolor			backgroundcolor;
	t_object			*object;
	t_tracer			tracer;
	t_camera			camera;
	t_ambient			amb;
	t_ambientoccluder	ao;
	t_shaderec			*sr;
	t_vector3d			cam_rot;
	t_object			*begin;
	t_light				*light;
	char				**objnames;
	t_rgbcolor			(*ambient)(struct s_world*, t_shaderec *);
	int					permt[256];

}						t_world;

t_shaderec				hit_objects(t_world *wr, const t_ray ray);
#endif
