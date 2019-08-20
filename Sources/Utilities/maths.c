/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 20:27:30 by asavann           #+#    #+#             */
/*   Updated: 2018/04/22 15:21:35 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths.h"
#include <stdlib.h>

double	max(double x0, double x1)
{
	return ((x0 > x1) ? x0 : x1);
}

float	rand_float(void)
{
	float invrandmax;

	invrandmax = 1.0 / (float)RAND_MAX;
	return (rand() * invrandmax);
}

float	rand_floatarg(int l, float h)
{
	return (rand_float() * (h - l) + l);
}

int		rand_arg(int l, int h)
{
	return ((int)(rand_floatarg(0, h - l + 1) + l));
}
