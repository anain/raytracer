/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_triangle2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <anain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 22:43:51 by anain             #+#    #+#             */
/*   Updated: 2018/04/24 22:45:19 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_triangle_error(void)
{
	ft_putstr("XML ERROR : TRIANGLE NODE\n--------------------------\n<vert");
	ft_putstr("ice_1> { X, Y, Z } </vertice_1>\n<vertice_2> { X, Y, ");
	ft_putstr("Z } </vertice_2>\n<vertice_3> { X, Y, Z } </vertice_3>\n");
	ft_error("--------------------------\n");
}
