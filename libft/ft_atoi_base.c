/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <anain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 19:16:13 by anain             #+#    #+#             */
/*   Updated: 2017/12/18 19:32:04 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_put_number(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		j = j * 10 + str[i] - 48;
		i++;
	}
	return (j);
}

int			ft_atoi(char *str)
{
	int		j;
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
	j = ft_put_number(str);
	j = m * j;
	return (j);
}
