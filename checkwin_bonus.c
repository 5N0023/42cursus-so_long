/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkwin_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlektaib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 22:10:17 by mlektaib          #+#    #+#             */
/*   Updated: 2022/11/20 22:10:18 by mlektaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
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


void ft_clearlose(t_vars *vars)
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
			mlx_pixel_put(vars->mlx,vars->win,i,j,0x0);
			j++;
		}
		i ++;
	}
}

int	ft_checkenemy(t_vars *vars)
{
	int	n;

	if(vars->x == vars->enemyx && vars->y == vars->enemyy)
		return (1);
	return (0);
}
void ft_drawrip(t_vars *vars)
{
	int	a;
	int	b;

	vars->img = mlx_xpm_file_to_image(vars->mlx, "./img/water.xpm", &a, &b);
	ft_checkimg(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
		vars->x, vars->y);
	mlx_destroy_image(vars->mlx,vars->img);
	vars->img = mlx_xpm_file_to_image(vars->mlx, "./img/rip.xpm", &a, &b);
	ft_checkimg(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
		vars->x, vars->y);
	mlx_destroy_image(vars->mlx,vars->img);

}
int	ft_checkenemy1(int x, int y, t_vars *vars)
{
	int	n;

	n = ((y/50) * (vars->w/50)) + (x / 50);
	if (vars->map[n] == 'B')
				return (1);
	return (0);
}
int ft_checklose(t_vars *vars)
{
	int a;
	int b;
	int x;
	int y;

	if (ft_checkenemy(vars) && vars->status == 0)
	{
		vars->status = 2;
		x = (vars->w - 250) / 2;
		y = (vars->h - 150) / 2;
		ft_drawrip(vars);
		ft_clearlose(vars);
		vars->img = mlx_xpm_file_to_image(vars->mlx, "./img/lose.xpm", &a, &b);
		ft_checkimg(vars);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
		 x, y);
		mlx_destroy_image(vars->mlx,vars->img);
		return (0);
	}
	if (vars->status == 2)
		return (0);
	return (1);
}

int ft_checkwin(t_vars *vars)
{
	int a;
	int b;
	int x;
	int y;

	if (vars->colcount == 0 && vars->x == vars->exitx && vars->y == vars->exity && vars->status == 0)
	{
		vars->status = 1;
		x = (vars->w - 250) / 2;
		y = (vars->h - 150) / 2;
		
		drawopendoor(vars);
		ft_clearwin(vars);
		vars->img = mlx_xpm_file_to_image(vars->mlx, "./img/win.xpm", &a, &b);
		ft_checkimg(vars);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
		 x, y);
		mlx_destroy_image(vars->mlx,vars->img);
		return (0);
	}
	if (vars->status == 1)
		return (0);
	return (1);
}
