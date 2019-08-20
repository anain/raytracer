/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 22:20:15 by anain             #+#    #+#             */
/*   Updated: 2018/04/21 21:48:40 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	free_all(char **c, int j)
{
	int i;

	i = -1;
	while (++i < j)
	{
		if (c[i])
			free(c[i]);
	}
	free(c);
}

void	set_normal2(t_normal *p, char **c, int i)
{
	double	*a;

	a = NULL;
	a = ft_atod_safe(c[0]);
	p->x = *a;
	free(a);
	a = ft_atod_safe(c[1]);
	p->y = *a;
	free(a);
	a = ft_atod_safe(c[2]);
	p->z = *a;
	free(a);
	free_all(c, i);
}

void	set_point2(t_point3d *p, char **c, int i)
{
	double	*a;

	a = NULL;
	a = ft_atod_safe(c[0]);
	p->x = *a;
	free(a);
	a = ft_atod_safe(c[1]);
	p->y = *a;
	free(a);
	a = ft_atod_safe(c[2]);
	p->z = *a;
	free(a);
	free_all(c, i);
}

void	set_vector2(t_vector3d *p, char **c, int i)
{
	double	*a;

	a = NULL;
	a = ft_atod_safe(c[0]);
	p->x = *a;
	free(a);
	a = ft_atod_safe(c[1]);
	p->y = *a;
	free(a);
	a = ft_atod_safe(c[2]);
	p->z = *a;
	free(a);
	free_all(c, i);
}

double	set_positive_value(xmlChar *xmlchar)
{
	char	*c;
	double	k;

	c = (char *)xmlchar;
	if (c == NULL)
		ft_error("Error in the definition of a positive value.");
	k = ft_atod(c);
	if (k < 0)
		ft_error("Error in the definition of a positive value.");
	return (k);
}
