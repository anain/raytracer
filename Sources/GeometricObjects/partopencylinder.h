/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partopencylinder.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 15:52:00 by asavann           #+#    #+#             */
/*   Updated: 2018/04/22 18:22:43 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARTOPENCYLINDER_H
# define PARTOPENCYLINDER_H

# include "geometricobjects.h"

typedef struct	s_quadracp
{
	double		a;
	double		b;
	double		c;
	double		disc;
	double		e;
	double		denom;
	t_point2d	hit;
	double		ox;
	double		oy;
	double		oz;
	double		dx;
	double		dy;
	double		dz;
	t_vector3d	tmp;
	t_ray		r;
}				t_quadracp;

int				partopencylinderhit(const t_object *o,\
				const t_ray ray, double *tmin, t_shaderec *sr);
int				partopencylinderhitshadow(\
				const t_object *o, const t_ray ray, float *tmin);

#endif
