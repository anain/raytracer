/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <anain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 15:04:10 by anain             #+#    #+#             */
/*   Updated: 2018/04/21 23:33:29 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mmlx.h"
#include <math.h>
#include <unistd.h>

t_rgbcolor	get_texture_pix(t_material *m, int row, int column)
{
	t_rgbcolor			color;
	int					i;
	unsigned char		*data;

	data = (unsigned char *)m->tex.marb_data;
	if (row >= 0 && column >= 0)
	{
		i = row * 4 + column * m->tex.marb_size_l;
		color.b = data[i] / 255.0;
		color.g = data[++i] / 255.0;
		color.r = data[++i] / 255.0;
	}
	else
		color = (t_rgbcolor){0, 0, 0};
	return (color);
}
