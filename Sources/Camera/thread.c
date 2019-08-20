/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:51:19 by asavann           #+#    #+#             */
/*   Updated: 2018/04/24 17:03:18 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "mmlx.h"
#include "sampler.h"
#include "libft.h"
#include <math.h>
#include <stdio.h>
#include <sys/time.h>

pthread_mutex_t g_lock;

void	launchthread(t_param *p, int *tab)
{
	pthread_t	thread[NBTHREAD];
	t_thread	thr[NBTHREAD];
	int			i;

	i = -1;
	while (++i < NBTHREAD)
	{
		if (!(thr[i].p = (t_param *)malloc(sizeof(t_param))))
			exit(EXIT_FAILURE);
		*thr[i].p = *p;
		thr[i].i = i;
		thr[i].tab = tab;
		deepcpy(&thr[i].p->world);
		thr[i].p->world.tracer.world_ptr = &thr[i].p->world;
		pthread_create(&thread[i], NULL, (void*)render, (void*)&thr[i]);
	}
	i = -1;
	while (++i < NBTHREAD)
	{
		pthread_join(thread[i], NULL);
		deepfree(&thr[i].p->world);
		free(thr[i].p);
	}
}

void	th_render(t_param *p)
{
	int			i;
	int			*tab;

	i = 0;
	pthread_mutex_init(&g_lock, NULL);
	if (!(tab = (int *)malloc(sizeof(int) * p->world.vp.win_height)))
		exit(EXIT_FAILURE);
	while (++i < p->world.vp.win_height)
	{
		tab[i] = 0;
	}
	launchthread(p, tab);
	free(tab);
	pthread_mutex_destroy(&g_lock);
}
