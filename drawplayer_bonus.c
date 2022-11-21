/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawplayer_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlektaib <mlektaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 22:26:01 by mlektaib          #+#    #+#             */
/*   Updated: 2022/11/20 22:27:11 by mlektaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void ft_drawplayerright(t_vars *vars)
{
	int a;
	int b;
	vars->img = mlx_xpm_file_to_image(vars->mlx,
				"./img/fishr.xpm", &a, &b);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img,vars->x, vars->y);
		mlx_destroy_image(vars->mlx,vars->img);
		ft_cleanlastpos(vars->x-50, vars->y, vars);
}
		

void	ft_moveright(t_vars *vars)
{
	int	a;
	int	b;

	vars->vision = 3;
	if (!ft_checkwall(vars->x + 50, vars->y, vars))
	{
		vars->x += 50;
		ft_drawplayerright(vars);
		vars->moves++;
		ft_showmoves(vars);
	}
	else 
	{
		ft_cleanlastpos(vars->x, vars->y, vars);
		vars->img = mlx_xpm_file_to_image(vars->mlx,
				"./img/fishr.xpm", &a, &b);
		mlx_put_image_to_window(vars->mlx, vars->win,
				vars->img, vars->x, vars->y);
		mlx_destroy_image(vars->mlx,vars->img);
	}
}

void	ft_moveleft(t_vars *vars)
{
	int	a;
	int	b;

	vars->vision = 4;
	if (!ft_checkwall(vars->x - 50, vars->y, vars))
	{
		vars->x -= 50;
		vars->img = mlx_xpm_file_to_image(vars->mlx,
				"./img/fish left.xpm", &a, &b);
		mlx_put_image_to_window(vars->mlx, vars->win,
				vars->img, vars->x, vars->y);
		mlx_destroy_image(vars->mlx,vars->img);
		ft_cleanlastpos(vars->x+50, vars->y, vars);
		vars->moves++;
		ft_showmoves(vars);
	}
	else 
	{
			ft_cleanlastpos(vars->x, vars->y, vars);
			vars->img = mlx_xpm_file_to_image(vars->mlx,
					"./img/fish left.xpm", &a, &b);
			mlx_put_image_to_window(vars->mlx, vars->win,
					vars->img, vars->x, vars->y);
			mlx_destroy_image(vars->mlx,vars->img);
	}
}

void	ft_moveup(t_vars *vars)
{
	int	a;
	int	b;

	vars->vision = 1;
	if (!ft_checkwall(vars->x, vars->y - 50, vars))
	{
		vars->y -= 50;
		vars->img = mlx_xpm_file_to_image(vars->mlx,
				"./img/fish up.xpm", &a, &b);
		mlx_put_image_to_window(vars->mlx, vars->win,
				vars->img, vars->x, vars->y);
		mlx_destroy_image(vars->mlx,vars->img);
		ft_cleanlastpos(vars->x, vars->y+50, vars);
		vars->moves++;
		ft_showmoves(vars);
	}
	else 
	{
		ft_cleanlastpos(vars->x, vars->y, vars);
		vars->img = mlx_xpm_file_to_image(vars->mlx,
				"./img/fish up.xpm", &a, &b);
		mlx_put_image_to_window(vars->mlx, vars->win,
				vars->img, vars->x, vars->y);
		mlx_destroy_image(vars->mlx,vars->img);
	}
}

void	ft_movedown(t_vars *vars)
{
	int	a;
	int	b;

	vars->vision = 2;
	if (!ft_checkwall(vars->x, vars->y + 50, vars))
	{
		vars->y += 50;
		vars->img = mlx_xpm_file_to_image(vars->mlx,
				"./img/fish down.xpm", &a, &b);
		mlx_put_image_to_window(vars->mlx, vars->win,
				vars->img, vars->x, vars->y);
		mlx_destroy_image(vars->mlx,vars->img);
		ft_cleanlastpos(vars->x, vars->y-50, vars);
		vars->moves++;
		ft_showmoves(vars);
	}
	else 
	{
		ft_cleanlastpos(vars->x, vars->y, vars);
		vars->img = mlx_xpm_file_to_image(vars->mlx,
				"./img/fish down.xpm", &a, &b);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img, vars->x, vars->y);
		mlx_destroy_image(vars->mlx,vars->img);
	}
}