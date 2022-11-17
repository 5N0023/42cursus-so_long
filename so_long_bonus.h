/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlektaib <mlektaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 23:41:42 by mlektaib          #+#    #+#             */
/*   Updated: 2022/11/17 21:56:34 by mlektaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include "stdlib.h"
# include "./libft/libft.h"

typedef struct s_vars {
	void	*mlx;
	void	*win;
	void	*img;
	int		collectivex;
	int		collectivey;
	int		exitx;
	int		exity;
	int		startx;
	int		starty;
	int		w;
	int		h;
	int		x;
	int		y;
	int		moves;
	char	*map;
	int		colcount;
	int		door;
	int		vision;
	int		*enemypos;
	int		enemycount;
	int		enemyx;
	int		enemyy;
	int		enemyd;
	int		status;
}				t_vars;

int		ft_checkmap1(const char *map, t_vars *vars, int fd);
void	ft_drawmap(t_vars *vars);
void	drawopendoor(t_vars *vars);
void	ft_drawwall(t_vars *vars, int i);
void	ft_drawcollective(t_vars *vars, int i);
void	ft_drawwater(t_vars *vars, int i);
void	ft_drawexit(t_vars *vars, int i);
void	ft_cleanlastpos(int x, int y, t_vars *vars);
int		ft_checkwall(int x, int y, t_vars *vars);
void	ft_checkcollective(t_vars *vars);
void	ft_startpos(t_vars *vars, int i);
int		key_hook(int keycode, t_vars *vars);
void	ft_checkimg(t_vars *vars);
void	ft_showmoves(t_vars *vars);
void	ft_showmoves(t_vars *vars);
int		ft_checkpath(t_vars *vars);
int		ft_checkwin(t_vars *vars);
int		ft_checklose(t_vars *vars);
void	ft_draweatanim(t_vars *vars);
int		ft_checkenemy1(int x, int y, t_vars *vars);
void	ft_moveenemy(t_vars *vars);
void	ft_drawframesright(t_vars *vars);
void	ft_drawframesleft(t_vars *vars);
void	ft_moveenemyleft(t_vars *vars);
void	drawopendoor(t_vars *vars);
void	drawcloseddoor(t_vars *vars);
void	ft_drawsprite(t_vars *vars);
#endif
