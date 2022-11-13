#include "so_long.h"
void ft_clearwin(t_vars *vars)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(i++ < vars->w)
	{
		j = -1;
		while(j++ < vars->h)
		{
			mlx_pixel_put(vars->mlx,vars->win,i,j,0xFFFFFF);
			j++;
		}
		i ++;
	}
}


int ft_checkwin(t_vars *vars)
{
	static int c;
	int a;
	int b;
	int x;
	int y;

	if (vars->colcount == 0 && vars->x == vars->exitx && vars->y == vars->exity && c == 0)
	{
		c++;
		x = (vars->w - 250) / 2;
		y = (vars->h - 150) / 2;
		ft_clearwin(vars);
		vars->img = mlx_xpm_file_to_image(vars->mlx, "./img/win.xpm", &a, &b);
		ft_checkimg(vars);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
		 x, y);
		free(vars->img);
		return (0);
	}
	if (c == 1)
		return (0);
	return (1);
}