/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noise.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <anain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 18:11:11 by anain             #+#    #+#             */
/*   Updated: 2018/04/21 23:45:13 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_NOISE_H
# define SET_NOISE_H

# include "camera.h"
# include <math.h>
# include "point3d.h"
# include "shaderec.h"
# include "rgbcolor.h"
# include "material.h"
# include "chess.h"

typedef struct		s_intpt
{
	int x;
	int y;
	int z;

}					t_intpt;

typedef struct		s_intpt2
{
	t_intpt i;
	t_intpt k;
}					t_intpt2;

void				init_floornoise(t_shaderec *sr, t_intpt2 *p);
int					ft_index(int ix, int iy, int iz, t_world *w);
t_rgbcolor			set_noise(t_shaderec *sr);
int					perm(int k, t_world *w);
float				turbulence(t_shaderec *sr);
float				linear_noise(t_shaderec *sr);
float				cubic_noise(t_shaderec *sr);
float				fractalsum(t_shaderec *sr);
float				lerp1(float x, float a, float b);
void				init_value_table(t_latticenoise *latticenoise);
float				fbm(t_shaderec *sr);

#endif
