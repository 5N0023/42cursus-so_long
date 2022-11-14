/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlektaib <mlektaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 23:02:41 by mlektaib          #+#    #+#             */
/*   Updated: 2022/11/14 19:55:44 by mlektaib         ###   ########.fr       */
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

int	ft_checkmap4(t_vars *vars)
{
	int	i;
	int	e;
	int	p;
	int	c;

	i = 0;
	e = 0;
	p = 0;
	c = 0;
	while (vars->map[i])
	{
		if (vars->map[i] == 'E')
			e++;
		else if (vars->map[i] == 'P')
		{
			vars->startx = (i % (vars->w / 50)) * 50;
			vars->starty = (i / (vars->w / 50)) * 50;
			p++;
		}
		else if (vars->map[i] == 'C')
			vars->colcount++;
		else if (vars->map[i] != '0' && vars->map[i] != '1' && vars->map[i] != 'B')
			return (-1);
		i++;
	}
	if (e > 1 || e == 0 || p > 1 || p == 0 || vars->colcount == 0)
		return (-1);
	return (0);
}

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
