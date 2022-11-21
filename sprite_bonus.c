/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlektaib <mlektaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 22:11:55 by mlektaib          #+#    #+#             */
/*   Updated: 2022/11/21 22:28:42 by mlektaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*ft_strframe(int d)
{
	char	str[15];
	char	*frame;
	char	xpm[5];

	ft_memmove(str, "./img/sprite/", 15);
	ft_memmove(xpm, ".xpm", 5);
	if (d < 10)
	{
		frame = malloc(sizeof(char) * 19);
		ft_memmove(frame, str, 13);
		frame[13] = d + 48;
		ft_memmove(frame + 14, xpm, 5);
		return (frame);
	}
	else
	{
		frame = malloc(sizeof(char) * 20);
		ft_memmove(frame, str, 13);
		frame[13] = (d / 10) + 48;
		frame[14] = (d % 10) + 48;
		ft_memmove(frame + 15, xpm, 5);
		return (frame);
	}
	return (0);
}

void	ft_drawanim(t_vars *vars, int f)
{
	int		a;
	int		b;
	char	*frame;

	frame = ft_strframe(f);
	vars->img = mlx_xpm_file_to_image(vars->mlx, frame, &a, &b);
	ft_checkimg(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	mlx_destroy_image(vars->mlx, vars->img);
	free(frame);
}

void	ft_drawsprite(t_vars *vars)
{
	static int	f;

	ft_drawanim(vars, f);
	f++;
	if (f == 20)
		f = 0;
}
