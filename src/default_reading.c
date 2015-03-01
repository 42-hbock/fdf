/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_reading.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbock <hbock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 13:11:33 by hbock             #+#    #+#             */
/*   Updated: 2015/03/01 13:11:33 by hbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

char		*init_string(char *s)
{
	if ((s = malloc(sizeof(char))) == NULL)
		return (NULL);
	s[0] = 0;
	return (s);
}

void		get_mapinfo(char *cmap, t_env *e)
{
	char	**tab_line;
	char	**single_line;
	int		i;
	int		j;
	int		max_len;

	max_len = 0;
	tab_line = ft_strsplit(cmap, '\n');
	i = -1;
	while (tab_line[++i])
	{
		single_line = ft_strsplit(tab_line[i], ' ');
		j = 0;
		while (single_line[j] != NULL)
			j++;
		max_len = (j > max_len) ? j : max_len;
	}
	e->map_x = max_len;
	e->map_y = i;
	printf("map_y:%d\nmap_x:%d\n", e->map_y, e->map_x);
	e->map = malloc(sizeof(int *) * e->map_y);
	i = -1;
	while (++i < e->map_x)
		e->map[i] = malloc(sizeof(int) * e->map_x);
}

char		*default_reading(char *file, t_env *e)
{
	int		fd;
	int		nread;
	char	buf[BUFF + 1];
	char	*c_map;

	buf[BUFF] = 0;
	if (((fd = open(file, O_RDONLY)) == -1) || ((c_map = init_string(c_map)) == NULL))
		exit(0);
	while ((nread = read(fd, buf, BUFF)) > 0)
	{
		buf[nread] = 0;
		c_map = ft_reallocat(c_map, buf);
	}
	if (nread < 0)
	{
		perror(NULL);
		free(c_map);
		exit(0);
	}
	get_mapinfo(c_map, e);
	return(c_map);
}

void		create_int_map(char *cmap, t_env *e)
{
	char	**tab_line;
	char	**single_line;
	int		i;
	int		j;

	tab_line = ft_strsplit(cmap, '\n');
	i = -1;
	while(tab_line[++i])
		printf("i:%d\n%s\n", i, tab_line[i]);
	i = -1;
	while (tab_line[++i])
	{
		single_line = ft_strsplit(tab_line[i], ' ');
		j = -1;
		while (++j < e->map_x)
		{
			if (single_line[j] != NULL)
			{
				if (ft_isnumber(single_line[j]))
					e->map[i][j] = ft_atoi(single_line[j]);
				else
					e->map[i][j] = 0;
			}
			else
				e->map[i][j] = 0;
		}
		printf("ok\n");
	}
}