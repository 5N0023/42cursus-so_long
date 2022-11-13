/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlektaib <mlektaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 23:21:42 by mlektaib          #+#    #+#             */
/*   Updated: 2022/11/12 23:34:17 by mlektaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	drawopendoor(t_vars *vars)
{
	int	a;
	int	b;

	vars->img = mlx_xpm_file_to_image(vars->mlx, "./img/odoor.xpm", &a, &b);
	ft_checkimg(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
		vars->exitx, vars->exity);
}

void	ft_drawwall(t_vars *vars, int i)
{
	int	a;
	int	b;
	int	x;
	int	y;

	x = (i % (vars->w / 50)) * 50;
	y = (i / (vars->w / 50)) * 50;
	vars->img = mlx_xpm_file_to_image(vars->mlx, "./img/wall.xpm", &a, &b);
	ft_checkimg(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, x, y);
}

void	ft_drawcollective(t_vars *vars, int i)
{
	int	a;
	int	b;

	vars->colcount++;
	vars->collectivex = (i % (vars->w / 50)) * 50;
	vars->collectivey = (i / (vars->w / 50)) * 50;
	vars->img = mlx_xpm_file_to_image(vars->mlx,
			"./img/collective.xpm", &a, &b);
	ft_checkimg(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
		vars->collectivex, vars->collectivey);
}

void	ft_drawwater(t_vars *vars, int i)
{
	int	a;
	int	b;
	int	x;
	int	y;

	x = (i % (vars->w / 50)) * 50;
	y = (i / (vars->w / 50)) * 50;
	vars->img = mlx_xpm_file_to_image(vars->mlx,
			"./img/water.xpm", &a, &b);
	ft_checkimg(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, x, y);
}

void	ft_drawexit(t_vars *vars, int i)
{
	int	a;
	int	b;

	vars->exitx = (i % (vars->w / 50)) * 50;
	vars->exity = (i / (vars->w / 50)) * 50;
	vars->img = mlx_xpm_file_to_image(vars->mlx, "./img/cdoor.xpm", &a, &b);
	ft_checkimg(vars);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->img, vars->exitx, vars->exity);
}
