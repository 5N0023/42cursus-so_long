/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlektaib <mlektaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 22:34:01 by mlektaib          #+#    #+#             */
/*   Updated: 2022/11/21 22:46:28 by mlektaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_checkcollective3(t_vars *vars, char d)
{
	int	n;

	n = ((vars->enemyy / 50) * (vars->w / 50)) + (vars->enemyx / 50);
	if (d == 'r')
		n--;
	if (d == 'l')
		n++;
	if (vars->map[n] == 'C')
		ft_drawcollective(vars, n);
}

char	*ft_strpos(char d)
{
	static int	m;
	char		str[15];
	char		*pos;
	char		xpm[5];

	ft_memmove(xpm, ".xpm", 5);
	ft_memmove(str, "./img/frames/f", 15);
	pos = malloc(sizeof(char) * 20);
	ft_memmove(pos, str, 14);
	if (m > 9)
		m = 0;
	pos[14] = d;
	pos[15] = m + 48;
	ft_memmove(pos + 16, xpm, 5);
	m++;
	return (pos);
}
