/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmart2 <albmart2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 22:03:08 by albmart2          #+#    #+#             */
/*   Updated: 2024/03/04 15:13:08 by albmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/*int main()
{
	char string[] = "hola";

	ft_bzero(string, 2 * sizeof(string));
	printf("%s", string);

	int	number[10] = {5, 4, 3, 2, 1};
	ft_bzero(number, 3 * sizeof(int));
	size_t i  = 0;
	while (i < 5)
	{
		printf("%i", number[i]);
		i++;
	}
	return (0);
}*/
