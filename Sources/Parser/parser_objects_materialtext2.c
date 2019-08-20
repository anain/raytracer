/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_objects_materialtext2.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <anain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 15:37:55 by anain             #+#    #+#             */
/*   Updated: 2018/04/24 22:16:57 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	print_xmltext_usage(void)
{
	ft_putstr("XML ERROR : TEXTURE NODE\n--------------------------\n");
	ft_putstr("<pattern> BANK PATTERN </pattern>\n \t\tOR \n");
	ft_putstr("<source> PATH TO XPM FILE </source>\n");
	ft_putstr("if the object is a sphere add a <mapping> type.\n");
	ft_putstr("-----------------------------------------------------\n");
	ft_putstr("PATTERNS : bois - grass - paper - marble - atlantic - desert");
	ft_putstr(" - light sky\n");
	ft_error("--------------------------\n");
}

void	texture_bank2(t_material *mat)
{
	if (mat->tex.path == NULL)
	{
		ft_putstr("Unknown pattern\n");
		print_xmltext_usage();
	}
}

void	texture_bank(t_material *mat, char *pattern)
{
	char	*bank[5];
	char	*path[5];
	int		i;

	i = -1;
	bank[0] = "bois";
	bank[1] = "grass";
	bank[2] = "marble";
	bank[3] = "light sky";
	bank[4] = "atlantic";
	path[0] = "Sources/Textures/XPM/bois.xpm";
	path[1] = "Sources/Textures/XPM/grass.xpm";
	path[2] = "Sources/Textures/XPM/marble.xpm";
	path[3] = "Sources/Textures/XPM/sky_lightblue.xpm";
	path[4] = "Sources/Textures/XPM/atlantic_skybox.xpm";
	if (pattern == NULL)
		ft_error("Error in the definition of a pattern texture.\n");
	while (++i < 5)
	{
		if (ft_strcmp(pattern, bank[i]) == 0)
			mat->tex.path = path[i];
	}
	texture_bank2(mat);
}
