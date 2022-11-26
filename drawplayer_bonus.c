/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawplayer_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlektaib <mlektaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 22:26:01 by mlektaib          #+#    #+#             */
/*   Updated: 2022/11/26 09:38:19 by mlektaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
		ft_checkimg(vars);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img, vars->x, vars->y);
		mlx_destroy_image(vars->mlx, vars->img);
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
		ft_drawplayerleft(vars);
		vars->moves++;
		ft_showmoves(vars);
	}
	else
	{
		ft_cleanlastpos(vars->x, vars->y, vars);
		vars->img = mlx_xpm_file_to_image(vars->mlx,
				"./img/fish left.xpm", &a, &b);
		ft_checkimg(vars);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img, vars->x, vars->y);
		mlx_destroy_image(vars->mlx, vars->img);
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
		ft_drawplayerup(vars);
		vars->moves++;
		ft_showmoves(vars);
	}
	else
	{
		ft_cleanlastpos(vars->x, vars->y, vars);
		vars->img = mlx_xpm_file_to_image(vars->mlx,
				"./img/fish up.xpm", &a, &b);
		ft_checkimg(vars);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img, vars->x, vars->y);
		mlx_destroy_image(vars->mlx, vars->img);
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
		ft_drawplayerdown(vars);
		vars->moves++;
		ft_showmoves(vars);
	}
	else
	{
		ft_cleanlastpos(vars->x, vars->y, vars);
		vars->img = mlx_xpm_file_to_image(vars->mlx,
				"./img/fish down.xpm", &a, &b);
		ft_checkimg(vars);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img, vars->x, vars->y);
		mlx_destroy_image(vars->mlx, vars->img);
	}
}
