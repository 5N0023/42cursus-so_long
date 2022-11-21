/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlektaib <mlektaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 22:08:39 by mlektaib          #+#    #+#             */
/*   Updated: 2022/11/21 22:54:23 by mlektaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	char	*moves;

	ft_putstr_fd("moves : ", 1);
	ft_putnbr_fd(vars->moves, 1);
	ft_putchar_fd('\n', 1);
}
