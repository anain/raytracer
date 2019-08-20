/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 19:01:54 by asavann           #+#    #+#             */
/*   Updated: 2018/04/22 14:34:58 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONG_H
# define PHONG_H

# include "material.h"

void		set_kap(t_phong *phong, const float k);
void		set_kdp(t_phong *phong, const float k);
void		set_cdp(t_phong *phong, \
			const float r, const float g, const float b);
void		init_phong(t_phong *phong);
void		cpy_phong(t_phong *phong, const t_phong rhs);
t_phong		eq_phong(t_phong *phong, const t_phong rhs);
t_rgbcolor	shadephong(t_material *m, t_shaderec *sr);
t_rgbcolor	pathphong(t_material *m, t_shaderec *sr);

#endif
