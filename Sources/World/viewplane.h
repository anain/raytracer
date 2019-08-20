/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewplane.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:14:54 by asavann           #+#    #+#             */
/*   Updated: 2018/04/22 15:03:25 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEWPLANE_H
# define VIEWPLANE_H
# include "../Utilities/rgbcolor.h"
# include "sampler.h"

typedef struct	s_viewplane
{
	int			hres;
	int			vres;
	int			win_width;
	int			win_height;
	float		s;
	int			numsamples;
	float		gamma;
	float		invgamma;
	int			show_out_of_gamut;
	int			max_depth;
	t_rgbcolor	background_color;
	t_sampler	sampler;
}				t_viewplane;

void			initviewplane(t_viewplane *v);
void			cpyviewplane(t_viewplane *v, const t_viewplane cpy);
t_viewplane		viewplaneeq(t_viewplane *v, const t_viewplane rhs);
void			set_hres(t_viewplane *v, const int hres);
void			set_vres(t_viewplane *v, const int vres);
void			set_size(t_viewplane *v, const float s);
void			set_sample(t_viewplane *v, const int n);
void			set_gamma(t_viewplane *v, const float gamma);
void			set_gamut(t_viewplane *v, const int show_out_of_gamut);
#endif
