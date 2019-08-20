/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_box.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorobin <jorobin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 12:36:39 by jorobin           #+#    #+#             */
/*   Updated: 2018/04/22 22:14:41 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_box_error(void)
{
	ft_putstr("XML ERROR : BOX NODE\n--------------------------\n");
	ft_putstr("<diagonal> X1 Y1 Z1, X2, Y2, Z2");
	ft_putstr(" </diagonal>\n");
	ft_error("--------------------------\n");
}

void	fill_values(char **c, t_lim *d)
{
	double *a;

	a = NULL;
	a = ft_atod_safe(c[0]);
	d->x0 = *a;
	free(a);
	a = ft_atod_safe(c[1]);
	d->y0 = *a;
	free(a);
	a = ft_atod_safe(c[2]);
	d->z0 = *a;
	free(a);
	a = ft_atod_safe(c[3]);
	d->x1 = *a;
	free(a);
	a = ft_atod_safe(c[4]);
	d->y1 = *a;
	free(a);
	a = ft_atod_safe(c[5]);
	d->z1 = *a;
	free(a);
}

int		set_diagonal(t_lim *d, xmlChar *xmlchar)
{
	char	**c;
	int		i;
	double	*a;

	a = NULL;
	i = -1;
	c = ft_strsplit((char *)xmlchar, ' ');
	while (c[++i])
	{
		if ((a = ft_atod_safe(c[i])) == NULL)
		{
			free(a);
			free_all(c, i + 1);
			return (0);
		}
		free(a);
	}
	if (i < 6)
	{
		free_all(c, i + 1);
		return (0);
	}
	fill_values(c, d);
	free_all(c, i + 1);
	return (1);
}

void	set_box2(t_object *object, xmlNodePtr child, xmlChar *xmldata)
{
	double *a;

	a = NULL;
	if (xmlStrcmp(child->name, (const xmlChar *)"diagonal") == 0)
	{
		if (!set_diagonal(&object->box.lim, xmldata))
		{
			xmlFree(xmldata);
			ft_box_error();
		}
	}
}

void	set_box(xmlDocPtr doc, t_object *object, xmlNodePtr cur)
{
	xmlChar		*xmldata;
	xmlNodePtr	child;

	object->type = BOX;
	child = cur;
	if (!(cur))
		ft_error("Error in the definition of box.\n");
	while (child != NULL)
	{
		xmldata = xmlNodeListGetString(doc, child->xmlChildrenNode, 0);
		if (xmldata)
		{
			set_box2(object, child, xmldata);
		}
		xmlFree(xmldata);
		child = child->next;
	}
	if (!(object->box.lim.x0) && !(object->box.lim.y0) && \
		!(object->box.lim.z0) && !(object->box.lim.x1) && \
		!(object->box.lim.y1) && !(object->box.lim.z1))
		ft_box_error();
	object->box.kepsilon = 0.00001;
	object->d = (t_point3d) {object->box.lim.x0, object->box.lim.y0, \
		object->box.lim.z0};
	set_object_generic(doc, object, cur);
}
