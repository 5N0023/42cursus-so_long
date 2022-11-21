/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkwin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlektaib <mlektaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 22:10:13 by mlektaib          #+#    #+#             */
/*   Updated: 2022/11/21 23:13:26 by mlektaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_clearwin(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i++ < vars->w)
	{
		j = -1;
		while (j++ < vars->h)
		{
			mlx_pixel_put(vars->mlx, vars->win, i, j, 0xFFFFFF);
			j++;
		}
		i++;
	}
}

int	ft_checkwin(t_vars *vars)
{
	int	a;
	int	b;
	int	x;
	int	y;

	if (vars->colcount == 0 && vars->x == vars->exitx && vars->y == vars->exity
		&& vars->status == 0)
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
		mlx_destroy_image(vars->mlx, vars->img);
		return (0);
	}
	if (vars->status == 1)
		return (0);
	return (1);
}
