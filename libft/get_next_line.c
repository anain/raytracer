/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <anain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 18:15:55 by anain             #+#    #+#             */
/*   Updated: 2017/12/19 17:13:45 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strjoin_free(char *s1, char *s2)
{
	char *str;

	if (!(str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + BUFF_SIZE + 1))))
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	ft_strdel(&s1);
	return (str);
}

static char	*ft_fill_line(int fd, char **line, char *str, char *buff)
{
	int		ret;
	int		i;
	char	*tmp;

	i = 0;
	ret = 2;
	while (ft_strstr(str, "\n") == 0 && ret != 0)
	{
		if ((ret = read(fd, buff, BUFF_SIZE)) == -1)
			return (NULL);
		buff[ret] = '\0';
		if ((str = ft_strjoin_free(str, buff)) == NULL)
			return (NULL);
	}
	if (buff != NULL)
		ft_strdel(&buff);
	while (str[i] != '\n' && str[i])
		i++;
	if ((*line = ft_strsub(str, 0, i)) == NULL)
		return (NULL);
	tmp = ft_strsub(str, i + 1, ft_strlen(str) - i);
	ft_strdel(&str);
	return (tmp);
}

static void	ft_end(char **buff, char **str)
{
	if (buff)
		ft_strdel(buff);
	ft_strdel(str);
}

int			get_next_line(const int fd, char **line)
{
	char		*buff;
	int			ret;
	static char *str;

	if (fd < 0 || BUFF_SIZE <= 0 ||
	(!str && (str = ft_strnew(0)) == 0) || !line)
		return (-1);
	buff = NULL;
	if (ft_strstr(str, "\n") == 0)
	{
		if ((buff = ft_strnew(BUFF_SIZE)) == 0 ||
		(ret = read(fd, buff, BUFF_SIZE)) < 0)
			return (-1);
		if (ret == 0 && ft_strlen(str) == 0)
		{
			ft_end(&buff, &str);
			return (0);
		}
		buff[ret] = '\0';
		if ((str = ft_strjoin_free(str, buff)) == NULL)
			return (-1);
	}
	if ((str = ft_fill_line(fd, line, str, buff)) == NULL)
		return (-1);
	return (1);
}
