/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paraboloid.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 15:46:08 by majulien          #+#    #+#             */
/*   Updated: 2018/04/22 18:02:25 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARABOLOID_H
# define PARABOLOID_H
# include "geometricobjects.h"

typedef struct		s_quad
{
	double			a;
	double			b;
	double			c;
	double			disc;
	double			e;
	double			denom;
	t_vector3d		tmp;
	t_ray			r;
}					t_quad;

int					paraboloidhit(const t_object *o, const t_ray ray,\
		double *tmin, t_shaderec *sr);
int					quadsolution(t_quad q, const t_paraboloid *paraboloid,\
		double *tmin, t_shaderec *sr);
int					paraboloidhitshadow(const t_object *o, const t_ray ray,\
		float *tmin);
int					quadsolutionshadow(t_quad q, \
		const t_paraboloid *paraboloid, float *tmin);
#endif
