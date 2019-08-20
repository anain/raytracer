/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_set2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 16:53:22 by asavann           #+#    #+#             */
/*   Updated: 2018/04/13 17:18:53 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int		set_point(xmlChar *xmlchar, t_point3d *p)
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
	if (i < 3)
	{
		free_all(c, i + 1);
		return (0);
	}
	set_point2(p, c, i + 1);
	return (1);
}

int		set_vector(xmlChar *xmlchar, t_vector3d *p)
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
	if (i < 3)
	{
		free_all(c, i + 1);
		return (0);
	}
	set_vector2(p, c, i + 1);
	return (1);
}
