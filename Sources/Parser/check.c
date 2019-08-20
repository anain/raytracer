/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 22:19:32 by anain             #+#    #+#             */
/*   Updated: 2018/04/09 19:35:03 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int			ft_is_point_or_vec(char **c)
{
	int i;
	int j;

	i = 0;
	while (++i < 3)
	{
		if (!(c[i][0] == '-' || ft_isdigit(c[i][0])))
			ft_error("Error in the definition of a point.");
		j = -1;
		while (++j)
		{
			if (!ft_isdigit(c[i][j]) && c[i][j] != ' ' && (c[i][j] == '.'\
				&& (!ft_isdigit(c[i][j - 1]) || !ft_isdigit(c[i][j + 1]))))
				ft_error("Error in the definition of a point.");
		}
	}
	return (1);
}

int			ft_is_value(char *c)
{
	int i;

	i = 0;
	if (!(c[0] == '-' || ft_isdigit(c[0])))
		ft_error("Error in the definition of a point.");
	while (c[++i])
	{
		if (!(ft_isdigit(c[i])))
			ft_error("Error in the definition of a point.");
	}
	return (1);
}

static int	isnumber(char *c)
{
	int i;

	i = -1;
	while (c[++i])
	{
		if (!ft_isdigit(c[i]) && c[i] != '.')
			return (0);
	}
	return (1);
}

int			ft_is_color(char **c)
{
	int i;

	i = -1;
	while (c[++i])
	{
		if (!isnumber(c[i]))
			return (0);
	}
	return (1);
}
