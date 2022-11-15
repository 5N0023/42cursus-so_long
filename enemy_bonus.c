#include "so_long_bonus.h"


void	ft_checkcollective3(t_vars *vars,char d)
{
	int	n;

	
	n = ((vars->enemyy/50) * (vars->w/50)) + (vars->enemyx / 50);
	if (d == 'r')
		n--;
	if (d == 'l')
		n++;
	if (vars->map[n] == 'C')
		ft_drawcollective(vars,n);
}
char *ft_strpos(char d)
{
	static int m;
	char str[15]="./img/frames/f";

	char *pos;
	char xpm[5] = ".xpm";
	pos = malloc(sizeof(char) * 20);
	ft_memmove(pos,str,14);
	if (m > 9)
		m = 0;
	pos[14] = d;
 	pos[15] = m+48;
	ft_memmove(pos+16,xpm,5);
	m++;
    return (pos);
}

void ft_drawframesright(t_vars *vars)
{
	int a;
	char *pos;
	int b;
	
	ft_cleanlastpos(vars->enemyx-50,vars->enemyy,vars);
	pos = ft_strpos('r');
	vars->img = mlx_xpm_file_to_image(vars->mlx, pos, &a, &b);
	ft_checkimg(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->enemyx, vars->enemyy);
	free(pos);
	ft_checkcollective3(vars,'r');

}
void ft_drawframesleft(t_vars *vars)
{
	int a;
	char *pos;
	int b;
	ft_cleanlastpos(vars->enemyx+50,vars->enemyy,vars);
	pos = ft_strpos('l');
	vars->img = mlx_xpm_file_to_image(vars->mlx, pos, &a, &b);
	ft_checkimg(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->enemyx, vars->enemyy);
	free(pos);
	ft_checkcollective3(vars,'l');
}
void	ft_moveenemyright(t_vars *vars, int *m)
{
	int	a;
	int	b;
	int x;
	int y;
	
	int i = 0;
	if (!ft_checkwall(vars->enemyx + 50, vars->enemyy, vars))
		{
			vars->enemyd = 1;
			vars->enemyx += 50;
			ft_drawframesright(vars);
		}
	else 
	{
		*m = 0;
		ft_moveenemyleft(vars);
	}
}


void	ft_moveenemyleft(t_vars *vars)
{
	int	a;
	int	b;
	int x;
	int y;
	static int m;	
	if (!ft_checkwall(vars->enemyx - 50, vars->enemyy, vars) && m == 0)
		{
			m = 0;
			vars->enemyd = 0;
			vars->enemyx -= 50;
			ft_drawframesleft(vars);
		}
	else 
	{
		m = 1;
		ft_moveenemyright(vars,&m);
	}
}
void ft_moveenemy(t_vars *vars)
{
	if (vars->status == 0)
		ft_moveenemyleft(vars);
}
