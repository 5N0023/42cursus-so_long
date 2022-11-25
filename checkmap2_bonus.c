/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlektaib <mlektaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 22:09:18 by mlektaib          #+#    #+#             */
/*   Updated: 2022/11/25 12:05:08 by mlektaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*ft_strjoin1(char *map, char *line, int w)
{
	int		i;
	int		j;
	char	*newmap;

	i = -1;
	j = -1;
	if (!map)
		map = ft_strdup("");
	newmap = malloc(ft_strlen(map) + ft_strlen(line) + 1);
	if (!newmap)
		return (0);
	while (map[++i] != 0 && map[i] != '\n')
		newmap[i] = map[i];
	while (line[++j] != 0 && line[j] != '\n')
		newmap[i + j] = line[j];
	newmap[i + j] = 0;
	if (ft_strlen(newmap) % (w / 50) != 0)
	{
		free(map);
		free(newmap);
		free(line);
		return (0);
	}
	free(map);
	return (newmap);
}

void	ft_setvariables(int *i, int *e, int *p, int *c)
{
	*i = 0;
	*e = 0;
	*p = 0;
	*c = 0;
}

void	ft_setfirstpos(t_vars *vars, int i)
{
	vars->startx = (i % (vars->w / 50)) * 50;
	vars->starty = (i / (vars->w / 50)) * 50;
}

int	ft_checkcontent(char c, t_vars *vars)
{
	if (c == 'B')
	{
		vars->enemycount++;
		return (1);
	}
	else if (c == 'C')
	{
		vars->colcount++;
		return (1);
	}
	return (0);
}

int	ft_checkmap4(t_vars *vars)
{
	int	i;
	int	e;
	int	p;
	int	c;

	ft_setvariables(&i, &e, &p, &c);
	while (vars->map[++i])
	{
		if (vars->map[i] == 'E')
			e++;
		else if (vars->map[i] == 'P')
		{
			ft_setfirstpos(vars, i);
			p++;
		}
		else if (ft_checkcontent(vars->map[i], vars))
			continue ;
		else if (vars->map[i] != '0' && vars->map[i] != '1')
			return (-1);
	}
	if (e > 1 || e == 0 || p > 1 || p == 0 || vars->colcount == 0
		|| vars->enemycount != 1)
		return (-1);
	return (0);
}
