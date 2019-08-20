/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mickey.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <anain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 22:29:20 by anain             #+#    #+#             */
/*   Updated: 2018/04/23 17:22:35 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "compound.h"

void		set_ears1(t_object *cur)
{
	cur->sphere.kepsilon = 0.00001;
	cur->hit = hittransform;
	cur->hittrans = spherehit;
	cur->shadow_hit = shadow_hittransform;
	cur->shadow_hittrans = spherehitshadow;
	cur->type = SPHERE;
	set_identity(&cur->inv_mat);
	set_identity(&cur->mat.inv_mat);
	cur->shadow = 1;
	cur->next = NULL;
}

void		set_ears(t_object *obj, xmlNodePtr curr, xmlDocPtr doc)
{
	t_object	*cur;
	t_object	*new;
	t_object	*sav;
	int			j;
	int			i;

	j = -1;
	sav = obj->compound;
	while (++j < 2)
	{
		if (!(new = (t_object *)malloc(sizeof(t_object))))
			ft_error(MALLOC_ERR);
		while (obj->compound->next != NULL)
			obj->compound = obj->compound->next;
		cur = obj->compound;
		cur->next = new;
		cur = cur->next;
		i = j == 0 ? 1 : -1;
		cur->sphere.center = (t_point3d){(0.9 * sav->sphere.radius * i), \
			(1.2 * sav->sphere.radius), sav->sphere.center.z};
		cur->sphere.radius = 0.8 * sav->sphere.radius;
		cur->mat = sav->mat;
		set_ears1(cur);
		transformation(doc, cur, curr);
	}
}

void		mickey2(xmlDocPtr doc, t_object *object, xmlNodePtr cur)
{
	double		*a;
	xmlChar		*xmldata;

	a = NULL;
	xmldata = find_data(doc, cur, "../center");
	if (!xmldata)
		ft_mickey_error();
	else if (!set_point(xmldata, &object->compound->sphere.center))
	{
		xmlFree(xmldata);
		ft_sphere_error();
	}
	xmldata = find_data(doc, cur, "../radius");
	if ((a = ft_atod_safe((char*)xmldata)) == NULL)
	{
		xmlFree(xmldata);
		ft_sphere_error();
	}
	object->compound->sphere.radius = *a;
	free(a);
	xmlFree(xmldata);
}

void		mickey1(t_object *obj)
{
	obj->compound->type = SPHERE;
	obj->compound->shadow = 1;
	obj->compound->next = NULL;
	obj->type = MICKEY;
	obj->next = NULL;
	obj->compound->sphere.kepsilon = 0.00001;
}

void		mickey(xmlDocPtr doc, t_object *obj, xmlNodePtr cur)
{
	t_object *head;

	if (!(cur))
		ft_mickey_error();
	if (!(obj->compound = (t_object *)malloc(sizeof(t_object))))
		ft_error(MALLOC_ERR);
	mickey1(obj);
	mickey2(doc, obj, cur);
	obj->d = obj->compound->sphere.center;
	if (!obj->compound->sphere.radius)
		ft_mickey_error();
	set_object_generic(doc, obj->compound, cur);
	set_object_generic(doc, obj, cur);
	head = obj->compound;
	set_ears(obj, cur, doc);
	obj->compound = head;
}
