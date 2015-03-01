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
	int		x_start;
	int		y_start;

	x_start = WIN_X / 10;
	y_start = WIN_Y / 10;
	e->para_map = malloc(sizeof(t_coord *) * WIN_Y);
	y = -1;
	while (++y < e->map_y)
	{
		e->para_map[y] = malloc(sizeof(t_coord) * WIN_X);
		x = -1;
		while (++x < e->map_x)
		{
			e->para_map[y][x].x = x_start + (x * SQ_SIZE) + (PARA_CONST * e->map[y][x] * (-e->maximize));
			e->para_map[y][x].y = y_start + (y * SQ_SIZE) + (PARA_CONST / 2 * e->map[y][x] * (-e->maximize));
		}
	}
}

void		iso_fdf(t_env *e)
{
	int		x;
	int		y;
	int		x_start;
	int		y_start;

	x_start = (WIN_X / (e->map_x + 2)) + (ISO_C2 * e->map_y * SQ_SIZE);
	y_start = WIN_Y - (SQ_SIZE * (e->map_y + (3 * (ISO_C1 + ISO_C2))));
	e->iso_map = malloc(sizeof(t_coord *) * WIN_Y);
	y = -1;
	while (++y < e->map_y)
	{
		e->iso_map[y] = malloc(sizeof(t_coord) * WIN_X);
		x = -1;
		while(++x < e->map_x)
		{
			e->iso_map[y][x].x = x_start + (ISO_C1 * x * SQ_SIZE) - (ISO_C2 * y * SQ_SIZE);
			e->iso_map[y][x].y = y_start + (ISO_C1 / 2 * x * SQ_SIZE) + (ISO_C2 / 2 * y * SQ_SIZE) - (e->map[y][x] * e->maximize);
		}
	}
}
