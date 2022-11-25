/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlektaib <mlektaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 22:34:01 by mlektaib          #+#    #+#             */
/*   Updated: 2022/11/25 12:33:35 by mlektaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_drawframesright(t_vars *vars)
{
	int		a;
	char	*pos;
	int		b;

	ft_cleanlastpos(vars->enemyx - 50, vars->enemyy, vars);
	pos = ft_strpos('r');
	vars->img = mlx_xpm_file_to_image(vars->mlx, pos, &a, &b);
	ft_checkimg(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
		vars->enemyx, vars->enemyy);
	mlx_destroy_image(vars->mlx, vars->img);
	free(pos);
	ft_checkcollective3(vars, 'r');
}

void	ft_drawframesleft(t_vars *vars)
{
	int		a;
	char	*pos;
	int		b;

	ft_cleanlastpos(vars->enemyx + 50, vars->enemyy, vars);
	pos = ft_strpos('l');
	vars->img = mlx_xpm_file_to_image(vars->mlx, pos, &a, &b);
	ft_checkimg(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
		vars->enemyx, vars->enemyy);
	mlx_destroy_image(vars->mlx, vars->img);
	free(pos);
	ft_checkcollective3(vars, 'l');
}

void	ft_moveenemyright(t_vars *vars, int *m)
{
	if (!ft_checkwall(vars->enemyx + 50, vars->enemyy, vars))
	{
		vars->enemyd = 1;
		vars->enemyx += 50;
		ft_drawframesright(vars);
	}
	else
	{
		*m = 0;
		ft_moveenemyleft(vars);
	}
}

void	ft_moveenemyleft(t_vars *vars)
{
	static int	m;

	if (!ft_checkwall(vars->enemyx - 50, vars->enemyy, vars) && m == 0)
	{
		m = 0;
		vars->enemyd = 0;
		vars->enemyx -= 50;
		ft_drawframesleft(vars);
	}
	else
	{
		m = 1;
		ft_moveenemyright(vars, &m);
	}
}

void	ft_moveenemy(t_vars *vars)
{
	if (vars->status == 0)
		ft_moveenemyleft(vars);
}
