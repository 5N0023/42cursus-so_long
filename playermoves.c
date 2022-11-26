/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playermoves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlektaib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 09:43:43 by mlektaib          #+#    #+#             */
/*   Updated: 2022/11/26 09:43:49 by mlektaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_drawplayerright(t_vars *vars)
{
	int	a;
	int	b;

	vars->img = mlx_xpm_file_to_image(vars->mlx,
			"./img/fishr.xpm", &a, &b);
	ft_checkimg(vars);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->img, vars->x, vars->y);
	mlx_destroy_image(vars->mlx, vars->img);
	ft_cleanlastpos(vars->x - 50, vars->y, vars);
}

void	ft_drawplayerleft(t_vars *vars)
{
	int	a;
	int	b;

	vars->img = mlx_xpm_file_to_image(vars->mlx,
			"./img/fish left.xpm", &a, &b);
	ft_checkimg(vars);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->img, vars->x, vars->y);
	mlx_destroy_image(vars->mlx, vars->img);
	ft_cleanlastpos(vars->x + 50, vars->y, vars);
}

void	ft_drawplayerup(t_vars *vars)
{
	int	a;
	int	b;

	vars->img = mlx_xpm_file_to_image(vars->mlx,
			"./img/fish up.xpm", &a, &b);
	ft_checkimg(vars);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->img, vars->x, vars->y);
	mlx_destroy_image(vars->mlx, vars->img);
	ft_cleanlastpos(vars->x, vars->y + 50, vars);
}

void	ft_drawplayerdown(t_vars *vars)
{
	int	a;
	int	b;

	vars->img = mlx_xpm_file_to_image(vars->mlx,
			"./img/fish down.xpm", &a, &b);
	ft_checkimg(vars);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->img, vars->x, vars->y);
	mlx_destroy_image(vars->mlx, vars->img);
	ft_cleanlastpos(vars->x, vars->y - 50, vars);
}
