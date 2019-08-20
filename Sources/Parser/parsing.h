/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 17:12:20 by anain             #+#    #+#             */
/*   Updated: 2018/04/24 22:53:20 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# define MALLOC_ERR "Memory allocation failed."
# include "../../libft/libft.h"
# include "mmlx.h"
# include "camera.h"
# include "noise.h"
# include "chess.h"
# include "material.h"
# include "geometricobjects.h"
# include "point3d.h"
# include "../World/world.h"
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <libxml2/libxml/tree.h>
# include <libxml2/libxml/xpath.h>
# include <libxml2/libxml/parser.h>

typedef struct			s_object_set
{
	char				*name;
	void				(*setobj)(xmlDocPtr doc, t_object *obj, xmlNodePtr cur);
	struct s_object_set *next;
}						t_object_set;

typedef struct			s_childlst
{
	char				*child;
	char				*value;
	struct s_childlst	*next;
}						t_childlst;

typedef struct			s_paramlist
{
	t_childlst			*lst;
	t_childlst			*next;
}						t_paramlist;

typedef struct			s_data
{
	t_childlst			*lst;
	int					level;
}						t_data;

void					ft_triangle_error(void);
void					set_limcone6(t_object *object);
void					set_skybox(xmlDocPtr doc, t_object *object,\
						xmlNodePtr cur);
void					fill_obj(t_object *obj);
void					ft_mickey_error(void);
void					set_point2(t_point3d *p, char **c, int i);
void					set_normal2(t_normal *p, char **c, int i);
void					ft_partocylinder_error(void);
void					ft_partsphere_error(void);
void					ft_mickey_error(void);
int						set_vector(xmlChar *xmlchar, t_vector3d *p);
void					set_vector2(t_vector3d *p, char **c, int i);
int						set_point(xmlChar *xmlchar, t_point3d *p);
void					set_vec(xmlChar *xmlchar, t_vector3d *v);
void					set_rgb(xmlChar *xmlchar, t_rgbcolor *p);
int						set_normal(xmlChar *xmlchar, t_normal *p);
void					set_colorp(xmlChar *xmlchar, t_rgbcolor *col);
void					set_colorp2(t_rgbcolor *col);
double					set_coef(xmlChar *xmlchar);
void					texture_bank2(t_material *mat);
void					texture_bank(t_material *mat, char *pattern);
void					print_xmltransfo_usage(void);
void					set_theta(t_object *object, \
						xmlNodePtr child, xmlChar *xmldata);
void					set_theta2(t_object *object, \
						xmlNodePtr child, xmlChar *xmldata);
void					set_phi(t_object *object, \
						xmlNodePtr child, xmlChar *xmldata);
void					set_phi2(t_object *object, \
						xmlNodePtr child, xmlChar *xmldata);
void					mickey3(t_object *obj, xmlNodePtr cur, xmlDocPtr doc);
void					set_partocylinder4(t_object *object, \
						xmlNodePtr child, xmlChar *xmldata);
void					set_partocylinder5(t_object *object, \
						xmlNodePtr child, xmlChar *xmldata);
void					set_partocylinder6(t_object *object);
void					set_cylinder4(t_object *object, \
						xmlNodePtr child, xmlChar *xmldata);
void					chess(xmlDocPtr doc, t_object *obj, \
						xmlNodePtr node);
void					mickey(xmlDocPtr doc, t_object *object, \
						xmlNodePtr cur);
int						no_vector(t_vector3d *v);
int						no_normal(t_normal *n);
int						no_point(t_point3d *p);
void					noise(xmlDocPtr doc, t_object *obj, xmlNodePtr node);
void					print_xmlreflective_usage(void);
void					print_xmltransparence_usage(void);
void					print_xmlmatte_usage(void);
void					print_xmltext_usage(void);
void					print_xmlphong_usage(void);
int						is_perfectsquare(int n);
void					parserot(xmlDocPtr doc, t_object *o,\
						xmlNodePtr transfonode);
void					parsetranslate(xmlDocPtr doc, t_object *o,\
						xmlNodePtr transfonode);
void					parsescale(xmlDocPtr doc, t_object *o,\
						xmlNodePtr transfonode);
void					transformation(xmlDocPtr doc, t_object *o,\
						xmlNodePtr transfonode);
void					translate_generic(t_matrix *matrix, t_point3d p);
void					scaling_generic(t_matrix *matrix, t_point3d p);
void					print_xmltransfo_usage(void);
void					transfo(xmlDocPtr doc, t_matrix *inv_mat, \
						xmlNodePtr transfonode, char *transfotype);
void					rotx_generic(t_matrix *matrix, double theta);
void					roty_generic(t_matrix *matrix, double theta);
void					rotz_generic(t_matrix *matrix, double theta);
void					transparence(xmlDocPtr doc, t_object *object, \
						xmlNodePtr transparence_node);
void					mirror(xmlDocPtr doc, t_object *object, \
						xmlNodePtr reflective_node);
void					matte(xmlDocPtr doc, t_object *object, \
						xmlNodePtr matte_node);
void					phong(xmlDocPtr doc, t_object *object, \
						xmlNodePtr phong_node);
void					ft_sphere_error(void);
void					ft_plane_error(void);
void					ft_cylinder_error(void);
void					ft_cone_error(void);
void					free_all(char **c, int j);
int						set_vector(xmlChar *xmlchar, t_vector3d *p);
void					set_box(xmlDocPtr doc, t_object *object, \
						xmlNodePtr cur);
void					set_partocylinder(xmlDocPtr doc, t_object *object, \
						xmlNodePtr cur);
void					set_paraboloid(xmlDocPtr doc, t_object *object, \
						xmlNodePtr cur);
void					set_partsphere(xmlDocPtr doc, t_object *object, \
						xmlNodePtr cur);
void					set_rectangle(xmlDocPtr doc, t_object *object, \
						xmlNodePtr cur);
void					set_triangle(xmlDocPtr doc, t_object *object, \
						xmlNodePtr cur);
void					set_torus(xmlDocPtr doc, t_object *object, \
						xmlNodePtr cur);
void					set_disk(xmlDocPtr doc, t_object *object, \
						xmlNodePtr cur);
int						set_normal(xmlChar *xmlchar, t_normal *p);
void					noise(xmlDocPtr doc, t_object *obj, xmlNodePtr node);
void					texture(xmlDocPtr doc, t_object *obj, xmlNodePtr node);
void					transp_compo(xmlDocPtr doc, t_transparence *transp, \
						xmlNodePtr node);
void					mirror_compo(xmlDocPtr doc, t_perfectspecular *pf, \
						xmlNodePtr node);
void					matte_compo(xmlDocPtr doc, t_lambertian *lambertian, \
						xmlNodePtr node, int i);
xmlChar					*find_data(xmlDocPtr doc, xmlNodePtr node, char *str);
xmlChar					*find_optional_data(xmlDocPtr doc, xmlNodePtr node, \
						char *str);
xmlXPathObjectPtr		findnodesbyname(xmlDocPtr doc, xmlNodePtr rootnode, \
						const xmlChar *nodename);
void					phong_compo(xmlDocPtr doc, t_glossyspecular *phong, \
						xmlNodePtr node);
double					set_positive_value(xmlChar *xmlchar);
double					set_coef(xmlChar *xmlchar);
void					set_material(xmlDocPtr doc, t_object *object, \
						xmlNodePtr cur);
void					set_object_generic(xmlDocPtr doc, t_object *object, \
						xmlNodePtr obj_node);
void					set_cylinder(xmlDocPtr doc, t_object *object, \
						xmlNodePtr cur);
void					set_cone(xmlDocPtr doc, t_object *object, \
						xmlNodePtr cur);
void					set_sphere(xmlDocPtr doc, t_object *object, \
						xmlNodePtr cur);
void					set_plane(xmlDocPtr doc, t_object *object, \
						xmlNodePtr cur);
void					set_rgb(xmlChar *xmlchar, t_rgbcolor *p);
void					parse_vp(xmlDocPtr doc, xmlNodePtr cur, \
						t_world *world);
void					parse_objects(xmlDocPtr doc, xmlNodePtr cur, \
						t_world *world);
int						ft_is_point_or_vec(char **c);
int						ft_is_value(char *c);
void					parse_cam(xmlDocPtr doc, xmlNodePtr cur, \
						t_world *world);
char					*parser(char *docname, t_world *world);
int						set_point(xmlChar *xmlchar, t_point3d *p);
void					set_vec(xmlChar *xmlchar, t_vector3d *v);
void					worldbuild(t_world *w, char *scene);
void					parse_lights(xmlDocPtr doc, xmlNodePtr cur, \
						t_world *world);
void					parse_spot_light(xmlDocPtr doc, xmlNodePtr cur, \
						t_light **li);
void					parse_directional_light(xmlDocPtr doc, xmlNodePtr cur, \
						t_light **li);
void					parse_environment_light(xmlDocPtr doc, xmlNodePtr cur, \
						t_world *w);
t_object				*addobj(t_object **o, t_world *world);
t_light					*addlight(t_light **l);
int						is_perfectsquare(int n);
void					parse_ao(xmlDocPtr doc, xmlNodePtr cur, \
						t_ambientoccluder *ao);
void					parse_area(xmlDocPtr doc, xmlNodePtr cur, \
						t_world *world);
int						set_normal(xmlChar *xmlchar, t_normal *n);
void					parse_lobject(xmlDocPtr doc, xmlNodePtr cur, \
						t_world *world, int ns);
void					parse_lsphere(xmlDocPtr doc, \
						xmlNodePtr cur, t_world *world, int ns);
void					set_colorp(xmlChar *xmlchar, t_rgbcolor *col);
int						ft_is_color(char **c);
void					parse_pathtracer(xmlDocPtr doc, xmlNodePtr cur,\
						t_world *world);
void					set_limcone(xmlDocPtr doc, t_object *object,\
						xmlNodePtr cur);
void					ft_limcone_error(void);
xmlXPathObjectPtr		checkobject(xmlDocPtr doc,\
						xmlNodePtr cur, t_world *world);
#endif
