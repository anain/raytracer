/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 14:29:04 by asavann           #+#    #+#             */
/*   Updated: 2018/04/20 20:34:06 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMBIENT_H
# define AMBIENT_H

# include "light.h"
# include "shaderec.h"

void		set_color(t_ambient *amb, \
			const float r, const float g, const float b);
t_vector3d	get_directionamb(t_ambient *amb, t_shaderec *sr);
t_rgbcolor	lamb(t_world *w, t_shaderec *sr);
void		init_amb(t_ambient *amb);
void		cpy_amb(t_ambient *amb, const t_ambient cpy);
t_ambient	eq_amb(t_ambient *amb, const t_ambient cpy);

#endif
