/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <anain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 12:21:56 by anain             #+#    #+#             */
/*   Updated: 2016/12/16 13:25:14 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t i;

	i = 0;
	while (src[i] != 0 && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	if (ft_strlen((char *)src) < n)
	{
		while (i < n)
		{
			dest[i] = '\0';
			i++;
		}
	}
	return (dest);
}
