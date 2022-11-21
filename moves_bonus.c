/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlektaib <mlektaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 22:11:06 by mlektaib          #+#    #+#             */
/*   Updated: 2022/11/21 22:30:05 by mlektaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_move(int keycode, t_vars *vars)
{
	if (keycode == 13)
		ft_moveup(vars);
	if (keycode == 1)
		ft_movedown(vars);
	if (keycode == 2)
		ft_moveright(vars);
	if (keycode == 0)
		ft_moveleft(vars);
}

int	key_hook(int keycode, t_vars *vars)
{
	int	a;
	int	b;

	if (vars->status == 0)
	{
		ft_move(keycode, vars);
		ft_drawsprite(vars);
		ft_checklose(vars);
		ft_checkwin(vars);
		ft_checkcollective(vars);
	}
	ft_moveenemy(vars);
	ft_checklose(vars);
	ft_checkwin(vars);
	if (keycode == 53)
	{
		free(vars->map);
		exit(1);
	}
	return (0);
}
