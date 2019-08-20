/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_set2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 16:53:22 by asavann           #+#    #+#             */
/*   Updated: 2018/04/22 22:07:28 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int		is_perfectsquare(int n)
{
	int sqrt_n;

	sqrt_n = sqrt(n);
	if (n != sqrt_n * sqrt_n)
		ft_error("Samples & antialiasing value should be a perfect square.");
	if (n > 100000)
		ft_error("Samples & antialiasing max value : 100 000");
	return (1);
}

int		no_point(t_point3d *p)
{
	if (!p->x && !p->y && !p->z)
		return (1);
	return (0);
}

int		no_normal(t_normal *n)
{
	if (!n->x && !n->y && !n->z)
		return (1);
	return (0);
}

int		no_vector(t_vector3d *v)
{
	if (!v->x && !v->y && !v->z)
		return (1);
	return (0);
}

double	set_coef(xmlChar *xmlchar)
{
	char	*c;
	double	k;

	c = (char *)xmlchar;
	if (c == NULL)
		ft_error("Error in the definition of a coefficient.");
	k = ft_atod(c);
	if (k >= 0 && k <= 1)
		return (ft_atod(c));
	else
		ft_error("Coefficients should be postive and inferior to 1.");
	return (-1);
}
