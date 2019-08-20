/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3d5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:51:37 by asavann           #+#    #+#             */
/*   Updated: 2018/04/22 15:45:49 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3d.h"
#include "normal.h"

/*
** Return multiplication by a matrix on the left
*/

t_vector3d		matxvectord3d(const t_matrix mat, const t_vector3d v)
{
	t_vector3d	res;

	vector3dsetvalue(&res,
		mat.m[0][0] * v.x + mat.m[0][1] * v.y + mat.m[0][2] * v.z,
		mat.m[1][0] * v.x + mat.m[1][1] * v.y + mat.m[1][2] * v.z,
		mat.m[2][0] * v.x + mat.m[2][1] * v.y + mat.m[2][2] * v.z);
	return (res);
}

/*
** Return subtraction of a vector from a normal
*/

t_vector3d		vecsubnormal(const t_normal n, const t_vector3d v)
{
	t_vector3d	res;

	vector3dsetvalue(&res, n.x - v.x, n.y - v.y, n.z - v.z);
	return (res);
}
