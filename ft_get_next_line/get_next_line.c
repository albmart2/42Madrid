/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmart2 <albmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 20:55:20 by albmart2          #+#    #+#             */
/*   Updated: 2024/12/30 20:59:07 by albmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

char    *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE + 1];
    char        *line;
    char        *temp;
    ssize_t     bytes_read;
    
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
        
    // Inicializar línea
    line = malloc(sizeof(char));
    if (!line)
        return (NULL);
    line[0] = '\0';
    
    // Leer hasta encontrar \n o EOF
    while (!ft_strchr(buffer, '\n'))
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read <= 0)
        {
            if (bytes_read == -1 || line[0] == '\0')
            {
                free(line);
                return (NULL);
            }
            return (line);
        }
        buffer[bytes_read] = '\0';
        temp = ft_strjoin(line, buffer);
        free(line);
        line = temp;
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