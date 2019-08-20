/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 11:00:02 by anain             #+#    #+#             */
/*   Updated: 2016/11/24 19:01:17 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	m;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		m = -n;
	}
	else
		m = n;
	if (m <= 9)
		ft_putchar_fd(m + '0', fd);
	else
	{
		ft_putnbr_fd(m / 10, fd);
		ft_putchar_fd((m % 10) + '0', fd);
	}
}
