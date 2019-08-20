/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <anain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 19:16:13 by anain             #+#    #+#             */
/*   Updated: 2018/04/24 22:03:31 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "math.h"
#include <stdio.h>

static double	ft_put_double(char *str, int i)
{
	double	n;
	double	j;
	double	k;

	j = 0;
	k = 0;
	n = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		j = j * 10 + str[i] - 48;
		i++;
	}
	if (str[i] == '.')
	{
		i++;
		while ('0' <= str[i] && str[i] <= '9')
		{
			k = k * 10 + str[i] - 48;
			i++;
			n++;
		}
	}
	j = j + k / pow(10, n);
	return (j);
}

double			*ft_atod_safe_2(double *j)
{
	free(j);
	return (NULL);
}

double			*ft_atod_safe(char *str)
{
	double	*j;
	int		m;

	if (!(j = (double*)malloc(sizeof(double))))
		ft_error("Memory allocation failed.");
	*j = 0;
	if (str == '\0' || str == NULL)
		return (ft_atod_safe_2(j));
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\f'
			|| *str == '\r' || *str == '\v')
		str++;
	if (str[0] == '+' && ft_isdigit(str[1]) == 1)
		str++;
	if (*str == '-')
	{
		m = (-1);
		str++;
	}
	else
		m = 1;
	*j = ft_put_double(str, 0);
	*j = m * *j;
	return (j);
}

double			ft_atod(char *str)
{
	double	j;
	int		m;

	j = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\f'
			|| *str == '\r' || *str == '\v')
		str++;
	if (str[0] == '+' && ft_isdigit(str[1]) == 1)
		str++;
	if (*str == '-')
	{
		m = (-1);
		str++;
	}
	else
		m = 1;
	j = ft_put_double(str, 0);
	j = m * j;
	return (j);
}
