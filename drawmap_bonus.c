/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlektaib <mlektaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 23:44:30 by mlektaib          #+#    #+#             */
/*   Updated: 2022/11/14 19:54:35 by mlektaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void ft_drawenemy(t_vars *vars,int i)
{
	int	a;
	int	b;
	int	x;
	int	y;

	x = (i % (vars->w / 50)) * 50;
	y = (i / (vars->w / 50)) * 50;
	vars->img = mlx_xpm_file_to_image(vars->mlx, "./img/enemy.xpm", &a, &b);
	ft_checkimg(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, x, y);
}
void	ft_drawmap(t_vars *vars)
{
	int	a;
	int	b;
	int	i;

	i = 0;
	while (vars->map[i])
	{
		if (vars->map[i])
			ft_drawwater(vars, i);
		if (vars->map[i] == '1')
			ft_drawwall(vars, i);
		if (vars->map[i] == 'B')
			ft_drawenemy(vars, i);
		if (vars->map[i] == 'C')
			ft_drawcollective(vars, i);
		if (vars->map[i] == 'P')
			ft_startpos(vars, i);
		if (vars->map[i] == 'E')
			ft_drawexit(vars, i);
		i++;
	}
}

void	ft_checkimg(t_vars *vars)
{
	if (!vars->img)
	{
		free(vars->map);
		ft_putstr_fd("Eroor !! xpm file deleted \n", 1);
		exit(1);
	}
}

void	ft_showmoves(t_vars *vars)
{
	ft_putstr_fd("moves : ", 1);
	ft_putnbr_fd(vars->moves, 1);
	ft_putchar_fd('\n', 1);
}
