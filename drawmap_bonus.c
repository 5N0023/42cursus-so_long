/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlektaib <mlektaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 23:44:30 by mlektaib          #+#    #+#             */
/*   Updated: 2022/11/20 21:44:52 by mlektaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void ft_drawenemy(t_vars *vars,int i)
{
	int	a;
	int	b;
	int	x;
	int	y;
	static int j;

	vars->enemyx = (i % (vars->w / 50)) * 50;
	vars->enemyy = (i / (vars->w / 50)) * 50;
	vars->img = mlx_xpm_file_to_image(vars->mlx, "./img/enemy.xpm", &a, &b);
	ft_checkimg(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, x, y);
	mlx_destroy_image(vars->mlx,vars->img);
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
void	ft_clearscore(t_vars *vars, int i)
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
	mlx_destroy_image(vars->mlx,vars->img);
}

void	ft_showmoves(t_vars *vars)
{
	char *moves;
	int i;

	i = 0;
	moves = ft_itoa(vars->moves);
	while (i++ < vars->w/50)
		ft_drawwall(vars,i);
	mlx_string_put(vars->mlx,vars->win,60,10,0xFFFFFF,"moves : ");
	mlx_string_put(vars->mlx,vars->win,140,10,0xFFFFFF,moves);
	ft_putstr_fd("moves : ", 1);
	ft_putnbr_fd(vars->moves, 1);
	ft_putchar_fd('\n', 1);
	free(moves);
}