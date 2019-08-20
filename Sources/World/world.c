/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 18:22:05 by asavann           #+#    #+#             */
/*   Updated: 2018/04/23 15:32:41 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"
#include "partsphere.h"
#include "partopencylinder.h"
#include "disk.h"
#include "rectangle.h"
#include "emissive.h"
#include "arealight.h"
#include "environmentlight.h"
#include "directional.h"
#include "matte.h"
#include "mmlx.h"
#include "noise.h"

void		hit_confirmed(t_wvar *var)
{
	var->sr.t = var->tmin;
	var->sr.normal = var->normal;
	var->sr.local_hit_point = var->local_hit_point;
}

t_shaderec	hit_objects(t_world *wr, const t_ray ray)
{
	t_wvar	var;

	shaderecinit(&var.sr, wr);
	var.sr.compound = 0;
	var.tmin = KHUGEVALUE;
	var.head = wr->begin;
	while (var.head)
	{
		if (var.head->hit(var.head, ray, &var.t, &var.sr) && (var.t < var.tmin))
		{
			var.sr.hit_an_object = 1;
			var.tmin = var.t;
			if (var.sr.compound == 0)
				var.sr.materialptr = &var.head->mat;
			var.sr.hit_point = addvector(&ray.o, multvector3d(&ray.d, var.t));
			var.normal = var.sr.normal;
			var.local_hit_point = var.sr.local_hit_point;
			var.sr.hitobj = var.head;
		}
		var.head = var.head->next;
	}
	if (var.sr.hit_an_object == 1)
		hit_confirmed(&var);
	return (var.sr);
}
