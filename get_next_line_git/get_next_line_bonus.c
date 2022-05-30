/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovikav <anovikav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:11:51 by anovikav          #+#    #+#             */
/*   Updated: 2021/12/21 15:45:31 by anovikav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static t_list	*free_all(t_list *buffer)
{
	t_list	*tmp;

	tmp = buffer->next;
	free(buffer->buff);
	free(buffer);
	buffer = tmp;
	buffer = NULL;
	return (tmp);
}

static t_list	*init_buffer(int fd)
{
	t_list	*buffer;

	buffer = malloc(sizeof(t_list));
	if (!buffer)
		return (NULL);
	buffer->buff = ft_calloc(sizeof(char), BUFFER_SIZE);
	if (!(buffer->buff))
		return (free(buffer), NULL);
	buffer->lengh = read(fd, buffer->buff, BUFFER_SIZE);
	if (buffer->lengh < 0)
	{
		free(buffer->buff);
		free(buffer);
		return (NULL);
	}
	buffer->index = 0;
	if (!buffer->lengh)
		buffer->eof = TRUE;
	else
		buffer->eof = FALSE;
	buffer->next = NULL;
	return (buffer);
}

static char	*get_str(register int pos_end, register t_list **buffer)
{
	register int	index;
	register char	*str;
	char			*ptr;

	if (!((*buffer)->lengh))
		return (NULL);
	str = malloc(sizeof(char) * (pos_end + 1));
	if (!str)
		return (NULL);
	ptr = str;
	index = (*buffer)->index;
	if (pos_end == -1)
		return (free(str), NULL);
	while (pos_end--)
	{
		*str++ = (*buffer)->buff[index++];
		if (index == (*buffer)->lengh)
		{
			*buffer = free_all(*buffer);
			index = 0;
		}
	}
	if (*buffer)
		(*buffer)->index = index;
	*str = '\0';
	return (ptr);
}

static int	end_line(int fd, register t_list *buffer)
{
	register int	i;
	register int	pos_end;
	t_list			*tmp;

	i = buffer->index;
	pos_end = 0;
	while (buffer->buff[i] && i <= buffer->lengh)
	{
		++pos_end;
		if ((i == buffer->lengh && buffer->eof) || buffer->buff[i] == '\n')
			break ;
		++i;
		if (i == buffer->lengh)
		{
			tmp = init_buffer(fd);
			if (!tmp)
				return (-1);
			tmp->next = buffer->next;
			buffer->next = tmp;
			buffer = tmp;
			i = 0;
		}
	}
	return (pos_end);
}

char	*get_next_line(int fd)
{
	static t_list	*fd_open[MAX_OPEN];
	char			*str;
	int				pos_end;

	if (fd < 0)
		return (NULL);
	if (!fd_open[fd])
		fd_open[fd] = init_buffer(fd);
	if (!fd_open[fd])
		return (NULL);
	pos_end = end_line(fd, fd_open[fd]);
	if (fd_open[fd] != NULL && fd_open[fd]->eof == TRUE)
	{
		free(fd_open[fd]->buff);
		free(fd_open[fd]);
		fd_open[fd] = NULL;
		return (NULL);
	}
	str = get_str(pos_end, &fd_open[fd]);
	if (!str)
		return (NULL);
	return (str);
}
