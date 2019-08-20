/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <anain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 15:39:40 by anain             #+#    #+#             */
/*   Updated: 2018/04/22 15:41:15 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_vector3d			prod_vec3_matrx4(t_vector3d vec, t_matrix a)
{
	t_vector3d		ret;

	ret.x = vec.x * a.m[0][0] + vec.y * a.m[0][1] + vec.z * a.m[0][2] \
		+ a.m[0][3];
	ret.y = vec.x * a.m[1][0] + vec.y * a.m[1][1] + vec.z * a.m[1][2] \
		+ a.m[1][3];
	ret.z = vec.x * a.m[2][0] + vec.y * a.m[2][1] + vec.z * a.m[2][2] \
		+ a.m[2][3];
	return (ret);
}
