/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 12:16:09 by anain             #+#    #+#             */
/*   Updated: 2016/11/17 12:21:15 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;
	int k;

	i = 0;
	if (to_find[i] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		k = i;
		j = 0;
		while (str[i] == to_find[j])
		{
			i++;
			j++;
			if (to_find[j] == '\0')
				return (str + i - j);
		}
		i = k;
		i++;
	}
	return (0);
}
