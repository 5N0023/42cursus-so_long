#include "so_long.h"

void ft_cleanlastpos(int x,int y,t_vars *vars)
{
	int a;
	int b;

	vars->img = mlx_xpm_file_to_image(vars->mlx,"./img/water.xpm",&a,&b);
	mlx_put_image_to_window(vars->mlx,vars->win,vars->img,x,y);
	if(x == vars->exitx && y == vars->exity)
	{
	vars->img = mlx_xpm_file_to_image(vars->mlx,"./img/closeddoor.xpm",&a,&b);
	mlx_put_image_to_window(vars->mlx,vars->win,vars->img,x,y);
	}
}

int ft_checkwall(int x,int y,t_vars *vars)
{
	int i = 0;
	int j = 0;
	int n;
	n = (vars->w / 50)  * (vars->h / 50);
	while(i < n - 1)
	{
		if(i  % (vars->w / 50) == x / 50 && i  / (vars->w / 50) == y/50)
			{	
				if(vars->map[i] == '1')
					return 0;
				else if(vars->map[i] == 'E' && vars->colcount == 0)
				{
					free(vars->map);
					exit(1);
				}
			}
		i++;
	}
	
	return 1;
}


void ft_checkcollective(t_vars *vars)
{
	int i = 0;
	int j = 0;
	int n;
	n = (vars->w / 50)  * (vars->h / 50);
	while(i < n - 1)
	{
		if(i  % (vars->w / 50) == vars->x / 50 && i  / (vars->w / 50) == vars->y/50)
			{
				
				if(vars->map[i] == 'C')
				{
					vars->colcount--;
					vars->map[i] = '0';
				}
			}
		i++;
	}
	if (vars->colcount == 0)
		drawopendoor(vars);
}

void ft_startpos(t_vars *vars, int i)
{
	int a;
	int b;
	vars->x = (i%(vars->w/50))*50;
	vars->y = (i/(vars->w/50))*50;
	vars->img = mlx_xpm_file_to_image(vars->mlx,"./img/fish right.xpm",&a,&b);
	mlx_put_image_to_window(vars->mlx,vars->win,vars->img,vars->x,vars->y);
	
}