/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmart2 <albmart2@student.madrid42>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 20:55:20 by albmart2          #+#    #+#             */
/*   Updated: 2025/01/29 18:01:30 by albmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

char	*read_line(int fd, char *buffer)
{
	char	*line;
	ssize_t	bytes_read;
	int	i;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	line = malloc(bytes_read + 1);
	if (fd < 0 || !buffer || bytes_read <= 0)
	{
		return (NULL);
	}
	i = 0;
	while (i < bytes_read)
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	char		*temp;
	ssize_t		bytes_read;

	line = read_line(fd, buffer);
	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
	{
		return (NULL);
	}
	return (line);
}
/*int main()
{
    int     fd;
    char    *line;
    
    fd = open("prueba.txt", O_RDONLY);
    if (fd == -1)
        return (1);
        
    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}*/
