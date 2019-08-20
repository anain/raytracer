/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <anain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 17:42:58 by anain             #+#    #+#             */
/*   Updated: 2016/12/03 20:12:57 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t		i;
	char		*str;
	size_t		n;

	i = 0;
	n = 0;
	str = 0;
	if (!s || !*s)
		return ("");
	n = ft_strlen((char *)s) - 1;
	while (ft_isspace(s[i]) == 1)
		i++;
	while (ft_isspace(s[n]) == 1 && n >= i)
		n--;
	if (n == i)
		return (0);
	if (!(str = (char *)malloc(sizeof(char) * (n + 1))))
		return (0);
	if (!str)
		return (0);
	str = ft_strsub(s, i, n - i + 1);
	if (str == 0 || !str)
		return ("");
	return (str);
}
