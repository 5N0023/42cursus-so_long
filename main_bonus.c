/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlektaib <mlektaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 23:37:47 by mlektaib          #+#    #+#             */
/*   Updated: 2022/11/26 09:33:25 by mlektaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_makezero(t_vars *vars)
{
	vars->moves = 0;
	vars->colcount = 0;
	vars->door = 0;
	vars->status = 0;
}	

int	main(int arg, char *map[])
{
	t_vars	vars;
	int		fd;

	ft_makezero(&vars);
	fd = open(map[1], O_RDONLY);
	if (arg != 2 || fd < 0 || ft_checkmap1(map[1], &vars, fd) == -1
		|| ft_checkpath(&vars) == -1)
	{
		ft_putstr_fd("Error : map not valid\n", 1);
		exit (1);
	}
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.w, vars.h, map[0]);
	ft_drawmap(&vars);
	ft_showmoves(&vars);
	mlx_hook(vars.win, 2, 0, key_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
