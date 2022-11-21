/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkpos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlektaib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 22:07:40 by mlektaib          #+#    #+#             */
/*   Updated: 2022/11/20 22:07:43 by mlektaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void	ft_cleanlastpos(int x, int y, t_vars *vars)
{
	int	a;
	int	b;

	vars->img = mlx_xpm_file_to_image(vars->mlx, "./img/water.xpm", &a, &b);
	ft_checkimg(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, x, y);
	mlx_destroy_image(vars->mlx,vars->img);
	if (x == vars->exitx && y == vars->exity)
	{
		if (vars->colcount == 0)
			drawopendoor(vars);
		else
			drawcloseddoor(vars);
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
	if (vars->colcount == 0 && ft_checkwin(vars))
		drawopendoor(vars);
	if(vars->colcount != 0)
	{
	n = ((vars->y/50) * (vars->w/50)) + (vars->x / 50);
	if (vars->map[n] == 'C')
	{
		ft_draweatanim(vars);
		vars->colcount--;
		vars->map[n] = '0';
	}
	}
	
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
	mlx_destroy_image(vars->mlx,vars->img);
}
