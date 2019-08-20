/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 19:24:16 by asavann           #+#    #+#             */
/*   Updated: 2018/04/22 18:09:02 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RECTANGLE_H
# define RECTANGLE_H

# include "geometricobjects.h"

int			rectanglehit(const t_object *o, const t_ray ray, \
				double *tmin, t_shaderec *sr);
int			rectanglehitshadow(const t_object *o, const t_ray ray, float *tmin);
t_point3d	rect_sample(t_object *o);
t_normal	rect_get_normal(t_object *o, t_point3d *sp);
void		rect_set_sampler(t_rectangle *rectangle, int ns);
float		rect_pdf(t_object *o, t_shaderec *sr);
#endif
