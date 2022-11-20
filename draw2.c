#include "so_long.h"

void	drawcloseddoor(t_vars *vars)
{
	int	a;
	int	b;

	vars->img = mlx_xpm_file_to_image(vars->mlx, "./img/water.xpm", &a, &b);
	ft_checkimg(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
		vars->exitx, vars->exity);
	mlx_destroy_image(vars->mlx,vars->img);
	vars->img = mlx_xpm_file_to_image(vars->mlx, "./img/cdoor.xpm", &a, &b);
	ft_checkimg(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
		vars->exitx, vars->exity);
	mlx_destroy_image(vars->mlx,vars->img);
}