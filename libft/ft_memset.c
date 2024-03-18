/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmart2 <albmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:31:36 by albmart2          #+#    #+#             */
/*   Updated: 2024/03/05 19:52:18 by albmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memset(void *a, int c, size_t len)
{
	unsigned char	*dest;
	size_t			i;

	i = 0;
	dest = a;
	while (i < len)
	{
		dest[i] = (unsigned char)c;
		i++;
	}
	return (a);
}

/*int main()
{
	char a[] = "hola";
	
	printf ("%s", ft_memset(a, '-', 3));
	return(0);
}*/
