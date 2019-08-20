/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:21:34 by anain             #+#    #+#             */
/*   Updated: 2016/11/27 17:25:21 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen((char *)s);
	if (ft_strlen(s) == 0 && c != '\0')
	{
		if (c == 0)
			return ("");
		return (0);
	}
	while (i >= 0)
	{
		if (s[i] == c)
		{
			s = &s[i];
			return ((char *)s);
		}
		i--;
	}
	return (0);
}
