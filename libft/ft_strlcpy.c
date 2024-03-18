/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmart2 <albmart2@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:35:50 by albmart2          #+#    #+#             */
/*   Updated: 2024/03/04 17:50:41 by albmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	len;

	if (n == 0)
		return (ft_strlen(src));
	i = 0;
	len = ft_strlen(src);
	while (i < len && i < (n - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len);
}

/*int main()
{
	char dest[] = "";
	char src[] = "hola";

	printf("%zu", ft_strlcpy(dest, src, 5));
	return (0);
}*/
