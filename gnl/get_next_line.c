/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:00:41 by mrocher           #+#    #+#             */
/*   Updated: 2023/11/07 13:33:18 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*join_free(char *res, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(res, buffer);
	free(res);
	return (temp);
}

char	*read_fd(int fd, char *res)
{
	char	*buffer;
	int		rd;

	if (!res)
		res = ft_calloc(1, 1);
	rd = 1;
	buffer = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	while (rd > 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[rd] = '\0';
		res = join_free(res, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (res);
}

char	*ft_del(char *buffer, char *line)
{
	int		i;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc(sizeof(char), (ft_strlen(buffer) - i));
	i++;
	if (!line)
		return (NULL);
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	free (buffer);
	return (line);
}

char	*print_line(char *buffer, char *line)
{
	int	i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(sizeof(char), (i + 2));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*res;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(res);
		res = NULL;
		return (NULL);
	}
	res = read_fd(fd, res);
	if (res == NULL)
		return (NULL);
	line = print_line(res, line);
	res = ft_del(res, line);
	return (line);
}

/*#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1) 
		return (1);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s\n", line);
		free(line); 
	}
	close(fd);
	return (0);
}*/