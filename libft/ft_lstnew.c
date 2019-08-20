/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <anain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 18:41:36 by anain             #+#    #+#             */
/*   Updated: 2016/12/10 16:41:40 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lstnew;

	if (!(lstnew = (void *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		lstnew->content = NULL;
		lstnew->content_size = 0;
	}
	else
	{
		if (!(lstnew->content = (void *)malloc(sizeof(content_size))))
			return (0);
		ft_memcpy(lstnew->content, content, content_size);
		lstnew->content_size = content_size;
		lstnew->next = NULL;
	}
	return (lstnew);
}
