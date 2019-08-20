/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directional2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 17:29:34 by asavann           #+#    #+#             */
/*   Updated: 2018/04/20 21:11:51 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "directional.h"
#include "world.h"
#include <stdio.h>

t_directional	eq_d(t_directional *d, const t_directional rhs)
{
	cpy_d(d, rhs);
	return (*d);
}

t_vector3d		get_direction(t_light *light, t_shaderec *sr)
{
	t_vector3d	wi;

	if (sr)
		;
	wi = vector3dneg(&light->dlight.dir);
	return (light->dlight.dir);
}

t_rgbcolor		l(t_light *light, t_shaderec *sr)
{
	if (sr)
		;
	return (rgbmult(&light->dlight.color, light->dlight.ls));
}

int				in_shadowd(\
		const t_light *light, const t_ray ray, const t_shaderec sr)
{
	float		t;
	int			j;
	t_object	*head;

	j = 0;
	if (light)
		;
	head = sr.w->begin;
	while (head != NULL)
	{
		if (head->shadow == 1 && head->shadow_hit(head, ray, &t))
			return (1);
		head = head->next;
	}
	head = sr.w->object;
	return (0);
}
