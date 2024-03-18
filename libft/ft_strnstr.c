/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmart2 <albmart2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:26:42 by albmart2          #+#    #+#             */
/*   Updated: 2024/03/04 17:59:16 by albmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	x;

	i = 0;
	x = 0;
	if (s2[x] == '\0')
		return ((char *)s1);
	while (s1[i] != '\0' && i < n)
	{
		while ((s1[i + x] == s2[x]) && ((x + i) < n) && (s2[x] != '\0'))
		{
			if (s2[x + 1] == '\0')
				return ((char *)&s1[i]);
			x++;
		}
		i++;
		x = 0;
	}
	return (0);
}

/*int main()
{
	char s1[] = "hola";
	char s2[] = "o";

	printf("%s", ft_strnstr(s1, s2, 3));
	return (0);
}*/
