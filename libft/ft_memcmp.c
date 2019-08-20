/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:38:11 by anain             #+#    #+#             */
/*   Updated: 2016/11/25 13:44:48 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *p1, const void *p2, size_t n)
{
	size_t	i;
	char	*s1;
	char	*s2;

	s1 = (char *)p1;
	s2 = (char *)p2;
	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
