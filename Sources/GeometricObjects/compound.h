/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compound.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <anain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 15:02:23 by anain             #+#    #+#             */
/*   Updated: 2018/04/22 17:17:15 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPOUND_H
# define COMPOUND_H

# include "geometricobjects.h"
# include "point3d.h"
# include "normal.h"
# include "../../libft/libft.h"

typedef struct	s_compvar
{
	double		t;
	t_normal	normal;
	t_point3d	local_hit_point;
	int			hit;
	t_object	*head;
}				t_compvar;

int				compoundhit(const t_object *o, const t_ray ray, double *tmin,\
					t_shaderec *sr);

int				compoundhitshadow(const t_object *o, const t_ray ray, \
					float *tmin);
#endif
