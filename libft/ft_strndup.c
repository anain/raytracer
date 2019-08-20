/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <anain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 01:22:28 by anain             #+#    #+#             */
/*   Updated: 2017/04/11 19:14:27 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * ft_strlen(src) + 1)))
		return (0);
	while (src[i] != '\0' && i < n)
	{
		str[i] = src[i];
		i++;
	}
	if (ft_strlen((char *)src) < n)
	{
		while (i < n)
		{
			str[i] = '\0';
			i++;
		}
	}
	str[i] = '\0';
	return (str);
}
