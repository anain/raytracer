/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infcone.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 15:36:27 by asavann           #+#    #+#             */
/*   Updated: 2018/04/22 21:56:13 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFCONE_H
# define INFCONE_H

# include "geometricobjects.h"

void			infcone_init(t_infcone *c, const double r, \
				const double heihgt);
int				infconehit(const t_object *o, const t_ray ray, double *tmin,\
				t_shaderec *sr);
int				infconehitshadow(\
				const t_object *o, const t_ray ray, float *tmin);
#endif
