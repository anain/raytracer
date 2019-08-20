/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chess.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <anain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 13:20:12 by anain             #+#    #+#             */
/*   Updated: 2018/04/21 23:12:25 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHESS_H
# define CHESS_H

# include <stdio.h>
# include "rgbcolor.h"
# include "shaderec.h"
# include "material.h"

typedef struct		s_intp
{
	int		x;
	int		y;
	int		z;
}					t_intp;

t_rgbcolor			get_chess_color(t_shaderec *sr);
int					ft_floor(double x);

#endif
