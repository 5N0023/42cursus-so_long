
#include "so_long.h"

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

void ft_setvariables(int *i,int *e,int *p ,int *c)
{
	*i = 0;
	*e = 0;
	*p = 0;
	*c = 0;
}
void ft_setfirstpos(t_vars *vars,int i)
{
	vars->startx = (i % (vars->w / 50)) * 50;
	vars->starty = (i / (vars->w / 50)) * 50;
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
			ft_setfirstpos(vars,i);
			p++;
		}
		else if (vars->map[i] == 'C')
			vars->colcount++;
		else if (vars->map[i] != '0' && vars->map[i] != '1')
			return (-1);
	}
	if (e > 1 || e == 0 || p > 1 || p == 0 || vars->colcount == 0)
		return (-1);
	return (0);
}