/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transparence.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <anain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 18:56:30 by anain             #+#    #+#             */
/*   Updated: 2018/04/22 13:12:26 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSPARENCE_H
# define TRANSPARENCE_H

# include "material.h"
# include "matte.h"
# include "world.h"
# include <math.h>

typedef struct		s_transparam
{
	t_vector3d		wo;
	t_vector3d		wi;
	t_vector3d		wt;
	t_rgbcolor		fr;
	t_rgbcolor		ft;
	t_ray			reflected_ray;
	t_ray			transmitted_ray;
}					t_transparam;

t_rgbcolor			shadephong(t_material *m, t_shaderec *sr);
t_rgbcolor			sample_f(t_perfectspecular *perf, const t_shaderec sr, \
						const t_vector3d wo, t_vector3d *wi);
t_rgbcolor			reflective(t_material *m, t_shaderec *sr);
int					transmitter_tir(const t_shaderec *sr, t_material *m);
t_rgbcolor			sample_ft(t_transparence *perft, const t_shaderec sr, \
						const t_vector3d wo, t_vector3d *wt);
t_rgbcolor			shadetransp(t_material *m, t_shaderec *sr);
t_rgbcolor			pathtransp(t_material *m, t_shaderec *sr);

#endif
