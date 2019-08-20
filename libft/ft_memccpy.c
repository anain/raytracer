/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 17:12:22 by anain             #+#    #+#             */
/*   Updated: 2016/11/27 13:54:05 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*csrc;
	unsigned char	*cdest;

	csrc = (unsigned char *)src;
	cdest = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		cdest[i] = csrc[i];
		if (csrc[i] == (unsigned char)c)
			return (&cdest[i + 1]);
		i++;
	}
	return (0);
}
