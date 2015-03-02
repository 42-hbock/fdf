/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbock <hbock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 21:20:41 by hbock             #+#    #+#             */
/*   Updated: 2015/03/02 21:20:46 by hbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define ABS(x) (((x) < 0) ? -(x) : x)
# define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
# define SQ_SIZE 30
# define WIN_X 800
# define WIN_Y 550
# define PARA_CONST 0.8
# define ISO_C1 0.8
# define ISO_C2 0.8
# define BUFF 1024

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <errno.h>
# include <unistd.h>
# include <math.h>

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	int			bpp;
	int			size_line;
	int			endian;
	char		*addr;
	int			map_x;
	int			map_y;
	int			**map;
	t_coord		**para_map;
	t_coord		**iso_map;
	t_coord		**conic_map;
	int			x_shift;
	int			y_shift;
	int			pers;
	int			maximize;
	float		para_const;
	float		iso_c1;
	float		iso_c2;
}				t_env;

typedef struct	s_line
{
	int			dx;
	int			dy;
	int			color;
	int			coef_sign;
}				t_line;

typedef struct	s_rgb
{
	float		red;
	float		green;
	float		blue;
}				t_rgb;

t_env			*env_init(t_env *e);
void			print_line(t_coord a, t_coord b, t_env *e, int color);
void			line_hori(t_env *e, t_coord a, t_coord b, int color);
void			line_vert(t_env *e, t_coord a, t_coord b, int color);
void			parallel_fdf(t_env *e);
void			iso_fdf(t_env *e);
void			draw_fdf(t_env *e, t_coord **map);
int				ft_atoi(const char *str);
int				ft_isdigit(int c);
void			*ft_memcpy(void *s1, const void *s2, size_t n);
char			*ft_reallocat(char *dst, char *to_add);
void			put_pixel_to_img(t_env *e, int x, int y, int color);
void			put_img_to_win(t_env *e);
void			hook_event(t_env *e);
void			change_pers(t_env *e);
void			free_map(t_env *e, t_coord **map);
void			depth_change(t_env *e, int sign);
char			*ft_reallocat(char *dst, char *to_add);
char			*default_reading(char *file, t_env *e);
char			**ft_strsplit(char const *s, char c);
void			create_int_map(char *cmap, t_env *e);
int				ft_isnumber(char *s);
void			reset_window(t_env *e);
void			const_modif(t_env *e, int modif);
void			map_shift(t_env *e, int modif);

#endif
