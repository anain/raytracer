/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 18:26:46 by asavann           #+#    #+#             */
/*   Updated: 2018/04/24 17:45:42 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mmlx.h"
#include "matrix.h"

int		mouse_input(int keycode, int x, int y, t_param *e)
{
	(void)keycode;
	if (x >= (e->v.vp.win_width / 4) * 3 && x <= ((e->v.vp.win_width / 4) * 3)\
		+ 100 && y >= (e->v.vp.win_height / 10) * 9 && y <= \
		(e->v.vp.win_height / 10) * 9 + 25)
		ft_exit(e);
	return (0);
}

int		ft_exit(t_param *e)
{
	ft_putstr("Exit.\n");
	free(e->world.objnames);
	exit(0);
}
