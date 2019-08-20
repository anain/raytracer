/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorobin <jorobin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:06:23 by jorobin           #+#    #+#             */
/*   Updated: 2018/04/23 15:43:21 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mmlx.h"
#include "matrix.h"

void	trans_mickey(t_object *o, int x, int y, int z)
{
	t_object *begin;

	begin = o;
	while (o)
	{
		translate(o, x, y, z);
		o = o->next;
	}
	o = begin;
}

void	rot_mickey(t_object *o, int rot, char dir)
{
	t_object	*begin;
	int			n;
	t_point3d	sav;

	begin = o;
	n = 1;
	sav = o->d;
	while (o)
	{
		translate(o, -o->d.x, -o->d.y, -o->d.z);
		if (dir == 'x')
			rotate_x(&o->inv_mat, rot);
		if (dir == 'y')
			rotate_y(&o->inv_mat, rot);
		translate(o, sav.x, sav.y, sav.z);
		n++;
		o = o->next;
	}
	o = begin;
}

void	move_objects3(int keycode, t_object *o)
{
	if (keycode == 82)
	{
		if (o->type == MICKEY)
			trans_mickey(o->compound, 0, 0, 2);
		else
		{
			translate(o, 0, 0, 2);
			translate_tex(o, 0, 0, 2);
		}
	}
	if (keycode == 65)
	{
		if (o->type == MICKEY)
			trans_mickey(o->compound, 0, 0, -2);
		else
		{
			translate(o, 0, 0, -2);
			translate_tex(o, 0, 0, -2);
		}
	}
	move_objects4(keycode, o);
}

void	move_objects2(int keycode, t_object *o)
{
	if (keycode == DOWN)
	{
		if (o->type == MICKEY)
			trans_mickey(o->compound, 0, -2, 0);
		else
		{
			translate(o, 0, -2, 0);
			translate_tex(o, 0, -2, 0);
		}
	}
	if (keycode == UP)
	{
		if (o->type == MICKEY)
			trans_mickey(o->compound, 0, 2, 0);
		else
		{
			translate(o, 0, 2, 0);
			translate_tex(o, 0, 2, 0);
		}
	}
	move_objects3(keycode, o);
}

void	move_objects(int keycode, t_object *o)
{
	if (keycode == RIGHT)
	{
		if (o->type == MICKEY)
			trans_mickey(o->compound, -2, 0, 0);
		else
		{
			translate(o, -2, 0, 0);
			translate_tex(o, -2, 0, 0);
		}
	}
	if (keycode == LEFT)
	{
		if (o->type == MICKEY)
			trans_mickey(o->compound, 2, 0, 0);
		else
		{
			translate(o, 2, 0, 0);
			translate_tex(o, 2, 0, 0);
		}
	}
	move_objects2(keycode, o);
}
