/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:30:03 by asavann           #+#    #+#             */
/*   Updated: 2018/04/22 15:40:40 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H
# define DEG2RAD PI / 180
# include <math.h>
# include "vector3d.h"
# include "constants.h"

typedef struct s_vector3d		t_vector3d;
typedef struct	s_matrix
{
	double m[4][4];
}				t_matrix;

t_vector3d		prod_vec3_matrx4(t_vector3d vec, t_matrix a);
t_matrix		prod_matrx4(t_matrix a, t_matrix b);
t_matrix		rotz_matrx4(float theta);
t_matrix		roty_matrx4(float theta);
t_matrix		rotx_matrx4(float theta);
t_matrix		transl_matrx4(float x, float y, float z);
t_matrix		id_matrx4(void);
t_matrix		new_matrx4(void);
void			round_matrx4(t_matrix *matrix);
void			matrixcpy(t_matrix *matrix, const t_matrix mat);
t_matrix		matrixequal(t_matrix *matrix, const t_matrix rhs);
t_matrix		matrixmult(const t_matrix *matrix, const t_matrix rhs);
t_matrix		matrixdiv(t_matrix *matrix, const double d);
void			set_identity(t_matrix *matrix);

#endif
