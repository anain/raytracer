/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflective.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <anain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 18:56:30 by anain             #+#    #+#             */
/*   Updated: 2018/04/22 13:06:05 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REFLECTIVE_H
# define REFLECTIVE_H

# include "material.h"
# include "matte.h"
# include "world.h"
# include <stdio.h>

t_rgbcolor	shadephong(t_material *m, t_shaderec *sr);
t_rgbcolor	sample_f(t_perfectspecular *perf, const t_shaderec sr, \
			const t_vector3d wo, t_vector3d *wi);
t_rgbcolor	reflective(t_material *m, t_shaderec *sr);
t_rgbcolor	pathreflective(t_material *m, t_shaderec *sr);

#endif
