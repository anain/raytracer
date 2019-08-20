/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environmentlight.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:17:09 by asavann           #+#    #+#             */
/*   Updated: 2018/03/08 17:19:00 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENTLIGHT_H
# define ENVIRONMENTLIGHT_H

# include "light.h"

void		set_samplerel(t_environmentlight *el, const int ns);
t_vector3d	get_directionel(t_light *light, t_shaderec *sr);
t_rgbcolor	lel(t_light *light, t_shaderec *sr);
int			in_shadowel(\
			const t_light *light, const t_ray ray, const t_shaderec sr);
float		pdfel(t_light *el, t_shaderec *sr);
#endif
