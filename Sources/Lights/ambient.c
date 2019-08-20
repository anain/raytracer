/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 14:40:12 by asavann           #+#    #+#             */
/*   Updated: 2018/02/21 16:47:18 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ambient.h"

void		set_color(t_ambient *amb, \
			const float r, const float g, const float b)
{
	amb->color.r = r;
	amb->color.g = g;
	amb->color.b = b;
}

void		init_amb(t_ambient *amb)
{
	amb->ls = 1.0;
	set_color(amb, 1.0, 1.0, 1.0);
}

void		cpy_amb(t_ambient *amb, const t_ambient cpy)
{
	amb->ls = cpy.ls;
	rgbcopy(&amb->color, cpy.color);
}

t_ambient	eq_amb(t_ambient *amb, const t_ambient cpy)
{
	cpy_amb(amb, cpy);
	return (*amb);
}
