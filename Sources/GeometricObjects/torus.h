/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 14:21:19 by majulien          #+#    #+#             */
/*   Updated: 2018/04/24 16:13:55 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TORUS_H
# define TORUS_H
# include "geometricobjects.h"
# include "point3d.h"
# include "normal.h"
# include "../../libft/libft.h"

int			torushit(const t_object *o, const t_ray ray, double *tmin, \
		t_shaderec *sr);
int			torushitshadow(const t_object *o, const t_ray ray,\
		float *tmin);
void		rootszero(double roots[4]);
void		rootsinit(const t_ray ray, const t_object *o,\
		double e[3], double coef[5]);
int			rootsval(double roots[4], const t_object *o, \
		int internum[2], double *t);
int			iszero(double x);
double		cbrt(double x);
void		ifquad(double coeffs[4], double z[6]);
void		ifcub(double s[4], double p[8]);
void		coefcubic(double c[4], double a[4]);
void		initcubic(double a[4], double p[8]);
void		initquartic(double a[5], double z[6], double c[5]);
void		elsequartic(double coeffs[4], double z[6], double s[4]);
int			elsequartic2(double coeffs[4], double z[6]);
void		elsifcubic(double p[8], double s[4]);
void		elcubic(double p[8], double s[4]);
void		whilefincub(int num, double a[4], double s[4]);
void		whilefinquad(int num, double a[5], double s[4]);
int			solvequadric(double c[3], double s[4]);
int			solvecubic(double c[4], double s[4]);
int			solvequartic(double c[5], double s[4]);
t_normal	computenormal(t_point3d hit, const t_object *o);

#endif
