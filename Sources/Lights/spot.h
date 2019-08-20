/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spot.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 15:56:16 by asavann           #+#    #+#             */
/*   Updated: 2018/03/06 13:12:41 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPOT_H
# define SPOT_H

# include "light.h"
# include "shaderec.h"

void		set_colors(t_spot *spot, \
			const float r, const float g, const float b);
void		init_spot(t_spot *spot);
void		cpy_spot(t_spot *spot, const t_spot cpy);
t_spot		eq_spot(t_spot *spot, const t_spot rhs);
t_vector3d	get_directions(t_light *l, t_shaderec *sr);
t_rgbcolor	lspot(t_light *l, t_shaderec *sr);
void		set_location(t_spot *spot, \
			const float x, const float y, const float z);
int			in_shadows(const t_light *l, const t_ray shadowray, \
			const t_shaderec sr);
float		gspot(t_light *light, t_shaderec *sr);
float		pdfspot(t_light *light, t_shaderec *sr);
#endif
