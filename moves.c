#include "so_long.h"

void ft_moveright(t_vars *vars)
{
	int a;
	int b;

	if (ft_checkwall(vars->x + 50,vars->y,vars))
		{
		vars->x += 50;
		vars->img = mlx_xpm_file_to_image(vars->mlx,"./img/fish right.xpm",&a,&b);
		mlx_put_image_to_window(vars->mlx,vars->win,vars->img,vars->x,vars->y);
		ft_cleanlastpos(vars->x-50,vars->y,vars);
		}
	else 
	{
			ft_cleanlastpos(vars->x,vars->y,vars);
			vars->img = mlx_xpm_file_to_image(vars->mlx,"./img/fish right.xpm",&a,&b);
			mlx_put_image_to_window(vars->mlx,vars->win,vars->img,vars->x,vars->y);
	}
}

void ft_moveleft(t_vars *vars)
{
	int a;
	int b;
	if (ft_checkwall(vars->x - 50,vars->y,vars))
	{
		vars->x -= 50;
		vars->img = mlx_xpm_file_to_image(vars->mlx,"./img/fish left.xpm",&a,&b);
		mlx_put_image_to_window(vars->mlx,vars->win,vars->img,vars->x,vars->y);
		ft_cleanlastpos(vars->x+50,vars->y,vars);
	}
	else 
	{
			ft_cleanlastpos(vars->x,vars->y,vars);
			vars->img = mlx_xpm_file_to_image(vars->mlx,"./img/fish left.xpm",&a,&b);
			mlx_put_image_to_window(vars->mlx,vars->win,vars->img,vars->x,vars->y);
	}
}
void ft_moveup(t_vars *vars)
{
	int a;
	int b;

	if(ft_checkwall(vars->x,vars->y - 50,vars))
		{
			vars->y -= 50;
			vars->img = mlx_xpm_file_to_image(vars->mlx,"./img/fish up.xpm",&a,&b);
			mlx_put_image_to_window(vars->mlx,vars->win,vars->img,vars->x,vars->y);
			ft_cleanlastpos(vars->x,vars->y+50,vars);
		}
	else 
	{
			ft_cleanlastpos(vars->x,vars->y,vars);
			vars->img = mlx_xpm_file_to_image(vars->mlx,"./img/fish up.xpm",&a,&b);
			mlx_put_image_to_window(vars->mlx,vars->win,vars->img,vars->x,vars->y);
	}
}
void ft_movedown(t_vars *vars)
{
	int a;
	int b;

	if (ft_checkwall(vars->x,vars->y + 50,vars))
		{
			vars->y += 50;
			vars->img = mlx_xpm_file_to_image(vars->mlx,"./img/fish down.xpm",&a,&b);
			mlx_put_image_to_window(vars->mlx,vars->win,vars->img,vars->x,vars->y);
			ft_cleanlastpos(vars->x,vars->y-50,vars);
		}
	else 
	{
			ft_cleanlastpos(vars->x,vars->y,vars);
			vars->img = mlx_xpm_file_to_image(vars->mlx,"./img/fish down.xpm",&a,&b);
			mlx_put_image_to_window(vars->mlx,vars->win,vars->img,vars->x,vars->y);
	}
}
int	key_hook(int keycode, t_vars *vars)
{
	int a;
	int b;

	if(keycode == 13)
		ft_moveup(vars);
	 if(keycode == 1)
	 	ft_movedown(vars);
	if(keycode == 2)
		ft_moveright(vars);
	if(keycode == 0)
		ft_moveleft(vars);
	if(keycode == 53)
	{
		mlx_clear_window(vars->mlx,vars->win);
		free(vars->map);
		exit(1);
	}
	ft_checkcollective(vars);
	return (0);
}