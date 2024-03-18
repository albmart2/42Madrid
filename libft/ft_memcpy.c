/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmart2 <albmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 22:56:20 by albmart2          #+#    #+#             */
/*   Updated: 2024/03/05 19:59:43 by albmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dest2;
	const unsigned char	*src2;
	size_t				i;

	dest2 = dest;
	src2 = src;
	i = 0;
	while (i < n && dest2 != src2)
	{
		dest2[i] = src2[i];
		i++;
	}
	return (dest);
}

/*int main()
{
	char dest[] = "";
	char src[] = "holaaaaaa";

	printf("%s", ft_memcpy(dest, src, 1));
	return (0);
}*/
