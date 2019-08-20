/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:09:01 by jorobin           #+#    #+#             */
/*   Updated: 2018/04/24 17:43:42 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mmlx.h"
#include "matrix.h"

int		expose(t_param *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	if (!e->menu)
		mlx_string_put(e->mlx, e->win, (e->v.vp.win_width / 10), \
		(e->v.vp.win_height / 10), 0X990000, "MENU : M");
	if (!e->menobj)
		mlx_string_put(e->mlx, e->win, (e->v.vp.win_width / 10 * 7),\
		(e->v.vp.win_height / 10), 0X990000, "OBJ MENU : O");
	mlx_string_put(e->mlx, e->win, (e->v.vp.win_width / 4) * 3,\
		(e->v.vp.win_height / 10) * 9, 0X990000, "QUITTER");
	if (e->menobj == 1)
		print_obj_menu(e);
	if (e->menu == 1)
		print_menu(e);
	return (0);
}

int		redraw(t_param *e)
{
	ft_bzero(e->data, e->v.vp.win_width * e->v.vp.win_height * 4);
	th_render(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	if (!e->menu)
		mlx_string_put(e->mlx, e->win, (e->v.vp.win_width / 10),\
		(e->v.vp.win_height / 10), 0X990000, "MENU : M");
	if (!e->menobj)
		mlx_string_put(e->mlx, e->win, (e->v.vp.win_width / 10 * 7),\
		(e->v.vp.win_height / 10), 0X990000, "OBJ MENU : O");
	mlx_string_put(e->mlx, e->win, (e->v.vp.win_width / 4) * 3,\
	(e->v.vp.win_height / 10) * 9, 0X990000, "QUITTER");
	if (e->menobj == 1)
		print_obj_menu(e);
	if (e->menu)
		print_menu(e);
	return (0);
}

int		input_config2(int keycode, t_param *e, t_object *temp)
{
	if (keycode == O)
	{
		e->menobj = (e->menobj > 0 ? 0 : 1);
		expose(e);
		return (0);
	}
	if (keycode == F6)
		e->filter = (e->filter == 3 ? 0 : e->filter + 1);
	if (keycode == F5)
	{
		fill_screencap(e);
		expose(e);
		return (0);
	}
	move_camera(keycode, e);
	move_objects(keycode, temp);
	if (keycode == ESC)
		ft_exit(e);
	change_res(keycode, e);
	e->world.object = temp;
	return (1);
}

int		input_config(int keycode, t_param *e)
{
	t_object	*temp;

	temp = e->world.object;
	if (keycode == N)
	{
		if (temp == NULL || temp->next == NULL)
		{
			e->world.object = e->world.begin;
			temp = e->world.object;
		}
		else
			temp = temp->next;
	}
	if (keycode == M)
	{
		e->menu = (e->menu > 0 ? 0 : 1);
		expose(e);
		return (0);
	}
	if (!(input_config2(keycode, e, temp)))
		return (0);
	redraw(e);
	return (0);
}

void	loop_minilibx(t_param *e)
{
	mlx_mouse_hook(e->win, mouse_input, e);
	mlx_hook(e->win, 2, 0, input_config, e);
	mlx_hook(e->win, 17, 18, ft_exit, e);
	mlx_expose_hook(e->win, expose, e);
	mlx_loop(e->mlx);
}
