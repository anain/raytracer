/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:57:08 by asavann           #+#    #+#             */
/*   Updated: 2018/04/22 15:42:39 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "normal.h"

t_normal	normalmultmat(const t_matrix mat, const t_normal n)
{
	t_normal res;

	normalsetvalue(&res,
					mat.m[0][0] * n.x + mat.m[1][0] * n.y + mat.m[2][0] * n.z,
					mat.m[0][1] * n.x + mat.m[1][1] * n.y + mat.m[2][1] * n.z,
					mat.m[0][2] * n.x + mat.m[1][2] * n.y + mat.m[2][2] * n.z);
	return (res);
}

t_vector3d	normalsubvec(const t_normal *n, const t_vector3d v)
{
	t_vector3d	res;

	vector3dsetvalue(&res, v.x - n->x, v.y - n->y, v.z - n->z);
	return (res);
}
