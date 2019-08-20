/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arealight.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 20:05:56 by asavann           #+#    #+#             */
/*   Updated: 2018/04/22 17:01:06 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AREALIGHT_H
# define AREALIGHT_H

# include "light.h"

t_vector3d	get_direction_arealight(t_light *light, t_shaderec *sr);
int			in_shadowarea(const t_light *light, \
				const t_ray ray, const t_shaderec sr);
t_rgbcolor	larea(t_light *light, t_shaderec *sr);
float		garea(t_light *light, t_shaderec *sr);
float		pdfarea(t_light *light, t_shaderec *sr);
#endif
