/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovikav <anovikav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:11:58 by anovikav          #+#    #+#             */
/*   Updated: 2021/12/21 15:30:05 by anovikav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdio.h>
# include <stddef.h> 
# include <fcntl.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 60
# endif
# define MAX_OPEN 65535

typedef enum s_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef struct s_list
{
	char			*buff;
	int				lengh;
	int				index;
	t_bool			eof;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
void	*ft_calloc(size_t type, size_t size);

#endif
