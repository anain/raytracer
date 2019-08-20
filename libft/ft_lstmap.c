/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <anain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 12:05:08 by anain             #+#    #+#             */
/*   Updated: 2016/12/19 15:50:21 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newel;
	t_list	*first;
	t_list	*tmp;

	if (!f || !lst)
		return (NULL);
	newel = (*f)(lst);
	lst = lst->next;
	first = newel;
	while (lst)
	{
		tmp = (*f)(lst);
		newel->next = tmp;
		newel = newel->next;
		lst = lst->next;
	}
	return (first);
}
