#include "so_long.h"

void ft_drawmap(t_vars *vars)
{
	int a;
	int b;
	int i = 0;
	while(vars->map[i])
	{
		if(vars->map[i])
			ft_drawwater(vars,i);
		if (vars->map[i] == '1')
			ft_drawwall(vars,i);
		if (vars->map[i] == 'C')
			ft_drawcollective(vars,i);
		if (vars->map[i] == 'P')
			ft_startpos(vars,i);
		 if (vars->map[i] == 'E')
			ft_drawexit(vars,i);
		i++;
	}
}