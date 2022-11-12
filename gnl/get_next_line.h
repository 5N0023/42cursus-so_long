/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlektaib <mlektaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:35:56 by mlektaib          #+#    #+#             */
/*   Updated: 2022/11/12 04:17:25 by mlektaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
#include "./../libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
int		read_file(int fd, int *readed, t_list **buffer);
void	add_tolist(char *content, t_list **buffer, int readed);
char	*extract_line(t_list *buffer);
void	allocline(t_list *buffer, char **line);
int		ft_check(t_list *buffer);
void	make_remain(t_list **head);

#endif
