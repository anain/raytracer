/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <anain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 17:08:54 by anain             #+#    #+#             */
/*   Updated: 2016/12/03 20:18:39 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char *csrc;
	char *cdest;

	csrc = (char *)src;
	cdest = (char *)dest;
	if (src > dest)
		dest = ft_memcpy(dest, src, n);
	else
	{
		while (n--)
		{
			cdest[n] = csrc[n];
		}
	}
	dest = (void *)cdest;
	return (dest);
}
