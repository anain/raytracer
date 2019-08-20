/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:06:30 by jorobin           #+#    #+#             */
/*   Updated: 2018/04/21 19:34:55 by jorobin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mmlx.h"
#include "matrix.h"

void	rot_camera2(int keycode, t_param *e)
{
	t_point3d mult;

	if (keycode == G)
	{
		e->world.camera.w = prod_vec3_matrx4(e->world.camera.w, roty_matrx4(1));
		mult = multvecdouble(&e->world.camera.w,\
				-e->world.camera.eye_lookat_dist);
		e->world.camera.look_at = addpoint(e->world.camera.eye, mult);
		compute_uvw(&e->world.camera);
	}
	if (keycode == J)
	{
		e->world.camera.w = prod_vec3_matrx4(e->world.camera.w,\
				roty_matrx4(-1));
		mult = multvecdouble(&e->world.camera.w,\
				-e->world.camera.eye_lookat_dist);
		e->world.camera.look_at = addpoint(e->world.camera.eye, mult);
		compute_uvw(&e->world.camera);
	}
}

void	rot_camera(int keycode, t_param *e)
{
	t_point3d mult;

	if (keycode == Y)
	{
		e->world.camera.w = prod_vec3_matrx4(e->world.camera.w, rotx_matrx4(1));
		mult = multvecdouble(&e->world.camera.w,\
				-e->world.camera.eye_lookat_dist);
		e->world.camera.look_at = addpoint(e->world.camera.eye, mult);
		compute_uvw(&e->world.camera);
	}
	if (keycode == H)
	{
		e->world.camera.w = prod_vec3_matrx4(e->world.camera.w,\
				rotx_matrx4(-1));
		mult = multvecdouble(&e->world.camera.w,\
				-e->world.camera.eye_lookat_dist);
		e->world.camera.look_at = addpoint(e->world.camera.eye, mult);
		compute_uvw(&e->world.camera);
	}
	rot_camera2(keycode, e);
}

void	move_camera3(int keycode, t_param *e)
{
	if (keycode == Q)
	{
		e->world.camera.eye = addvector(&e->world.camera.eye,\
				multvector3d(&e->world.camera.v, 10));
		e->world.camera.look_at = addvector(&e->world.camera.look_at,\
				e->world.camera.v);
	}
}

void	move_camera2(int keycode, t_param *e)
{
	if (keycode == D)
	{
		e->world.camera.eye = addvector(&e->world.camera.eye,\
				multvector3d(&e->world.camera.u, 10));
		e->world.camera.look_at = addvector(&e->world.camera.look_at,\
				e->world.camera.v);
	}
	if (keycode == Z)
	{
		e->world.camera.eye = subvector(&e->world.camera.eye,\
				multvector3d(&e->world.camera.v, 10));
		e->world.camera.look_at = subvector(&e->world.camera.look_at,\
				e->world.camera.v);
	}
	move_camera3(keycode, e);
	if (keycode == R)
		e->world.camera.pin.d += 200;
	if (keycode == F)
		e->world.camera.pin.d -= 200;
}

void	move_camera(int keycode, t_param *e)
{
	if (keycode == W)
	{
		e->world.camera.eye = subvector(&e->world.camera.eye,\
				multvector3d(&e->world.camera.w, 10));
		e->world.camera.look_at = subvector(&e->world.camera.look_at,\
				e->world.camera.w);
	}
	if (keycode == S)
	{
		e->world.camera.eye = addvector(&e->world.camera.eye,\
				multvector3d(&e->world.camera.w, 10));
		e->world.camera.look_at = addvector(&e->world.camera.look_at,\
				e->world.camera.w);
	}
	if (keycode == A)
	{
		e->world.camera.eye = subvector(&e->world.camera.eye,\
				multvector3d(&e->world.camera.u, 10));
		e->world.camera.look_at = subvector(&e->world.camera.look_at,\
				e->world.camera.v);
	}
	move_camera2(keycode, e);
	rot_camera(keycode, e);
}
