/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chess.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <anain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 12:56:36 by anain             #+#    #+#             */
/*   Updated: 2018/04/22 23:16:51 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chess.h"

int				ft_floor(double x)
{
	if (x > (int)(x))
		return ((int)x);
	else
		return ((int)x - 1);
}

t_rgbcolor		get_chess_color(t_shaderec *sr)
{
	t_point3d p;

	p = point3dmultmat(sr->materialptr->inv_mat, sr->local_hit_point);
	if ((ft_floor(p.x / sr->materialptr->chess.size) + \
	ft_floor(p.y / sr->materialptr->chess.size) + \
	ft_floor(p.z / sr->materialptr->chess.size)) % 2 == 0)
	{
		return (sr->materialptr->chess.color1);
	}
	else
		return (sr->materialptr->chess.color2);
}
