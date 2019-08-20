/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr_caseins.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <anain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 12:16:09 by anain             #+#    #+#             */
/*   Updated: 2018/02/08 13:51:13 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr_caseins(char *str, char *to_find)
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
		while (str[i] == to_find[j] || ft_tolower(str[i]) == to_find[j])
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
