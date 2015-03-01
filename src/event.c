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

static int	key_hook(unsigned int key, t_env *e)
{
	printf("%d\n", key);
	if (key == 65307)
		exit(0);
	if (key == 112)
		change_pers(e);
	if (key == 65451)
		depth_change(e , 0);
	if (key == 65453)
		depth_change(e, 1);
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
