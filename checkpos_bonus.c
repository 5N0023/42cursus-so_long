/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkpos_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlektaib <mlektaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 23:09:58 by mlektaib          #+#    #+#             */
/*   Updated: 2022/11/14 19:43:09 by mlektaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_cleanlastpos(int x, int y, t_vars *vars)
{
	int	a;
	int	b;

	vars->img = mlx_xpm_file_to_image(vars->mlx, "./img/water.xpm", &a, &b);
	ft_checkimg(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, x, y);
	if (x == vars->exitx && y == vars->exity)
	{
		vars->img = mlx_xpm_file_to_image(vars->mlx, "./img/cdoor.xpm", &a, &b);
		ft_checkimg(vars);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, x, y);
	}
}

int	ft_checkwall(int x, int y, t_vars *vars)
{
	int	n;

	n = ((y/50) * (vars->w/50)) + (x / 50);
	if (vars->map[n] == '1')
				return (1);
	return (0);
}

void	ft_checkcollective(t_vars *vars)
{
	int	n;

	n = ((vars->y/50) * (vars->w/50)) + (vars->x / 50);
	if (vars->map[n] == 'C')
	{
		ft_draweatanim(vars);
		vars->colcount--;
		vars->map[n] = '0';
	}
	if (vars->colcount == 0 && ft_checkwin(vars))
		drawopendoor(vars);
}

void	ft_startpos(t_vars *vars, int i)
{
	int	a;
	int	b;

	vars->x = (i % (vars->w / 50)) * 50;
	vars->y = (i / (vars->w / 50)) * 50;
	vars->img = mlx_xpm_file_to_image(vars->mlx, "./img/fishr.xpm", &a, &b);
	ft_checkimg(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->x, vars->y);
}
