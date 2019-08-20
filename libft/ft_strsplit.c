/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <anain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:23:43 by anain             #+#    #+#             */
/*   Updated: 2017/12/20 15:34:24 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_jump(const char *str, char c, int start)
{
	while (str[start] == c)
		start++;
	return (start);
}

static	int		ft_count_words(const char *s, char c)
{
	int i;
	int n;

	i = 0;
	n = 0;
	if (s[0] != c)
		n = 1;
	while (s[i])
	{
		if (s[i] == c && !(s[i + 1] == c || s[i + 1] == '\0'))
			n++;
		i++;
	}
	return (n);
}

static	size_t	ft_length(const char *s, char c, int start)
{
	int l;

	l = 0;
	while (s[start] != c && s[start])
	{
		l++;
		start++;
	}
	return (l);
}

char			**ft_strsplit(const char *s, char c)
{
	char			**str;
	unsigned int	start;
	int				j;
	size_t			len;

	start = 0;
	j = 0;
	len = 0;
	str = 0;
	if (s == NULL)
		return (0);
	if (!(str = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1))))
		return (0);
	while (j < ft_count_words(s, c) && (s) && (*s))
	{
		start = ft_jump(s, c, start);
		len = ft_length(s, c, start);
		str[j] = ft_strsub(s, start, ft_length(s, c, start));
		start = start + ft_length(s, c, start);
		j++;
	}
	str[j] = 0;
	return (str);
}
