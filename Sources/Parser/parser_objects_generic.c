/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_objects_generic.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 17:12:02 by anain             #+#    #+#             */
/*   Updated: 2018/04/24 23:11:15 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "paraboloid.h"
#include "torus.h"
#include "infcone.h"
#include "opencylinder.h"
#include "limcone.h"
#include "partopencylinder.h"
#include "partsphere.h"
#include "disk.h"
#include "rectangle.h"
#include "compound.h"

void	get_hittrans3(t_object *object)
{
	if (object->type == PARTCYLINDER)
	{
		object->hittrans = partopencylinderhit;
		object->shadow_hittrans = partopencylinderhitshadow;
	}
	if (object->type == PARTSPHERE)
	{
		object->hittrans = partspherehit;
		object->shadow_hittrans = partspherehitshadow;
	}
	if (object->type == PARABOLOID)
	{
		object->hittrans = paraboloidhit;
		object->shadow_hittrans = paraboloidhitshadow;
	}
	if (object->type == TORUS)
	{
		object->hittrans = torushit;
		object->shadow_hittrans = torushitshadow;
	}
	if (object->type == MICKEY)
	{
		object->hittrans = compoundhit;
		object->shadow_hittrans = compoundhitshadow;
	}
}

void	get_hittrans2(t_object *object)
{
	if (object->type == TRIANGLE)
	{
		object->hittrans = trianglehit;
		object->shadow_hittrans = trianglehitshadow;
	}
	if (object->type == DISK)
	{
		object->hittrans = diskhit;
		object->shadow_hittrans = diskhitshadow;
	}
	if (object->type == CYLINDER)
	{
		object->hittrans = opencylinderhit;
		object->shadow_hittrans = opencylinderhitshadow;
	}
	if (object->type == RECTANGLE)
	{
		object->hittrans = rectanglehit;
		object->shadow_hittrans = rectanglehitshadow;
	}
	get_hittrans3(object);
}

void	get_hittrans(t_object *object)
{
	if (object->type == SPHERE)
	{
		object->hittrans = spherehit;
		object->shadow_hittrans = spherehitshadow;
	}
	if (object->type == PLANE)
	{
		object->hittrans = planehit;
		object->shadow_hittrans = planehitshadow;
	}
	if (object->type == CONE)
	{
		object->hittrans = infconehit;
		object->shadow_hittrans = infconehitshadow;
	}
	if (object->type == BOX)
	{
		object->hittrans = boxhit;
		object->shadow_hittrans = boxhitshadow;
	}
	object->shadow_hit = shadow_hittransform;
	get_hittrans2(object);
}

void	set_hit_hittrans(t_object *obj)
{
	obj->hit = hittransform;
	get_hittrans(obj);
}

void	set_object_generic(xmlDocPtr doc, t_object *object, xmlNodePtr obj_node)
{
	xmlXPathObjectPtr	xpathobj;
	xmlNodePtr			mat;

	set_identity(&object->inv_mat);
	set_identity(&object->mat.inv_mat);
	object->mat.mapping = basic_mapping;
	object->mat.tex.path = NULL;
	xpathobj = findnodesbyname(doc, obj_node, (xmlChar *)"../material");
	if (xpathobj->nodesetval->nodeNr == 0)
	{
		ft_putstr("Error in ");
		ft_putstr((char *)obj_node->parent->name);
		ft_putstr(" : material not found.");
		ft_error("--------------------------\n");
	}
	mat = xpathobj->nodesetval->nodeTab[0]->xmlChildrenNode;
	set_material(doc, object, mat);
	transformation(doc, object, obj_node);
	if (object->type)
		set_hit_hittrans(object);
	xmlXPathFreeObject(xpathobj);
	object->shadow = (object->type == SKYBOX ? 0 : 1);
}
