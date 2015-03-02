/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbock <hbock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 09:43:02 by hbock             #+#    #+#             */
/*   Updated: 2015/02/19 09:43:02 by hbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void		parallel_fdf(t_env *e)
{
	int		x;
	int		y;
	int		sq_size;
	int		x_start;
	int		y_start;

	sq_size = MIN((WIN_X / (e->map_x * 1.2)), (WIN_Y / (e->map_y * 1.2)));
	x_start = e->x_shift + (WIN_X - (sq_size * e->map_x)) / 2;
	y_start = e->y_shift + (WIN_Y - (sq_size * e->map_y)) / 2;
	e->para_map = malloc(sizeof(t_coord *) * WIN_Y);
	y = -1;
	while (++y < e->map_y)
	{
		e->para_map[y] = malloc(sizeof(t_coord) * WIN_X);
		x = -1;
		while (++x < e->map_x)
		{
			e->para_map[y][x].x = x_start + (x * sq_size) + (e->para_const *
				e->map[y][x] * (-e->maximize));
			e->para_map[y][x].y = y_start + (y * sq_size) +
			(e->para_const / 2 * e->map[y][x] * (-e->maximize));
		}
	}
}

void		iso_fdf(t_env *e)
{
	int		x;
	int		y;
	int		sq_size;
	int		x_start;
	int		y_start;

	sq_size = MIN((WIN_X / (e->map_x * 1.2)), (WIN_Y / (e->map_y * 1.2)));
	x_start = e->x_shift + (WIN_X - ((e->iso_c1 * e->map_x * sq_size) -
		(e->iso_c2 * e->map_y * sq_size))) / 2;
	y_start = e->y_shift + (WIN_Y - ((e->iso_c1 / 2 * e->map_x * sq_size) +
		(e->iso_c2 / 2 * e->map_y * sq_size))) / 2;
	e->iso_map = malloc(sizeof(t_coord *) * WIN_Y);
	y = -1;
	while (++y < e->map_y)
	{
		e->iso_map[y] = malloc(sizeof(t_coord) * WIN_X);
		x = -1;
		while (++x < e->map_x)
		{
			e->iso_map[y][x].x = x_start + (e->iso_c1 * x * sq_size) -
			(e->iso_c2 * y * sq_size);
			e->iso_map[y][x].y = y_start + (e->iso_c1 / 2 * x * sq_size) +
			(e->iso_c2 / 2 * y * sq_size) - (e->map[y][x] * e->maximize);
		}
	}
}
