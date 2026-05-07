/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:09:59 by linux-babas       #+#    #+#             */
/*   Updated: 2025/12/06 00:24:02 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*first_loop(int fd, char *buf, char *storage, int *read_len)
{
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	*read_len = read(fd, buf, BUFFER_SIZE);
	if (*read_len == -1 || (*read_len == 0 && storage[0] == '\0'))
	{
		free(buf);
		free(storage);
		return (NULL);
	}
	buf[*read_len] = 0;
	storage = ft_strjoin_free(storage, buf, 1, 1);
	buf = NULL;
	return (storage);
}

static char	*read_line(int fd, char *storage)
{
	char	*buf;
	int		read_len;

	read_len = 1;
	buf = NULL;
	if (storage != NULL)
	{
		buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
		read_len = read(fd, buf, BUFFER_SIZE);
		buf[read_len] = 0;
		if (read_len > 0)
			storage = ft_strjoin_free(storage, buf, 1, 1);
		buf = NULL;
	}
	else
	{
		storage = malloc(sizeof(char) * 1);
		storage[0] = 0;
	}
	while (read_len > 0 && ft_strchr(storage, '\n') == NULL)
		storage = first_loop(fd, buf, storage, &read_len);
	return (storage);
}

static char	*store_line(char *storage)
{
	int		i;
	char	*line;

	line = NULL;
	if (storage == NULL)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (storage[i] == '\n')
		i++;
	line = ft_substr(storage, 0, i);
	return (line);
}

static char	*storage_cleaner(char *storage)
{
	int		i;
	int		j;
	char	*new_storage;

	if (storage == NULL)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (storage[i] == '\n')
		i++;
	j = ft_strlen(storage);
	if (i == j || storage[i] == '\0')
	{
		free(storage);
		return (NULL);
	}
	new_storage = ft_substr(storage, i, j);
	free(storage);
	return (new_storage);
}

char	*get_next_line(int fd)
{
	static char	*storage[1024];
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage[fd] = read_line(fd, storage[fd]);
	line = store_line(storage[fd]);
	storage[fd] = storage_cleaner(storage[fd]);
	return (line);
}
