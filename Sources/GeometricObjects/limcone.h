/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limcone.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 19:54:37 by asavann           #+#    #+#             */
/*   Updated: 2018/04/22 21:56:17 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIMCONE_H
# define LIMCONE_H

# include "geometricobjects.h"

int			limconehit(\
		const t_object *o, const t_ray ray, double *tmin, t_shaderec *sr);
int			limconehitshadow(\
		const t_object *o, const t_ray ray, float *tmin);
#endif
