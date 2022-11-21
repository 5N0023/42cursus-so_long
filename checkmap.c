/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlektaib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 22:09:01 by mlektaib          #+#    #+#             */
/*   Updated: 2022/11/20 22:09:06 by mlektaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "so_long.h"

int	ft_checkmap3(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->map[i])
	{
		if (i / (vars->w / 50) < 1 && vars->map[i] != '1')
			return (-1);
		if (i / (vars->w / 50) >= (vars->h / 50) - 1 && vars->map[i] != '1')
			return (-1);
		if (i % (vars->w / 50) == 0 && vars->map[i] != '1')
			return (-1);
		if (i % (vars->w / 50) == (vars->w / 50) - 1 && vars->map[i] != '1')
			return (-1);
		i++;
	}
	return (ft_checkmap4(vars));
}

int	ft_checkmap2(char *map, t_vars *vars)
{
	int		fd;
	char	*line;
	int		len;
	int		tmp;

	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	len = ft_strlen(line);
	map = NULL;
	while (line)
	{
		map = ft_strjoin1(map, line, vars->w);
		if (!map)
			return (-1);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	vars->map = map;
	if (ft_checkmap3(vars) == -1)
	{
		free(vars->map);
		return (-1);
	}
	return (0);
}

int	ft_checkmap1(const char *map, t_vars *vars, int fd)
{
	char	*line;
	int		countlines;

	countlines = 0;
	line = get_next_line(fd);
	if (!line)
		return (-1);
	vars->w = (ft_strlen(line) - 1) * 50;
	while (line)
	{
		free(line);
		if (*line == '\n')
			return (-1);
		line = get_next_line(fd);
		countlines++;
	}
	vars->h = countlines * 50;
	close(fd);
	if (ft_checkmap2((char *)map, vars) == -1)
		return (-1);
	return (0);
}
