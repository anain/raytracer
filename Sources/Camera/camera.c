/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 19:09:34 by asavann           #+#    #+#             */
/*   Updated: 2018/04/22 14:54:26 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

void	set_up(t_camera *cam, double x, double y, double z)
{
	vector3dsetvalue(&cam->up, x, y, z);
}

void	compute_uvw(t_camera *cam)
{
	cam->w = getvector(&cam->eye, cam->look_at);
	normalize(&cam->w);
	cam->u = crossproduct(&cam->up, cam->w);
	normalize(&cam->u);
	cam->v = crossproduct(&cam->w, cam->u);
	if (cam->eye.x == cam->look_at.x && cam->eye.z == cam->look_at.z \
		&& cam->eye.y > cam->look_at.y)
	{
		vector3dsetvalue(&cam->u, 0, 0, 1);
		vector3dsetvalue(&cam->v, 1, 0, 0);
		vector3dsetvalue(&cam->w, 0, 1, 0);
	}
	if (cam->eye.x == cam->look_at.x && cam->eye.z == cam->look_at.z \
		&& cam->eye.y < cam->look_at.y)
	{
		vector3dsetvalue(&cam->u, 1, 0, 0);
		vector3dsetvalue(&cam->v, 0, 0, 1);
		vector3dsetvalue(&cam->w, 0, -1, 0);
	}
}
