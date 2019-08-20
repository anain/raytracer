/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mickey2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <anain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 22:29:20 by anain             #+#    #+#             */
/*   Updated: 2018/04/23 17:21:07 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void		ft_mickey_error(void)
{
	ft_putstr("XML ERROR : MICKEY NODE\n--------------------------\n<cen");
	ft_putstr("ter> { X, Y, Z } </center>\n<radius> RADIUS");
	ft_putstr(" </radius>\n");
	ft_putstr("--------------------------\n");
	ft_putstr("Radius must be > 0 && < int max\n");
	ft_error("Mickey center at { 0, 0, 0 }!\n");
}
