/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlektaib <mlektaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 22:11:01 by mlektaib          #+#    #+#             */
/*   Updated: 2022/11/20 22:25:56 by mlektaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		ft_checkwin(vars);
		ft_checkcollective(vars);
	}
	ft_checkwin(vars);
	if (keycode == 53)
	{
		free(vars->map);
		exit(1);
	}
	return (0);
}
