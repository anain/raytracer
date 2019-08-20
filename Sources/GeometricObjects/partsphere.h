/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partsphere.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 16:58:03 by asavann           #+#    #+#             */
/*   Updated: 2018/04/22 18:09:50 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARTSPHERE_H
# define PARTSPHERE_H

# include "geometricobjects.h"
# include "sphere.h"

int				partspherehit(\
		const t_object *o, const t_ray ray, double *tmin, t_shaderec *sr);
int				partspherehitshadow(\
		const t_object *o, const t_ray ray, float *tmin);

#endif
