/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 13:56:03 by jorobin           #+#    #+#             */
/*   Updated: 2018/04/21 19:04:08 by jorobin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mmlx.h"
#include <math.h>
#include <unistd.h>

void	get_textures(t_param *p, t_tex *tex, char *path)
{
	if (!(tex->marb_add = mlx_xpm_file_to_image(p->mlx, path,\
					&tex->marb_sizex, &tex->marb_sizey)))
	{
		ft_putstr("xpm to image fail\n");
		exit(0);
	}
	if (!(tex->marb_data = mlx_get_data_addr(tex->marb_add,\
					&tex->marb_bpp, &tex->marb_size_l, &p->endian)))
	{
		ft_putstr("data address fail\n");
		exit(0);
	}
}
