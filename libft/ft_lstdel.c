/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <anain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 16:27:55 by anain             #+#    #+#             */
/*   Updated: 2016/12/10 16:55:04 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (*alst && alst)
	{
		while ((*alst) != NULL)
		{
			(*del)((*alst)->content, (*alst)->content_size);
			free(*alst);
			(*alst) = (*alst)->next;
		}
		alst = NULL;
	}
}
