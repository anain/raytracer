/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 16:41:03 by anain             #+#    #+#             */
/*   Updated: 2016/11/25 12:00:58 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *str, char *to_find, size_t len)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	if (to_find[i] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		k = i;
		j = 0;
		while (str[i] == to_find[j] && i < len)
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
