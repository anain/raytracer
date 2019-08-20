/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 17:22:11 by asavann           #+#    #+#             */
/*   Updated: 2018/04/23 19:31:44 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "mmlx.h"

void		calcul_res(t_rendervar *e)
{
	e->pix_per_case.x = trunc(e->vp.hres / e->resolution.x);
	e->pix_per_case.y = trunc(e->vp.vres / e->resolution.y);
	if (e->resolution.x == e->vp.hres)
		e->first_3dpix.x = -e->vp.hres / 2 + (e->q +\
		(0.5 * e->pix_per_case.x)) / e->n;
	else
		e->first_3dpix.x = (e->pix_per_case.x / 2) - (e->vp.hres / 2) +\
		(e->q + (0.5 * e->pix_per_case.x)) / e->n;
	if (e->resolution.y == e->vp.vres)
		e->first_3dpix.y = -e->vp.vres / 2 + (e->p1 +\
		(0.5 * e->pix_per_case.y)) / e->n;
	else
		e->first_3dpix.y = (e->pix_per_case.y / 2) - (e->vp.vres / 2) +\
		(e->p1 + (0.5 * e->pix_per_case.y)) / e->n;
	e->first_3dpix.z = 0;
}

t_vector3d	ray_direction(t_camera *cam, t_rendervar *e, t_sampler *s)
{
	t_vector3d	dir;
	t_point2d	sp;

	e->cur3dpix.x = e->first_3dpix.x + (e->screen.x * e->pix_per_case.x);
	e->cur3dpix.y = e->first_3dpix.y + (e->screen.y * e->pix_per_case.y);
	e->cur3dpix.z = 0;
	sp = sample_unit_square(s);
	if (e->n > 1)
	{
		e->cur3dpix.x = (e->screen.x - 0.5 * e->resolution.x + sp.x);
		e->cur3dpix.y = (e->screen.y - 0.5 * e->resolution.y + sp.y);
		e->cur3dpix.z = 0;
	}
	dir.x = e->cur3dpix.x * cam->u.x + e->cur3dpix.y * cam->v.x\
	- cam->pin.d * cam->w.x;
	dir.y = e->cur3dpix.x * cam->u.y + e->cur3dpix.y * cam->v.y\
	- cam->pin.d * cam->w.y;
	dir.z = e->cur3dpix.x * cam->u.z + e->cur3dpix.y * cam->v.z\
	- cam->pin.d * cam->w.z;
	normalize(&dir);
	return (dir);
}

void		render_pin(t_param *p, int i, int n)
{
	p->v.screen.y = i;
	p->v.screen.x = -1;
	while (++p->v.screen.x <= p->v.resolution.x)
	{
		p->v.p1 = -1;
		rgbsetvalue(&p->v.pixel_color, 0, 0, 0);
		while (++p->v.p1 < n)
		{
			p->v.ray.d = ray_direction(&p->world.camera, &p->v,\
			&p->world.vp.sampler);
			rgbaddc(&p->v.pixel_color,\
			p->world.tracer.t(&p->world.tracer, p->v.ray, 0));
		}
		rgbdivc(&p->v.pixel_color, n);
		if (p->v.resolution.x == p->world.vp.hres &&\
		p->v.resolution.y == p->world.vp.vres)
			display_pixel(p, p->v.cur3dpix.y +\
			(p->world.vp.vres / 2), p->v.cur3dpix.x +\
			(p->world.vp.hres / 2), p->v.pixel_color);
		else
			display_res(p, p->v.cur3dpix.x +\
			(p->world.vp.hres / 2), p->v.cur3dpix.y +\
			(p->world.vp.vres / 2), p->v.pixel_color);
	}
}

int			next_row(t_thread *t, int *i)
{
	int j;

	j = 0;
	pthread_mutex_lock(&g_lock);
	while (j < t->p->v.vp.win_height)
	{
		if (t->tab[j] == 0)
		{
			*i = j;
			t->tab[j] = 1;
			pthread_mutex_unlock(&g_lock);
			return (1);
		}
		j++;
	}
	pthread_mutex_unlock(&g_lock);
	return (0);
}

void		render(t_thread *t)
{
	int		n;
	int		i;
	float	p;

	calcul_res(&t->p->v);
	p = 0;
	if (t->p->v.pix_per_case.x != 1)
	{
		t->p->v.n = 1;
		n = 1;
	}
	else
	{
		t->p->v.n = sqrt(t->p->world.vp.numsamples);
		n = t->p->world.vp.numsamples;
	}
	point3dcpy(&t->p->v.ray.o, t->p->world.camera.eye);
	while (next_row(t, &i) == 1)
		render_pin(t->p, i, n);
	pthread_exit(NULL);
}
