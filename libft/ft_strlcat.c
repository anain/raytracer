/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <anain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 17:34:33 by anain             #+#    #+#             */
/*   Updated: 2016/12/02 15:29:42 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t k;
	size_t l;

	k = ft_strlen(dest);
	l = ft_strlen(src);
	i = k;
	j = 0;
	if (k < size)
	{
		while (src[j] != 0 && i < size - 1)
		{
			dest[i] = src[j];
			i++;
			j++;
		}
		dest[i] = '\0';
		return (l + k);
	}
	else
		return (l + size);
}
