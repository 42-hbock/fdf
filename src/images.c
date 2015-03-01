/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbock <hbock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 02:34:22 by hbock             #+#    #+#             */
/*   Updated: 2015/03/01 02:34:22 by hbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int		create_color(t_rgb *color)
{
	unsigned int	new_red;
	unsigned int	new_blue;
	unsigned int	new_green;

	new_red = (int)color->red;
	new_green = (int)color->green;
	new_blue = (int)color->blue;
	return (new_red << 16 | new_green << 8 | new_blue);
}

// void			put_pixel_to_img(t_env *e, int x, int y, t_rgb *color)
// {
// 	int		new_color;
// 	int		begin;

// 	begin = (x * e->bpp / 8) + (y * e->size_line);
// 	new_color = create_color(color);
// 	// if ((y >= 0 && y <= WIN_Y) && (x >= 0 && x <= WIN_X))
// 	ft_memcpy(e->addr + begin, &new_color, (e->bpp / 8));
// }

void			put_pixel_to_img(t_env *e, int x, int y, int color)
{
	int		new_color;
	int		begin;

	begin = (x * e->bpp / 8) + (y * e->size_line);
//	new_color = create_color(color);
	if ((y >= 0 && y <= WIN_Y) && (x >= 0 && x <= WIN_X))
		ft_memcpy(e->addr + begin, &color, (e->bpp / 8));
}

void			put_img_to_win(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

t_env			*env_init(t_env *e)
{
	if ((e = malloc(sizeof(t_env))) == NULL)
		return (NULL);
	if ((e->mlx = mlx_init()) == NULL)
		return (NULL);
	if ((e->win = mlx_new_window(e->mlx, WIN_X, WIN_Y, "HUGO")) == NULL)
		return (NULL);
	if ((e->img = mlx_new_image(e->mlx, WIN_X, WIN_Y)) == NULL)
		return (NULL);
	if ((e->addr = mlx_get_data_addr(e->img, &e->bpp, &e->size_line,
		&e->endian)) == NULL)
		return (NULL);
	e->pers = 0;
	e->maximize = 1;
	return (e);
}