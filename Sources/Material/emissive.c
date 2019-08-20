/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emissive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 17:35:32 by asavann           #+#    #+#             */
/*   Updated: 2018/04/22 13:07:32 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "emissive.h"
#include <stdio.h>
#include <stdlib.h>

t_rgbcolor			area_light_shade(t_material *m, t_shaderec *sr)
{
	double			ndotd;
	t_normal		n;

	n = normalneg(&sr->normal);
	ndotd = normaldotproduct(&n, sr->ray.d);
	if (ndotd > 0.0)
		return (rgbmult(&m->emissive.ce, m->emissive.ls));
	return ((t_rgbcolor){0.0, 0.0, 0.0});
}

t_rgbcolor			get_le(t_material *m, t_shaderec *sr)
{
	if (sr)
		;
	return (rgbmult(&m->emissive.ce, m->emissive.ls));
}
