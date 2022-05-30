/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovikav <anovikav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:11:42 by anovikav          #+#    #+#             */
/*   Updated: 2021/12/21 08:58:24 by anovikav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_bzero(void *s, size_t n)
{
	unsigned long int	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t type, size_t size)
{
	char	*ptr;

	ptr = malloc(size * type);
	if (ptr == 0)
		return (NULL);
	ft_bzero(ptr, size * type);
	return (ptr);
}
