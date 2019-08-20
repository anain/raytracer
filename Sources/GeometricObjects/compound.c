/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compound.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <anain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 15:02:17 by anain             #+#    #+#             */
/*   Updated: 2018/04/22 17:16:12 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compound.h"
#include "constants.h"

int			compoundhit(const t_object *o, const t_ray ray, double *tmin,\
		t_shaderec *sr)
{
	t_compvar cv;

	*tmin = KHUGEVALUE;
	cv.hit = 0;
	cv.head = o->compound;
	while (cv.head)
	{
		if (cv.head->hit(cv.head, ray, &cv.t, sr) && (cv.t < *tmin))
		{
			cv.hit = 1;
			*tmin = cv.t;
			sr->compound = 1;
			sr->materialptr = &cv.head->mat;
			cv.normal = sr->normal;
			cv.local_hit_point = sr->local_hit_point;
		}
		cv.head = cv.head->next;
	}
	if (cv.hit)
	{
		sr->t = *tmin;
		sr->normal = cv.normal;
		sr->local_hit_point = cv.local_hit_point;
	}
	return (cv.hit);
}

int			compoundhitshadow(const t_object *o, const t_ray ray, float *tmin)
{
	float		t;
	int			hit;
	t_object	*head;

	hit = 0;
	head = o->compound;
	t = KHUGEVALUE;
	while (head)
	{
		if (head->shadow_hit(head, ray, &t))
		{
			hit = 1;
			tmin = &t;
		}
		head = head->next;
	}
	return (hit);
}
