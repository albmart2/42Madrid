/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmart2 <albmart2@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:16:05 by albmart2          #+#    #+#             */
/*   Updated: 2024/03/04 18:02:18 by albmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strrchr(const char *string, int c)
{
	int	n;

	n = 0;
	while (string[n] != '\0')
		n++;
	while (n >= 0)
	{
		if (string[n] == (char)c)
			return ((char *)(string + n));
		n--;
	}
	return (NULL);
}

/*int main()
{
	char str[] = "hola";

	printf ("%s", ft_strrchr(str, 'o'));
	return (0);
}*/
