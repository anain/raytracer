/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:12:30 by asavann           #+#    #+#             */
/*   Updated: 2018/04/24 16:13:59 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "vector3d.h"
# include "point3d.h"
# include "viewplane.h"
# include "rgbcolor.h"
# include "ray.h"
# include <pthread.h>
# define NBTHREAD 8

extern pthread_mutex_t	g_lock;

typedef struct s_world	t_world;

typedef struct	s_rendervar
{
	t_rgbcolor	pixel_color;
	t_ray		ray;
	t_point2d	pix_per_case;
	t_point2d	resolution;
	t_point2d	screen;
	t_point3d	first_3dpix;
	t_point3d	cur3dpix;
	int			p1;
	int			q;
	int			hres;
	int			vres;
	float		s;
	float		zw;
	int			n;
	int			depth;
	t_viewplane	vp;
}				t_rendervar;

typedef struct s_param	t_param;

typedef struct	s_pinhole
{
	float	d;
	float	zoom;
}				t_pinhole;

typedef struct	s_camera
{
	t_point3d	eye;
	t_point3d	look_at;
	double		eye_lookat_dist;
	float		ra;
	t_vector3d	u;
	t_vector3d	v;
	t_vector3d	w;
	t_vector3d	up;
	void		(*cam)(t_param *);
	t_pinhole	pin;

}				t_camera;

typedef struct	s_thread
{
	int			i;
	float		*per;
	t_param		*p;
	int			*tab;
}				t_thread;

void			th_render(t_param *p);
void			compute_uvw(t_camera *cam);
void			compute_uvw2(t_camera *cam);
void			render(t_thread *t);
void			deepfree(t_world *w);
void			deepcpy(t_world *w);
#endif
