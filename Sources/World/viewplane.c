/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewplane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:30:22 by asavann           #+#    #+#             */
/*   Updated: 2017/11/16 19:24:31 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "viewplane.h"

/*
** Default constructor
*/

void		viewplaneinit(t_viewplane *v)
{
	v->hres = 400;
	v->vres = 400;
	v->s = 1.0;
	v->numsamples = 1;
	v->gamma = 1.0;
	v->invgamma = 1.0;
	v->show_out_of_gamut = 0;
}

/*
** Copy constructor
*/

void		cpyviewplane(t_viewplane *v, const t_viewplane cpy)
{
	v->hres = cpy.hres;
	v->vres = cpy.vres;
	v->s = cpy.s;
	v->numsamples = cpy.numsamples;
	v->gamma = cpy.gamma;
	v->invgamma = cpy.invgamma;
	v->show_out_of_gamut = cpy.show_out_of_gamut;
}

/*
** Assign viewplane
*/

t_viewplane	viewplaneeq(t_viewplane *v, const t_viewplane rhs)
{
	if (v == &rhs)
		return (*v);
	v->hres = rhs.hres;
	v->vres = rhs.vres;
	v->s = rhs.s;
	v->numsamples = rhs.numsamples;
	v->gamma = rhs.gamma;
	v->invgamma = rhs.invgamma;
	v->show_out_of_gamut = rhs.show_out_of_gamut;
	return (*v);
}

/*
** Set hres
*/

void		set_hres(t_viewplane *v, const int hres)
{
	v->hres = hres;
}

/*
** Set vres
*/

void		set_vres(t_viewplane *v, const int vres)
{
	v->vres = vres;
}
