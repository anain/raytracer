/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 22:16:07 by anain             #+#    #+#             */
/*   Updated: 2018/04/22 20:17:51 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void			add_object_list(t_object_set *object, char *newobj, \
	void (*setobj)(xmlDocPtr doc, t_object *object, xmlNodePtr cur))
{
	t_object_set *obj;

	obj = object;
	while (obj->next != NULL)
		obj = obj->next;
	if (!(obj->next = (t_object_set *)malloc(sizeof(t_object_set))))
		ft_error(MALLOC_ERR);
	obj = obj->next;
	obj->name = newobj;
	obj->setobj = setobj;
	obj->next = NULL;
}

t_object_set	*object_list(t_object_set *obj)
{
	if (!(obj = (t_object_set *)malloc(sizeof(t_object_set))))
		ft_error(MALLOC_ERR);
	obj->name = "sphere";
	obj->next = NULL;
	obj->setobj = set_sphere;
	add_object_list(obj, "plane", set_plane);
	add_object_list(obj, "cylinder", set_cylinder);
	add_object_list(obj, "cone", set_cone);
	add_object_list(obj, "triangle", set_triangle);
	add_object_list(obj, "torus", set_torus);
	add_object_list(obj, "box", set_box);
	add_object_list(obj, "partsphere", set_partsphere);
	add_object_list(obj, "rectangle", set_rectangle);
	add_object_list(obj, "paraboloid", set_paraboloid);
	add_object_list(obj, "partocylinder", set_partocylinder);
	add_object_list(obj, "disk", set_disk);
	add_object_list(obj, "mickey", mickey);
	add_object_list(obj, "limcone", set_limcone);
	add_object_list(obj, "skybox", set_skybox);
	return (obj);
}

t_object		*new_obj(t_object *worldobject, t_world *world)
{
	t_object *begin;

	begin = worldobject;
	if (!worldobject)
	{
		if (!(worldobject = (t_object *)malloc(sizeof(t_object))))
			ft_error(MALLOC_ERR);
		worldobject->next = NULL;
		begin = worldobject;
		world->begin = worldobject;
	}
	else
	{
		while (worldobject != NULL)
			worldobject = worldobject->next;
		if (!(worldobject = (t_object *)malloc(sizeof(t_object))))
			ft_error(MALLOC_ERR);
		worldobject->next = NULL;
		begin = worldobject;
	}
	return (begin);
}

void			freeset(t_object_set *set)
{
	while (set != NULL)
	{
		free(set);
		set = set->next;
	}
}

void			parse_objects(xmlDocPtr doc, xmlNodePtr cur, t_world *world)
{
	int				i;
	t_object_set	*obj;
	t_object_set	*current_obj;
	t_object		*last;

	i = 0;
	obj = NULL;
	obj = object_list(obj);
	current_obj = obj;
	while (cur != NULL)
	{
		current_obj = obj;
		while (current_obj != NULL)
		{
			if (xmlStrcmp(cur->name, (const xmlChar *)current_obj->name) == 0)
			{
				last = addobj(&world->object, world);
				current_obj->setobj(doc, last, cur->xmlChildrenNode);
			}
			current_obj = current_obj->next;
		}
		cur = cur->next;
	}
	freeset(obj);
}
