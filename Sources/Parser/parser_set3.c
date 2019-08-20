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

void	set_colorp2(t_rgbcolor *col)
{
	if (col->r < 0 || col->r > 1 || col->g < 0 || col->g > 1
	|| col->b < 0 || col->b > 1)
		ft_error("Error in the definition of a color.");
}

void	set_colorp(xmlChar *xmlchar, t_rgbcolor *col)
{
	char	**c;
	int		i;

	i = 0;
	c = ft_strsplit((char *)xmlchar, ' ');
	if (c)
	{
		if (!ft_is_color(c))
			ft_error("Error in the definition of a color.");
		col->r = ft_atod(c[0]);
		col->g = ft_atod(c[1]);
		col->b = ft_atod(c[2]);
		free(c[0]);
		free(c[1]);
		free(c[2]);
		free(c);
	}
	else
	{
		col->r = 1;
		col->g = 1;
		col->b = 1;
	}
	set_colorp2(col);
}

int		set_normal(xmlChar *xmlchar, t_normal *p)
{
	char	**c;
	int		i;
	double	*a;

	a = NULL;
	i = 0;
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
	set_normal2(p, c, i + 1);
	return (1);
}

void	set_rgb(xmlChar *xmlchar, t_rgbcolor *p)
{
	char	**c;
	int		i;

	i = 0;
	c = ft_strsplit((char *)xmlchar, ' ');
	if (!(c[0] && c[1] && c[2]))
		ft_error("Error in the definition of a color : set double for R G B.");
	p->r = ft_atod(c[0]);
	p->g = ft_atod(c[1]);
	p->b = ft_atod(c[2]);
	free(c[0]);
	free(c[1]);
	free(c[2]);
	free(c);
}

void	set_vec(xmlChar *xmlchar, t_vector3d *v)
{
	char	**c;
	int		i;

	i = 0;
	c = ft_strsplit((char *)xmlchar, ' ');
	v->x = ft_atod(c[0]);
	v->y = ft_atod(c[1]);
	v->z = ft_atod(c[2]);
	free(c[0]);
	free(c[1]);
	free(c[2]);
	free(c);
}
