/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:23:37 by asavann           #+#    #+#             */
/*   Updated: 2017/12/01 19:29:09 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H

# include "geometricobjects.h"

/*
** Default Constructor
*/

void			planeinit(t_plane *plane);
int				planehit(const t_object *o, const t_ray ray, double *tmin, \
				t_shaderec *sr);
int				planehitshadow(const t_object *o, const t_ray ray, float *tmin);
#endif
