/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deepcopy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 17:54:05 by asavann           #+#    #+#             */
/*   Updated: 2018/04/24 17:02:50 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "world.h"

void	cpylight(t_light **wlight)
{
	t_light *light;

	if (!(light = (t_light *)malloc(sizeof(t_light))))
		exit(EXIT_FAILURE);
	*light = **wlight;
	*wlight = light;
}

void	cpyobj(t_object **obj)
{
	t_object *object;

	if (!(object = (t_object *)malloc(sizeof(t_object))))
		exit(EXIT_FAILURE);
	*object = **obj;
	*obj = object;
}

void	deepfree(t_world *w)
{
	t_light		*tmp;
	t_object	*obj;

	while (w->light != NULL)
	{
		tmp = w->light;
		w->light = w->light->next;
		free(tmp);
	}
	while (w->begin != NULL)
	{
		obj = w->begin;
		w->begin = w->begin->next;
		free(obj);
	}
}

void	deepcpy(t_world *w)
{
	t_light		*tmp;
	t_object	*obj;

	if (w->light)
	{
		cpylight(&w->light);
		tmp = w->light;
		while (w->light->next != NULL)
		{
			cpylight(&w->light->next);
			w->light = w->light->next;
		}
		w->light = tmp;
	}
	if (w->begin)
	{
		cpyobj(&w->begin);
		obj = w->begin;
		while (w->begin->next != NULL)
		{
			cpyobj(&w->begin->next);
			w->begin = w->begin->next;
		}
		w->begin = obj;
	}
}
