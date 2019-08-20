/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorobin <jorobin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:09:22 by jorobin           #+#    #+#             */
/*   Updated: 2018/04/22 17:23:24 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIANGLE_H
# define TRIANGLE_H

# include "../Utilities/point3d.h"
# include <stdlib.h>
# include "../Utilities/normal.h"

typedef struct		s_triangle
{
	t_point3d		v0;
	t_point3d		v1;
	t_point3d		v2;
	t_normal		normal;
}					t_triangle;

typedef struct		s_trivar
{
	double			kepsilon;
	double			a;
	double			b;
	double			c;
	double			d;
	double			e;
	double			f;
	double			g;
	double			h;
	double			i;
	double			j;
	double			k;
	double			l;
	double			m;
	double			n;
	double			p;
	double			q;
	double			r;
	double			inv_denom;
	double			beta;
	double			s;
	double			e1;
	double			e2;
	double			e3;
	double			gamma;
}					t_trivar;

t_triangle			*set_triangle_normal(t_triangle *t);

#endif
