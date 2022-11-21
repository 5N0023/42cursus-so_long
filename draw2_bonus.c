/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlektaib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 22:08:13 by mlektaib          #+#    #+#             */
/*   Updated: 2022/11/20 22:08:14 by mlektaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
