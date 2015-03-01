#include "../include/fdf.h"
#include "unistd.h"

int			main()
{
	t_env	e;
	t_coord a;
	t_coord	b;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 600, 450, "HUGO");
	a.x = 100;
	a.y = 100;
	b = a;
	b.x += 300;
	b.y += 200;
	print_line(a, b, &e, COLOR_START, 1);
	mlx_pixel_put(e.mlx, e.win, a.x, a.y, 0xFF0000);
	mlx_pixel_put(e.mlx, e.win, b.x, b.y, 0xFF0000);
	sleep(15);
	mlx_destroy_window(e.mlx, e.win);
	return (0);
}