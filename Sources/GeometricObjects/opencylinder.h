/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opencylinder.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 18:08:54 by asavann           #+#    #+#             */
/*   Updated: 2017/12/11 15:46:46 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPENCYLINDER_H
# define OPENCYLINDER_H

# include "geometricobjects.h"

typedef struct	s_quadrac
{
	double		a;
	double		b;
	double		c;
	double		disc;
	double		e;
	double		denom;
	double		yhit;
	double		ox;
	double		oy;
	double		oz;
	double		dx;
	double		dy;
	double		dz;
	t_vector3d	tmp;
	t_ray		r;
}				t_quadrac;

void			opencylinder_init(t_opencylinder *c, const double r, \
				const double bottom, const double top);
int				opencylinderhit(\
				const t_object *o, const t_ray ray, double *tmin,\
				t_shaderec *sr);
int				opencylinderhitshadow(\
				const t_object *o, const t_ray ray, float *tmin);

#endif
