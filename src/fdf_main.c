/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbock <hbock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 09:24:48 by hbock             #+#    #+#             */
/*   Updated: 2015/02/19 09:24:49 by hbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int			main(int ac, char **av)
{
	char	*cmap;
	t_env	*e;

	if (ac != 2)
		return (0);
	if ((e = env_init(e)) == NULL)
		exit(EXIT_FAILURE);
	cmap = default_reading(av[1], e);
	create_int_map(cmap, e);
	parallel_fdf(e);
	iso_fdf(e);
	draw_fdf(e, e->iso_map);
	hook_event(e);
	return (0);
}
