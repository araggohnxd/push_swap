/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl_multifd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:06:22 by maolivei          #+#    #+#             */
/*   Updated: 2022/06/28 13:54:09 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_extract_line(char *buffer, char *cache)
{
	size_t	i;
	char	*aux;

	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		++i;
	aux = ft_substr(buffer, 0, (i + 1));
	if (buffer[i] && buffer[i + 1])
		ft_strlcpy(cache, &buffer[i + 1], (ft_strlen(&buffer[i + 1]) + 1));
	else
		ft_bzero(cache, ft_strlen(cache));
	free(buffer);
	return (aux);
}

static char	*ft_read_line(int fd, char *buffer)
{
	int		read_ret;
	char	*aux;

	read_ret = TRUE;
	while (read_ret)
	{
		if (ft_strchr(buffer, '\n'))
			break ;
		aux = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
		read_ret = read(fd, aux, BUFFER_SIZE);
		if (read_ret < 1)
		{
			free(aux);
			break ;
		}
		aux[read_ret] = '\0';
		buffer = ft_strjoin_free(&buffer, &aux);
	}
	if (!*buffer)
		ft_memfree((void *) &buffer);
	return (buffer);
}

char	*ft_gnl_multifd(int fd)
{
	static char	*cache[MAX_FD_VALUE];
	char		*buffer;

	if (fd < 0 || fd >= MAX_FD_VALUE || BUFFER_SIZE < 1)
		return (NULL);
	if (!cache[fd])
		cache[fd] = (char *) ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	buffer = ft_read_line(fd, ft_strdup(cache[fd]));
	if (!buffer)
		ft_memfree((void *) &cache[fd]);
	return (ft_extract_line(buffer, cache[fd]));
}
