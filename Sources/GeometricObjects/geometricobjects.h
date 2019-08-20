/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometricobjects.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:20:05 by asavann           #+#    #+#             */
/*   Updated: 2018/04/24 16:23:20 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOMETRICOBJECTS_H
# define GEOMETRICOBJECTS_H

# include "point3d.h"
# include "ray.h"
# include "shaderec.h"
# include "matrix.h"
# include "sampler.h"
# include "material.h"
# include "triangle.h"
# include "noise.h"

typedef struct				s_partopencylinder
{
	double					y0;
	double					y1;
	double					radius;
	double					invradius;
	double					kepsilon;
	double					phi_min;
	double					phi_max;
}							t_partopencylinder;

typedef struct				s_torus
{
	double					a;
	double					b;
	double					kepsilon;
}							t_torus;

typedef	struct				s_paraboloid
{
	t_point3d				c;
	t_vector3d				v;
	double					k;
	double					kepsilon;
}							t_paraboloid;

typedef struct s_material	t_material;

typedef struct				s_partsphere
{
	t_point3d				center;
	double					radius;
	double					kepsilon;
	double					phi_min;
	double					phi_max;
	double					theta_min;
	double					theta_max;
	double					cos_theta_min;
	double					cos_theta_max;
}							t_partsphere;

typedef struct				s_rectanlge
{
	t_point3d				p0;
	t_normal				normal;
	t_vector3d				a;
	t_vector3d				b;
	float					len_squared_a;
	float					len_squared_b;
	float					len_a;
	float					len_b;
	double					kepsilon;
	t_sampler				sampler;
	float					area;
	float					inv_area;
}							t_rectangle;

typedef struct				s_disk
{
	t_point3d				center;
	t_normal				normal;
	double					r;
	double					r_squared;
	double					kepsilon;
	t_sampler				sampler;
	double					inv_area;
	double					area;
	float					k;
	t_vector3d				u;
	t_vector3d				v;
	t_vector3d				w;
}							t_disk;

typedef struct				s_infcone
{
	double					h;
	double					radius;
	double					invradius;
	double					kepsilon;
}							t_infcone;

typedef struct				s_limcone
{
	double					h;
	double					radius;
	double					y0;
	double					y1;
	double					invradius;
	double					kepsilon;
}							t_limcone;

typedef struct				s_opencylinder
{
	double					y0;
	double					y1;
	double					radius;
	double					invradius;
	double					kepsilon;
}							t_opencylinder;

typedef struct				s_plane
{
	t_point3d				point;
	t_normal				normal;
	double					kepsilon;
}							t_plane;

typedef struct				s_sphere
{
	t_point3d				center;
	t_sampler				sampler;
	double					kepsilon;
	float					area;
	float					inv_area;
	double					radius;
}							t_sphere;

typedef struct				s_lim
{
	double					x0;
	double					y0;
	double					z0;
	double					x1;
	double					y1;
	double					z1;
}							t_lim;

typedef struct				s_box
{
	t_lim					lim;
	double					kepsilon;
}							t_box;

typedef struct				s_object
{
	t_torus					torus;
	t_material				mat;
	t_sphere				sphere;
	t_plane					plane;
	t_opencylinder			ocylinder;
	t_partsphere			partsphere;
	t_partopencylinder		pocylinder;
	t_infcone				icone;
	t_disk					disk;
	t_limcone				lcone;
	t_rectangle				rectangle;
	t_triangle				triangle;
	t_point3d				d;
	t_paraboloid			paraboloid;
	t_box					box;
	t_rgbcolor				c;
	t_matrix				inv_mat;
	int						shadow;
	int						type;
	t_latticenoise			noise;
	struct s_object			*compound;
	int						(*hittrans)(\
		const struct s_object*, const t_ray, double*, t_shaderec *);
	int						(*hit)(\
		const struct s_object*, const t_ray, double*, t_shaderec *);
	int						(*shadow_hit)(\
		const struct s_object*, const t_ray, float*);
	int						(*shadow_hittrans)(\
		const struct s_object*, const t_ray, float*);
	t_point3d				(*sample)(struct s_object*);
	t_normal				(*get_normal)(struct s_object*, t_point3d *);
	float					(*pdfo)(struct s_object *, t_shaderec *);
	struct s_object			*next;
}							t_object;

enum { SPHERE = 1, PLANE, CONE, CYLINDER, TRIANGLE, RECTANGLE, \
	DISK, PARTCYLINDER, PARTSPHERE, BOX, PARABOLOID, TORUS, MICKEY,\
	LIMCONE, SKYBOX };

int							shadow_hittransform(\
				const t_object *obj, const t_ray ray, float *tmin);
int							hittransform(const t_object *obj, const t_ray ray,\
				double *tmin, t_shaderec *sr);
void						translate(t_object *obj, \
				const double dx, const double dy, const double dz);
void						translate_tex(t_object *obj, \
				const double dx, const double dy, const double dz);
void						translatevec(t_object *obj, const t_vector3d vec);
void						scale(t_object *obj, double a, double b, double c);
int							trianglehit(const t_object *o, const t_ray ray, \
				double *tmin, t_shaderec *sr);
int							trianglehitshadow(const t_object *o,\
				const t_ray ray, float *tmin);
void						rotate_x(t_matrix *inv_mat, double theta);
void						rotate_y(t_matrix *inv_mat, double theta);
void						rotate_z(t_matrix *inv_mat, double theta);
#endif
