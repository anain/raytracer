/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 18:21:52 by asavann           #+#    #+#             */
/*   Updated: 2018/04/24 23:57:42 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mmlx.h"
#include "camera.h"
#include "libft.h"
#include "parsing.h"
#include "noise.h"
#include "chess.h"

static void		perm_table(t_world *world)
{
	int i;
	int *tab;

	i = -1;
	tab = (int[256])
	{225, 155, 210, 108, 175, 199, 221, 144, 203, 116, 70, 213, 69, 158, 33,\
	252, 5, 82, 173, 133, 222, 139, 174, 27, 9, 71, 90, 246, 75, 130, 91, 191,\
	169, 138, 2, 151, 194, 235, 81, 7, 25, 113, 228, 159, 205, 253, 134, 142, \
	248, 65, 224, 217, 22, 121, 229, 63, 89, 103, 96, 104, 156, 17, 201, 129, \
	36, 8, 165, 110, 237, 117, 231, 56, 132, 211, 152, 20, 181, 111, 239, 218, \
	170, 163, 51, 172, 157, 47, 80, 212, 176, 250, 87, 49, 99, 242, 136, 189, \
	162, 115, 44, 43, 124, 94, 150, 16, 141, 247, 32, 10, 198, 223, 255, 72, \
	53, 131, 84, 57, 220, 197, 58, 50, 208, 11, 241, 28, 3, 192, 62, 202, \
	18, 215, 153, 24, 76, 41, 15, 179, 39, 46, 55, 6, 128, 167, 23, 188, \
	106, 34, 187, 140, 164, 73, 112, 182, 244, 195, 227, 13, 35, 77, 196, 185, \
	26, 200, 226, 119, 31, 123, 168, 125, 249, 68, 183, 230, 177, 135, 160, \
	180, 12, 1, 243, 148, 102, 166, 38, 238, 251, 37, 240, 126, 64, 74, 161, \
	40, 184, 149, 171, 178, 101, 66, 29, 59, 146, 61, 254, 107, 42, 86, 154, \
	4, 236, 232, 120, 21, 233, 209, 45, 98, 193, 114, 78, 19, 206, 14, 118, \
	127, 48, 79, 147, 85, 30, 207, 219, 54, 88, 234, 190, 122, 95, 67, 143, \
	109, 137, 214, 145, 93, 92, 100, 245, 0, 216, 186, 60, 83, 105, 97, \
	204, 52};
	while (++i < 256)
		world->permt[i] = tab[i];
}

void			fill_p(t_param *p)
{
	p->menu = 0;
	p->menobj = 0;
	p->screencap = NULL;
	p->filter = NONE;
}

int				main(int argc, char **argv)
{
	t_param		p;
	int			fd;
	t_object	*textobj;

	if (argc < 2)
		ft_error("File descriptor not found.\n");
	if (argc > 2)
		ft_putstr("Warning : only the first file descriptor will be read.\n");
	worldbuild(&p.world, argv[1]);
	open_window(&p);
	perm_table(&p.world);
	textobj = p.world.object;
	while (p.world.object != NULL)
	{
		if (p.world.object->mat.tex.path != NULL)
			get_textures(&p, &p.world.object->mat.tex, \
				p.world.object->mat.tex.path);
		p.world.object = p.world.object->next;
	}
	p.world.object = textobj;
	fill_p(&p);
	th_render(&p);
	loop_minilibx(&p);
	return (0);
}
