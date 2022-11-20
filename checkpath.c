
#include "so_long.h"

int	ft_checkwall2(int x, int y,t_vars *vars,char *map)
{
	int	i;
	int	n;

	i = 0;
	n = ((y/50) * (vars->w/50)) + (x / 50);
	if (map[n] == '1')
				return (0);
	return (1);
}
int	ft_checkexit2(int x, int y,t_vars *vars,char *map)
{
	int	n;

	n = ((y/50) * (vars->w/50)) + (x / 50);
	if (map[n] == 'E')
				return (1);
	return (0);
}
int	ft_checkcollective2(int x, int y,t_vars *vars,char *map)
{
	int	n;

	n = ((y/50) * (vars->w/50)) + (x / 50);
	if (map[n] == 'C')
				return (1);
	return (0);
}

int ft_checkpath1(t_vars *vars,int x,int y,char *map)
{
	static int e;
	static int c;
	static int p;

	if(ft_checkcollective2(x,y,vars,map))
		c++;
	if(ft_checkexit2(x,y,vars,map))
		e++;
	map[((y/50) * (vars->w/50)) + (x / 50)] = '1';
	if (ft_checkwall2(x + 50, y, vars,map))
		ft_checkpath1(vars,x + 50,y,map);
	if (ft_checkwall2(x, y + 50, vars,map))
		ft_checkpath1(vars, x, y + 50,map);
	if (ft_checkwall2(x - 50, y,vars,map))
		ft_checkpath1(vars, x - 50, y,map);			
	if (ft_checkwall2(x, y - 50,vars,map))
		ft_checkpath1(vars, x, y - 50,map);
	if (c == vars->colcount && e == 1)
		return (1);	
	return (-1);
}

int ft_checkpath(t_vars *vars)
{
	char	*map;
	int		n;

	map = malloc(sizeof(char) * ft_strlen(vars->map) + 1);
	if(!map)
		return (-1);
	ft_memcpy(map,vars->map,ft_strlen(vars->map));
	map[ft_strlen(vars->map)] = 0;
	n = ft_checkpath1(vars,vars->startx,vars->starty,map);
	free(map);
	return (n);
}