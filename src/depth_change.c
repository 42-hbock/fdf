/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   depth_change.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbock <hbock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 10:56:30 by hbock             #+#    #+#             */
/*   Updated: 2015/03/01 10:56:31 by hbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void		free_map(t_env *e, t_coord **map)
{
	int		i;

	i = -1;
	while (++i < e->map_y)
		free(map[i]);
	free(map);
}

void		depth_change(t_env *e, int sign)
{
	reset_window(e);
	if (sign == 0)
		e->maximize++;
	else if (sign == 1)
		e->maximize--;
	if (e->pers == 0)
	{
		free_map(e, e->iso_map);
		iso_fdf(e);
		draw_fdf(e, e->iso_map);
	}
	else if (e->pers == 1)
	{
		free_map(e, e->para_map);
		parallel_fdf(e);
		draw_fdf(e, e->para_map);		
	}
	put_img_to_win(e);
}