/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:25:06 by asavann           #+#    #+#             */
/*   Updated: 2018/04/12 20:33:44 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include "geometricobjects.h"

typedef struct	s_quadra
{
	double		a;
	double		b;
	double		c;
	double		disc;
	double		e;
	double		denom;
	t_vector3d	tmp;
	t_ray		r;
}				t_quadra;

void			sphere_set_center(t_sphere *sphere,\
		const double x, const double y, const double z);
void			sphere_set_radius(t_sphere *sphere, const double r);
int				spherehit(\
		const t_object *o, const t_ray ray, double *tmin, t_shaderec *sr);
int				spherehitshadow(\
		const t_object *o, const t_ray ray, float *tmin);
void			sphere_set_sampler(t_sphere *sphere, int ns);
t_point3d		sphere_sample(t_object *o);
float			sphere_pdf(t_object *o, t_shaderec *sr);
t_normal		sphere_get_normal(t_object *o, t_point3d *sp);
int				concavespherehit(\
		const t_object *o, const t_ray ray, double *tmin, t_shaderec *sr);
int				concavespherehitshadow(\
		const t_object *o, const t_ray ray, float *tmin);
#endif
