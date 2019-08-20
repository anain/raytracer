/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambientoccluder.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:40:32 by asavann           #+#    #+#             */
/*   Updated: 2018/04/20 20:47:28 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMBIENTOCCLUDER_H
# define AMBIENTOCCLUDER_H

# include "light.h"
# include "shaderec.h"

void		set_samplerao(t_ambientoccluder *ao, const int ns);
t_rgbcolor	lao(t_world *w, t_shaderec *sr);

#endif
