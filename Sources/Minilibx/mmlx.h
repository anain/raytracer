/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mmlx.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 18:26:46 by asavann           #+#    #+#             */
/*   Updated: 2018/04/24 17:44:23 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MMLX_H
# define MMLX_H

# include "world.h"
# include "material.h"
# include "point2d.h"
# include "mlx.h"
# include "events.h"
# include "../../libft/libft.h"
# include <pthread.h>

typedef struct	s_param
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	char		*name;
	int			bpp;
	int			size_l;
	int			endian;
	int			menu;
	int			menobj;
	int			filter;
	t_rgbcolor	*screencap;
	t_rendervar v;
	t_world		world;
	int			r;
}				t_param;

void			pixel_draw(t_param *e, int x, int y, t_rgbcolor *color);
void			rot_mickey(t_object *o, int rot, char dir);
void			move_objects4(int keycode, t_object *o);
void			move_objects5(int keycode, t_object *o);
void			move_objects6(int keycode, t_object *o);
void			move_objects7(int keycode, t_object *o);
int				mouse_input(int keycode, int x, int y, t_param *e);
void			fill_screencap(t_param *p);
void			allocate_screencap(t_param *p);
void			open_window(t_param *p);
void			loop_minilibx(t_param *e);
void			display_pixel(t_param *p, const int row, const int column, \
				const t_rgbcolor pixel_color);
void			display_res(t_param *p, const int row, const int column, \
				const t_rgbcolor pixel_color);
void			render_scene(t_param *p);
void			get_textures(t_param *p, t_tex *tex, char *path);
t_rgbcolor		max_to_one(const t_rgbcolor c);
int				ft_exit(t_param *e);
#endif
