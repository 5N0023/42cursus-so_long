/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlektaib <mlektaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 23:46:46 by mlektaib          #+#    #+#             */
/*   Updated: 2022/11/17 20:41:05 by mlektaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_moveright(t_vars *vars)
{
	int	a;
	int	b;

	vars->vision = 3;
	if (!ft_checkwall(vars->x + 50, vars->y, vars))
	{
		vars->x += 50;
		vars->img = mlx_xpm_file_to_image(vars->mlx,
				"./img/fishr.xpm", &a, &b);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img,vars->x, vars->y);
		mlx_destroy_image(vars->mlx,vars->img);
		ft_cleanlastpos(vars->x-50, vars->y, vars);
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

int	key_hook(int keycode, t_vars *vars)
{
	int	a;
	int	b;
	
	if (ft_checkwin(vars) == 1)
	{
		if (keycode == 13)
			ft_moveup(vars);
		if (keycode == 1)
			ft_movedown(vars);
		if (keycode == 2)
			ft_moveright(vars);
		if (keycode == 0)
			ft_moveleft(vars);
		ft_checkcollective(vars);
	}
	if (keycode == 53)
		{
			free(vars->map);
			exit(1);
		}
	return (0);
}
