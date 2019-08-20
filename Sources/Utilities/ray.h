/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:06:26 by asavann           #+#    #+#             */
/*   Updated: 2017/11/10 17:32:49 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "point3d.h"
# include "vector3d.h"

typedef struct	s_ray
{
	t_point3d	o;
	t_vector3d	d;
}				t_ray;

/*
** Default contructor
*/

void			rayinit(t_ray *ray);

/*
** Constructor
*/

void			raysetvalue(t_ray *ray, const t_point3d origin,
				const t_vector3d dir);

/*
** Copy constructor
*/

void			raycopy(t_ray *ray, const t_ray rhs);

/*
** Assignment
*/

t_ray			rayeq(t_ray *ray, const t_ray rhs);
#endif
