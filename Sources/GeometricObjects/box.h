/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <anain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 18:51:21 by anain             #+#    #+#             */
/*   Updated: 2018/04/22 17:09:17 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOX_H
# define BOX_H

# include "../World/world.h"
# include "point3d.h"
# include "normal.h"
# include "../../libft/libft.h"

typedef struct	s_tminmax
{
	t_point3d	min;
	t_point3d	max;
}				t_tminmax;

typedef struct	s_face
{
	int			in;
	int			out;
}				t_face;

typedef struct	s_inter
{
	double		in;
	double		out;
}				t_inter;

int				boxhit(const t_object *o, const t_ray ray, double *tmin, \
					t_shaderec *sr);
int				boxhitshadow(const t_object *o, const t_ray ray,\
					float *tmin);
int				bboxhit(const t_object *o, const t_ray ray, double *tmin, \
					t_shaderec *sr);
t_normal		get_normal(int a);
void			init_val(t_tminmax *t, const t_box *box, t_point3d *param, \
					const t_ray ray);
void			init_points(t_point3d *or, t_point3d *param,\
					const t_ray ray);

#endif
