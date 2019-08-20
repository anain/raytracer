/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 14:39:26 by anain             #+#    #+#             */
/*   Updated: 2018/04/22 16:17:15 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H

# define MATERIAL_H
# define KTABLESIZE 256
# define KTABLEMASK 256 - 1

# include "shaderec.h"
# include "brdf.h"
# include "camera.h"

typedef struct s_param	t_param;

typedef struct			s_matte
{
	t_lambertian		ambient_brdf;
	t_lambertian		diffuse_brdf;
}						t_matte;

typedef struct			s_phong
{
	t_lambertian		ambient_brdf;
	t_lambertian		diffuse_brdf;
	t_glossyspecular	specular_brdf;
}						t_phong;

typedef struct			s_reflective
{
	t_lambertian		ambient_brdf;
	t_lambertian		diffuse_brdf;
	t_glossyspecular	specular_brdf;
	t_perfectspecular	perfectspecular;
}						t_reflective;

typedef struct			s_transmitter
{
	t_lambertian		ambient_brdf;
	t_lambertian		diffuse_brdf;
	t_glossyspecular	specular_brdf;
	t_perfectspecular	perfectspecular;
	t_transparence		perft;
}						t_transmitter;

typedef struct			s_emissive
{
	float				ls;
	t_rgbcolor			ce;
}						t_emissive;

typedef struct			s_tex
{
	void				*marb_add;
	char				*marb_data;
	int					marb_sizex;
	int					marb_sizey;
	int					marb_bpp;
	int					marb_size_l;
	int					transform;
	char				*path;
}						t_tex;

typedef struct			s_latticenoise
{
	float				value_table[KTABLESIZE];
	int					perm_table[KTABLESIZE];
}						t_latticenoise;

typedef struct			s_chess
{
	t_rgbcolor			color1;
	t_rgbcolor			color2;
	double				size;
}						t_chess;

typedef struct			s_matparam
{
	t_vector3d			wi;
	t_vector3d			wo;
	t_rgbcolor			l;
	t_rgbcolor			c;
	t_ray				ray;
	float				ndotwi;
}						t_matparam;

typedef struct			s_material
{
	t_matte				matte;
	t_phong				phong;
	t_reflective		reflective;
	t_transmitter		transparence;
	int					type;
	t_tex				tex;
	t_rgbcolor			(*shade)(struct s_material *, t_shaderec*);
	t_rgbcolor			(*mapping)(t_shaderec *);
	t_rgbcolor			(*path_shade)(struct s_material *, t_shaderec*);
	t_rgbcolor			(*get_le)(struct s_material *, t_shaderec *sr);
	t_matrix			inv_mat;
	t_latticenoise		noise;
	float				(*fnoise)(t_shaderec *);
	t_emissive			emissive;
	t_chess				chess;
}						t_material;

void					reset_color(t_material *m, t_shaderec *sr);
t_rgbcolor				basic_mapping(t_shaderec *sr);
void					rotate_tex_x(t_material *m, double theta);
void					rotate_tex_y(t_material *m, double theta);
void					rotate_tex_z(t_material *m, double theta);
void					scale_texture(t_material *m, double a, \
							double b, double c);
void					translate_texture(t_material *m, double dx, double dy, \
							double dz);
t_rgbcolor				get_texture_pix(t_material *m, int row, int column);
t_rgbcolor				sphere_mapping(t_shaderec *sr);
t_rgbcolor				probe_mapping(t_shaderec *sr);
t_rgbcolor				rectangular_mapping(t_shaderec *sr);
t_rgbcolor				cylindrical_mapping(t_shaderec *sr);

#endif
