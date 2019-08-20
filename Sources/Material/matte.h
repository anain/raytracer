/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matte.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:54:59 by asavann           #+#    #+#             */
/*   Updated: 2018/04/22 13:36:24 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATTE_H
# define MATTE_H

# include "material.h"

t_rgbcolor		shadematte(t_material *m, t_shaderec *sr);
void			set_ka(t_matte *matte, const float k);
void			set_kd(t_matte *matte, const float k);
void			set_cd(t_matte *matte, \
					const float r, const float g, const float b);
void			init_matte(t_matte *matte);
void			cpy_matte(t_matte *matte, const t_matte rhs);
t_matte			eq_matte(t_matte *matte, const t_matte rhs);
t_rgbcolor		pathshadematte(t_material *m, t_shaderec *sr);

#endif
