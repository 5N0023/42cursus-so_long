#include "so_long.h"

void	ft_draweatanimup(t_vars *vars)

{
	int	a;
	int	b;

	vars->img = mlx_xpm_file_to_image(vars->mlx, "./img/water.xpm", &a, &b);
	ft_checkimg(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
		vars->x, vars->y);
	mlx_destroy_image(vars->mlx,vars->img);
	vars->img = mlx_xpm_file_to_image(vars->mlx, "./img/eatanimup.xpm", &a, &b);
	ft_checkimg(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
		vars->x, vars->y);
	mlx_destroy_image(vars->mlx,vars->img);
}
void	ft_draweatanimdown(t_vars *vars)

{
	int	a;
	int	b;

	vars->img = mlx_xpm_file_to_image(vars->mlx, "./img/water.xpm", &a, &b);
	ft_checkimg(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
		vars->x, vars->y);
	mlx_destroy_image(vars->mlx,vars->img);
	vars->img = mlx_xpm_file_to_image(vars->mlx, "./img/eatanimdown.xpm", &a, &b);
	ft_checkimg(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
		vars->x, vars->y);
	mlx_destroy_image(vars->mlx,vars->img);
}
void	ft_draweatanimright(t_vars *vars)

{
	int	a;
	int	b;

	vars->img = mlx_xpm_file_to_image(vars->mlx, "./img/water.xpm", &a, &b);
	ft_checkimg(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
		vars->x, vars->y);
	mlx_destroy_image(vars->mlx,vars->img);
	vars->img = mlx_xpm_file_to_image(vars->mlx, "./img/eatanimright.xpm", &a, &b);
	ft_checkimg(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
		vars->x, vars->y);
	mlx_destroy_image(vars->mlx,vars->img);
}
void	ft_draweatanimleft(t_vars *vars)

{
	int	a;
	int	b;

	vars->img = mlx_xpm_file_to_image(vars->mlx, "./img/water.xpm", &a, &b);
	ft_checkimg(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
		vars->x, vars->y);
	mlx_destroy_image(vars->mlx,vars->img);
	vars->img = mlx_xpm_file_to_image(vars->mlx, "./img/eatanimleft.xpm", &a, &b);
	ft_checkimg(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
		vars->x, vars->y);
	mlx_destroy_image(vars->mlx,vars->img);
}

void	ft_draweatanim(t_vars *vars)

{
	if (vars->vision == 1)
		ft_draweatanimup(vars);
	if (vars->vision == 2)
		ft_draweatanimdown(vars);
	if (vars->vision == 3)
		ft_draweatanimright(vars);
	if (vars->vision == 4)
		ft_draweatanimleft(vars);
}