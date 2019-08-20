/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_objects2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorobin <jorobin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:06:23 by jorobin           #+#    #+#             */
/*   Updated: 2018/04/24 22:06:43 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mmlx.h"
#include "matrix.h"

void	move_objects4(int keycode, t_object *o)
{
	t_point3d s;
	t_point3d d;

	if (keycode == U)
	{
		d =
		s = o->d;
		if (o->type == MICKEY)
			rot_mickey(o->compound, 2, 'y');
		else
		{
			translate(o, -o->d.x, -o->d.y, -o->d.z);
			translate_tex(o, -s.x, -s.y, -s.z);
			rotate_y(&o->inv_mat, 2);
			rotate_y(&o->mat.inv_mat, 2);
			translate(o, s.x, s.y, s.z);
			translate_tex(o, s.x, s.y, s.z);
		}
	}
	move_objects5(keycode, o);
}

void	move_objects5(int keycode, t_object *o)
{
	t_point3d s;

	if (keycode == I)
	{
		s = o->d;
		if (o->type == MICKEY)
			rot_mickey(o->compound, -2, 'y');
		else
		{
			translate(o, -o->d.x, -o->d.y, -o->d.z);
			translate_tex(o, -s.x, -s.y, -s.z);
			rotate_y(&o->inv_mat, -2);
			rotate_y(&o->mat.inv_mat, -2);
			translate(o, s.x, s.y, s.z);
			translate_tex(o, s.x, s.y, s.z);
		}
	}
	move_objects6(keycode, o);
}

void	move_objects6(int keycode, t_object *o)
{
	t_point3d s;

	if (keycode == B)
	{
		s = o->d;
		if (o->type == MICKEY)
			rot_mickey(o->compound, 2, 'x');
		else
		{
			translate(o, -o->d.x, -o->d.y, -o->d.z);
			translate_tex(o, -s.x, -s.y, -s.z);
			rotate_x(&o->inv_mat, 2);
			rotate_x(&o->mat.inv_mat, 2);
			translate(o, s.x, s.y, s.z);
			translate_tex(o, s.x, s.y, s.z);
		}
	}
	move_objects7(keycode, o);
}

void	move_objects7(int keycode, t_object *o)
{
	t_point3d s;

	if (keycode == V)
	{
		s = o->d;
		if (o->type == MICKEY)
			rot_mickey(o->compound, -2, 'x');
		else
		{
			translate(o, -o->d.x, -o->d.y, -o->d.z);
			translate_tex(o, -s.x, -s.y, -s.z);
			rotate_x(&o->inv_mat, -2);
			rotate_x(&o->mat.inv_mat, -2);
			translate(o, s.x, s.y, s.z);
			translate_tex(o, s.x, s.y, s.z);
		}
	}
}
