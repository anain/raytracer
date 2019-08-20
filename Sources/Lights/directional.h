/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directional.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 17:01:16 by asavann           #+#    #+#             */
/*   Updated: 2018/03/08 17:42:58 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIRECTIONAL_H
# define DIRECTIONAL_H

# include "light.h"
# include "shaderec.h"

void			set_colord(t_directional *d, \
			const float r, const float g, const float b);
void			set_directiond(t_directional *d, \
			const float dx, const float dy, const float dz);
void			scale_radianced(t_directional *d, const float b);
void			init_d(t_directional *d);
void			cpy_d(t_directional *d, const t_directional rhs);
t_directional	eq_d(t_directional *d, const t_directional rhs);
t_vector3d		get_direction(t_light *light, t_shaderec *sr);
t_rgbcolor		l(t_light *light, t_shaderec *sr);
int				in_shadowd(const t_light *light, \
			const t_ray ray, const t_shaderec sr);
float			gdir(t_light *light, t_shaderec *sr);
float			pdfdir(t_light *light, t_shaderec *sr);
#endif
