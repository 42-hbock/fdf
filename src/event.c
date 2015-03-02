/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbock <hbock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 04:45:21 by hbock             #+#    #+#             */
/*   Updated: 2015/03/01 04:45:21 by hbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void		move_map(t_env *e, int key)
{
	if (key == 123)
		map_shift(e, 0);
	else if (key == 124)
		map_shift(e, 1);
	else if (key == 125)
		map_shift(e, 2);
	else if (key == 126)
		map_shift(e, 3);
}

static int	key_hook(unsigned int key, t_env *e)
{
	if (key == 53)
		exit(0);
	if (key == 35)
		change_pers(e);
	if (key == 69)
		depth_change(e, 0);
	if (key == 78)
		depth_change(e, 1);
	if (key == 6)
		const_modif(e, 0);
	if (key == 7)
		const_modif(e, 1);
	if (key == 8)
		const_modif(e, 2);
	if (key == 9)
		const_modif(e, 3);
	if (key >= 123 && key <= 126)
		move_map(e, key);
	return (0);
}

int			expose_hook(t_env *e)
{
	put_img_to_win(e);
	return (0);
}

void		hook_event(t_env *e)
{
	mlx_key_hook(e->win, &key_hook, e);
	mlx_expose_hook(e->win, &expose_hook, e);
	mlx_loop(e->mlx);
}
