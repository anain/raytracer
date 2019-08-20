/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_objects_material_usage.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <anain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 17:32:00 by anain             #+#    #+#             */
/*   Updated: 2018/04/14 15:25:21 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	print_xmlmatte_usage(void)
{
	ft_putstr("XML ERROR : MATTE (MATERIAL) NODE\n------------------------\n");
	ft_putstr("<ambient_coef> COEFFICIENT (0-1) </ambient_coef>\n");
	ft_putstr("<diffuse_coef> COEFFICIENT (0-1) </diffuse_coef>\n");
	ft_putstr("<numsamples> NUMBER OF SAMPLES (path tracing) </numsamples>\n");
	ft_putstr("<color> R G B </color>\n");
	ft_error("--------------------------\n");
}

void	print_xmlphong_usage(void)
{
	ft_putstr("XML ERROR : PHONG (MATERIAL) NODE\n------------------------\n");
	ft_putstr("<ambient_coef> COEFFICIENT (0-1) </ambient_coef>\n");
	ft_putstr("<diffuse_coef> COEFFICIENT (0-1) </diffuse_coef>\n");
	ft_putstr("<numsamples> NUMBER OF SAMPLES (path tracing) </numsamples>\n");
	ft_putstr("<color> R G B </color>\n");
	ft_putstr("<glossy_coef> COEFFICIENT (0-1) </glossy_coef>\n");
	ft_putstr("<glossy_color> R G B </glossy_color>\n");
	ft_putstr("<exp> LEVEL OF BRIGHTNESS </exp>\n");
	ft_error("--------------------------\n");
}

void	print_xmlreflective_usage(void)
{
	ft_putstr("XML ERROR : REFLECTIVE (MATERIAL) NODE\n--------------------\n");
	ft_putstr("<ambient_coef> COEFFICIENT (0-1) </ambient_coef>\n");
	ft_putstr("<diffuse_coef> COEFFICIENT (0-1) </diffuse_coef>\n");
	ft_putstr("<color> R G B </color>\n");
	ft_putstr("<glossy_coef> COEFFICIENT (0-1) </glossy_coef>\n");
	ft_putstr("<glossy_color> R G B </glossy_color>\n");
	ft_putstr("<exp> LEVEL OF BRIGHTNESS </exp>\n");
	ft_putstr("<reflective_coef> COEFFICIENT (0-1) </reflective_coef>\n");
	ft_putstr("<reflective_color> R G B </reflective_color>\n");
	ft_error("--------------------------\n");
}

void	print_xmltransparence_usage(void)
{
	ft_putstr("XML ERROR : TRANSPARENCE (MATERIAL) NODE\n------------------\n");
	ft_putstr("<ambient_coef> COEFFICIENT (0-1) </ambient_coef>\n");
	ft_putstr("<diffuse_coef> COEFFICIENT (0-1) </diffuse_coef>\n");
	ft_putstr("<color> R G B </color>\n");
	ft_putstr("<glossy_coef> COEFFICIENT (0-1) </glossy_coef>\n");
	ft_putstr("<glossy_color> R G B </glossy_color>\n");
	ft_putstr("<exp> LEVEL OF BRIGHTNESS </exp>\n");
	ft_putstr("<reflective_color> R G B </reflective_color>\n");
	ft_putstr("<reflective_coef> COEFFICIENT (0-1) </reflective_coef>\n");
	ft_putstr("<transparence_coef> COEFFICIENT (0-1) </transparence_coef>\n");
	ft_putstr("constraint : reflective coef + transparence_coef = 1\n");
	ft_putstr("<ior> REFRACTIVE INDEX </ior>\n");
	ft_error("--------------------------\n");
}
