/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 12:29:27 by anain             #+#    #+#             */
/*   Updated: 2016/11/25 18:22:31 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_imintoa(void)
{
	char *str;

	str = ft_strdup("-2147483648");
	return (str);
}

char			*ft_itoa(int n)
{
	int					c;
	char				*str;
	unsigned int		m;

	c = 1;
	m = (n >= 0) ? n : -n;
	if (n == -2147483648)
		return (ft_imintoa());
	while (m / 10 >= 1)
	{
		c++;
		m = m / 10;
	}
	if (n >= 0)
		c--;
	if (!(str = (char *)malloc(sizeof(char) * (c + 2))))
		return (0);
	str[c + 1] = '\0';
	str[0] = (n >= 0) ? m : '-';
	while (c >= 0 && str[c] != '-')
	{
		str[c--] = n > 0 ? n % 10 + 48 : -n % 10 + 48;
		n = n / 10;
	}
	return (str);
}
