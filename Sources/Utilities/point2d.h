/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point2d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 11:35:05 by asavann           #+#    #+#             */
/*   Updated: 2018/02/14 19:52:29 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT2D_H
# define POINT2D_H

typedef struct	s_point2d
{
	float	x;
	float	y;
}				t_point2d;

void			point2dsetvalue(t_point2d *p, float x, float y);

#endif
