/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_limcone2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 22:27:58 by asavann           #+#    #+#             */
/*   Updated: 2018/04/24 22:45:01 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "limcone.h"

void	ft_limcone_error(void)
{
	ft_putstr("XML ERROR : LIMCONE NODE\n--------------------------\n<hei");
	ft_putstr("ght> HEIGHT </height>\n<radius> RADIUS");
	ft_putstr(" </radius>\n");
	ft_putstr("<top> TOP </top>\n");
	ft_putstr("<bottom> BOTTOM </bottom>\n");
	ft_error("--------------------------\n");
}

void	set_limcone6(t_object *object)
{
	object->lcone.kepsilon = 0.00001;
	object->lcone.invradius = 1 / object->lcone.radius;
	object->d = (t_point3d) {0, 0, 0};
	object->shadow = 1;
	object->hittrans = limconehit;
	object->shadow_hittrans = limconehitshadow;
}
