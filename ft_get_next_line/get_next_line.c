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

char	*get_next_line(int fd)
{
	//Donde vamos a guardar la linea
	static char	buffer[BUFFER_SIZE+1];
	//Donde vamos a guardar los bytes a la hora de guardar la linea para imprimirlo después
	char bytes;
	char *line;
	int i;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (NULL);
	}
	bytes = read(fd, buffer, BUFFER_SIZE);
	line = malloc(bytes + 1);
	if (!line)
		return (NULL);

	i = 0;
	while (i <= bytes)
	{
		line[i] = buffer[i];
		i++;
	}
	
	return (line);
	
}

int	main()
{
	printf("%s",get_next_line(open("prueba.txt", O_RDONLY, S_IRUSR)));
	return (0);
}
