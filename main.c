/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlektaib <mlektaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 23:37:47 by mlektaib          #+#    #+#             */
/*   Updated: 2022/11/13 01:34:33 by mlektaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int arg, char *map[])
{
	t_vars	vars;
	int		fd;

	fd = open(map[1], O_RDONLY);
	if (arg != 2 || fd < 0 || ft_checkmap1(map[1], &vars, fd) == -1)
	{
		ft_putstr_fd("Error : map not valid\n", 1);
		return (0);
	}
	if (ft_checkpath(&vars,vars.startx,vars.starty,vars.colcount) == -1)
		{
			ft_putstr_fd("Error : map not valid\n", 1);
			return 0;
		}
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.w, vars.h, map[0]);
	mlx_clear_window(vars.mlx, vars.win);
	ft_drawmap(&vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
