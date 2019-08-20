/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emissive.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 17:30:56 by asavann           #+#    #+#             */
/*   Updated: 2018/04/22 13:07:45 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EMISSIVE_H
# define EMISSIVE_H

# include "material.h"

t_rgbcolor	area_light_shade(t_material *m, t_shaderec *sr);
t_rgbcolor	get_le(t_material *m, t_shaderec *sr);

#endif
