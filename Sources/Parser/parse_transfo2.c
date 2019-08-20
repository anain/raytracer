/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_transfo2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <anain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 14:55:35 by anain             #+#    #+#             */
/*   Updated: 2018/04/24 22:20:55 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	print_xmltransfo_usage(void)
{
	ft_putstr("XML ERROR : TRANSFORMATION NODE\n--------------------------\n");
	ft_putstr("<transformation_type>a b c</transformation_type>\n");
	ft_putstr("transformation_type : ");
	ft_putstr("\'rotation\' or \'translation\' or \'scaling\'\n");
	ft_putstr("a, b, c : value (double) of the transformation for x, y, z.");
	ft_error("--------------------------\n");
}

void	transformation(xmlDocPtr doc, t_object *o,\
			xmlNodePtr transfonode)
{
	parserot(doc, o, transfonode);
	parsetranslate(doc, o, transfonode);
	parsescale(doc, o, transfonode);
}
