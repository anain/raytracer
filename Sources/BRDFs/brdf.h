/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brdf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 14:56:32 by asavann           #+#    #+#             */
/*   Updated: 2018/04/22 16:38:40 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRDF_H
# define BRDF_H
# define WHITE (t_rgbcolor){1, 1, 1}

# include "rgbcolor.h"
# include "vector3d.h"
# include "shaderec.h"
# include "sampler.h"

typedef struct s_matparam	t_matparam;
typedef struct s_transparam	t_transparam;

typedef struct		s_glossyspecular
{
	float		ks;
	float		exp;
	t_rgbcolor	cs;
	t_sampler	sampler;
}					t_glossyspecular;

typedef struct		s_lambertian
{
	float		kd;
	t_rgbcolor	cd;
	t_sampler	sampler;
}					t_lambertian;

typedef struct		s_perfectspecular
{
	float		kr;
	t_rgbcolor	cr;
}					t_perfectspecular;

typedef struct		s_transparence
{
	float		ior;
	float		kt;
}					t_transparence;

typedef	struct		s_parambrdf
{
	t_vector3d	u;
	t_vector3d	v;
	t_vector3d	w;
	float		cos_theta_i;
	float		eta;
	float		tmp;
	float		cos_theta2;
}					t_parambrdf;

void				glossyinit(t_glossyspecular *spec);
void				glossycopy(\
					t_glossyspecular *spec, const t_glossyspecular cpy);
t_glossyspecular	glossynew(\
					t_glossyspecular *spec, const t_glossyspecular cpy);
t_rgbcolor			glossyf(\
					t_glossyspecular *spec, const t_shaderec sr,\
					const t_vector3d wo, const t_vector3d wi);
void				lambinit(t_lambertian *lamb);
void				lambcopy(t_lambertian *lamb, const t_lambertian cpy);
t_lambertian		lambnew(t_lambertian *lamb);
t_lambertian		lambeq(t_lambertian *lamb, const t_lambertian rhs);
t_rgbcolor			lambf(t_lambertian *lamb);
t_rgbcolor			lambrho(t_lambertian *lamb);
t_rgbcolor			lambfps(t_lambertian *lamb,\
					const t_shaderec *sr, t_vector3d *wi, float *pdf);
t_rgbcolor			sample_fps(t_perfectspecular *perf, const t_shaderec *sr,\
					t_transparam *p, float *pdf);
void				set_samplerlamb(t_lambertian *l, const int ns);
t_rgbcolor			glossyfps(t_glossyspecular *spec,\
					const t_shaderec *sr, t_matparam *mp, float *pdf);
void				set_samplerphong(t_glossyspecular *spec, const int ns);
t_rgbcolor			sample_ftps(t_transparence *perft, const t_shaderec sr, \
	t_transparam *mp, float *pdf);

#endif
