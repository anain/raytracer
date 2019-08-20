/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lambertian.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:00:07 by asavann           #+#    #+#             */
/*   Updated: 2017/12/07 21:37:36 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brdf.h"
#include "constants.h"

void			lambinit(t_lambertian *lamb)
{
	lamb->kd = 0;
	rgbsetvalue(&lamb->cd, 0, 0, 0);
}

void			lambcopy(t_lambertian *lamb, const t_lambertian cpy)
{
	rgbcopy(&lamb->cd, cpy.cd);
	lamb->kd = cpy.kd;
}

t_lambertian	lambnew(t_lambertian *lamb)
{
	t_lambertian dest;

	lambcopy(&dest, *lamb);
	return (dest);
}

t_lambertian	lambeq(t_lambertian *lamb, const t_lambertian rhs)
{
	lambcopy(lamb, rhs);
	return (*lamb);
}

t_rgbcolor		lambf(t_lambertian *lamb)
{
	t_rgbcolor f;

	f = rgbmult(&lamb->cd, lamb->kd);
	f = rgbmult(&f, INVPI);
	return (f);
}
