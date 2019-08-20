/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <anain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 01:22:28 by anain             #+#    #+#             */
/*   Updated: 2018/02/09 17:06:53 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strdup(const char *src)
{
	char	*str;
	int		i;

	i = 0;
	if (src == NULL)
		return (NULL);
	else if (!(str = (char *)malloc(sizeof(char) * ft_strlen(src) + 1)))
		return (0);
	while (src[i] != '\0')
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
