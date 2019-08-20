/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorobin <jorobin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:08:49 by jorobin           #+#    #+#             */
/*   Updated: 2018/03/21 15:08:52 by jorobin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# define ESC 53
# define RIGHT 124
# define LEFT 123
# define DOWN 125
# define UP 126
# define PLUS 69
# define MINUS 78
# define N 45
# define W 13
# define A 0
# define S 1
# define D 2
# define R 15
# define F 3
# define Y 16
# define G 5
# define H 4
# define J 38
# define X 7
# define O 31
# define P 35
# define Q 12
# define Z 6
# define U 32
# define I 34
# define M 46
# define F5 96
# define F6 97
# define B 11
# define V 9

void	move_texture(int keycode, t_object *o);
void	print_menu(t_param *e);
void	print_obj_menu(t_param *e);
void	move_objects(int keycode, t_object *o);
void	move_camera(int keycode, t_param *e);
void	change_res(int keycode, t_param *e);

#endif
