/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 14:46:50 by asavann           #+#    #+#             */
/*   Updated: 2018/04/20 20:37:15 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ambient.h"
#include "world.h"

t_vector3d	get_directionamb(t_ambient *amb, t_shaderec *sr)
{
	t_vector3d d;

	if (amb && sr)
		;
	vector3dsetvalue(&d, 0.0, 0.0, 0.0);
	return (d);
}

t_rgbcolor	lamb(t_world *w, t_shaderec *sr)
{
	if (sr)
		;
	return (rgbmult(&w->amb.color, w->amb.ls));
}
