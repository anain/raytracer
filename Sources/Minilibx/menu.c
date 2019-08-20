/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:08:39 by jorobin           #+#    #+#             */
/*   Updated: 2018/04/21 23:03:03 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mmlx.h"

#include "mmlx.h"

void	print_menu2(t_param *e)
{
	mlx_string_put(e->mlx, e->win, (e->v.vp.win_width / 10) * 1,\
	(e->v.vp.win_height / 10) * 1 + 110, 0X990000, \
	"Rotation camera : Y, G, H, J");
	mlx_string_put(e->mlx, e->win, (e->v.vp.win_width / 10) * 1,\
	(e->v.vp.win_height / 10) * 1 + 130, 0X990000, "Reset : X");
	mlx_string_put(e->mlx, e->win, (e->v.vp.win_width / 10) * 1,\
	(e->v.vp.win_height / 10) * 1 + 150, 0X990000, "ZOOM : R, F");
	mlx_string_put(e->mlx, e->win, (e->v.vp.win_width / 10) * 1,\
	(e->v.vp.win_height / 10) * 1 + 170, 0X990000, "Resolution : - +");
	mlx_string_put(e->mlx, e->win, (e->v.vp.win_width / 10) * 1,\
	(e->v.vp.win_height / 10) * 1 + 190, 0X990000, "Capture d'ecran : F5");
	mlx_string_put(e->mlx, e->win, (e->v.vp.win_width / 10) * 1,\
	(e->v.vp.win_height / 10) * 1 + 210, 0X990000, "Filtre : F6");
}

void	print_menu(t_param *e)
{
	char *str;

	mlx_string_put(e->mlx, e->win, (e->v.vp.win_width / 10) * 1,\
	(e->v.vp.win_height / 10) * 1, 0X990000, "Position de la camera : ");
	str = ft_itoa(e->world.camera.eye.x);
	mlx_string_put(e->mlx, e->win, (e->v.vp.win_width / 10) * 1 +\
	40, (e->v.vp.win_height / 10) * 1 + 20, 0X990000,\
	str);
	free(str);
	str = ft_itoa(e->world.camera.eye.y);
	mlx_string_put(e->mlx, e->win, (e->v.vp.win_width / 10) * 1 +\
	100, (e->v.vp.win_height / 10) * 1 + 20, 0X990000,\
	str);
	free(str);
	str = ft_itoa(e->world.camera.eye.z);
	mlx_string_put(e->mlx, e->win, (e->v.vp.win_width / 10) * 1 +\
	150, (e->v.vp.win_height / 10) * 1 + 20, 0X990000,\
	str);
	free(str);
	mlx_string_put(e->mlx, e->win, (e->v.vp.win_width / 10) * 1,\
		(e->v.vp.win_height / 10) * 1 + 70, 0X990000, "TOUCHES");
	mlx_string_put(e->mlx, e->win, (e->v.vp.win_width / 10) * 1,\
	(e->v.vp.win_height / 10) * 1 + 90, 0X990000, "Camera : W, A, S, D, Q, Z");
	print_menu2(e);
}

void	print_obj_menu2(t_param *e, int mult)
{
	char *str;

	str = ft_itoa(e->world.object->d.y);
	mlx_string_put(e->mlx, e->win, (e->v.vp.win_width / 10) * mult + 100,\
	(e->v.vp.win_height / 10) * 1 + 100,\
	0X990000, str);
	free(str);
	str = ft_itoa(e->world.object->d.z);
	mlx_string_put(e->mlx, e->win, (e->v.vp.win_width / 10) * mult + 150,\
	(e->v.vp.win_height / 10) * 1 + 100,\
	0X990000, str);
	free(str);
}

void	print_obj_menu(t_param *e)
{
	int		mult;
	char	*str;

	mult = e->v.vp.win_width <= 600 ? 5 : 6;
	mult = e->v.vp.win_width > 1000 ? 7 : mult;
	mlx_string_put(e->mlx, e->win, (e->v.vp.win_width / 10) * mult,\
	(e->v.vp.win_height / 10) * 1, 0X990000, "Touches: Fleches, '.', 0");
	mlx_string_put(e->mlx, e->win, (e->v.vp.win_width / 10) * mult,\
	(e->v.vp.win_height / 10) * 1 + 20, 0X990000, "Rotations: U, I, B, V");
	mlx_string_put(e->mlx, e->win, (e->v.vp.win_width / 10) * mult,\
	(e->v.vp.win_height / 10) * 1 + 40, 0X990000, "Cur obj : ");
	mlx_string_put(e->mlx, e->win, (e->v.vp.win_width / 10) * mult + 100,\
	(e->v.vp.win_height / 10) * 1 + 40, 0X990000, \
	e->world.objnames[e->world.object->type]);
	mlx_string_put(e->mlx, e->win, (e->v.vp.win_width / 10) * mult,\
	(e->v.vp.win_height / 10) + 60, 0X990000, "Changer d'Objet : N");
	mlx_string_put(e->mlx, e->win, (e->v.vp.win_width / 10) * mult,\
	(e->v.vp.win_height / 10) * 1 + 80, 0X990000, "Position : ");
	str = ft_itoa(e->world.object->d.x);
	mlx_string_put(e->mlx, e->win, (e->v.vp.win_width / 10) * mult + 40,\
	(e->v.vp.win_height / 10) * 1 + 100, 0X990000,\
	str);
	free(str);
	print_obj_menu2(e, mult);
}
