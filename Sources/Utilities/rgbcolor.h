/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgbcolor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:35:12 by asavann           #+#    #+#             */
/*   Updated: 2017/11/13 15:57:09 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RGBCOLOR_H
# define RGBCOLOR_H

typedef struct	s_rgbcolor
{
	float r;
	float g;
	float b;
}				t_rgbcolor;

enum { NONE = 0, BLACKNWHITE, BLUE, SEPIA};

void			rgbinit(t_rgbcolor *c);
void			rgbsetvalue(t_rgbcolor *c, float r, float g, float b);
void			rgbcopy(t_rgbcolor *c, const t_rgbcolor v);
t_rgbcolor		rgbeq(t_rgbcolor *c, const t_rgbcolor rhs);
t_rgbcolor		rgbpow(const t_rgbcolor *c, float p);
t_rgbcolor		rgbadd(const t_rgbcolor *c, t_rgbcolor rhs);
t_rgbcolor		rgbaddc(t_rgbcolor *c, t_rgbcolor rhs);
t_rgbcolor		rgbmult(const t_rgbcolor *c, const float a);
t_rgbcolor		rgbmultc(t_rgbcolor *c, const float a);
t_rgbcolor		rgbmultrgb(const t_rgbcolor *c, const t_rgbcolor rhs);
t_rgbcolor		rgbdiv(const t_rgbcolor *c, const float a);
t_rgbcolor		rgbdivc(t_rgbcolor *c, const float a);
int				rgbcomp(const t_rgbcolor *c, const t_rgbcolor rhs);
float			average(const t_rgbcolor *c);
#endif
