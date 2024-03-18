/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmart2 <albmart2@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 09:33:02 by albmart2          #+#    #+#             */
/*   Updated: 2024/02/20 15:36:34 by albmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*src;

	src = malloc(count * size);
	if (src == NULL)
		return (src);
	ft_bzero(src, size * count);
	return (src);
}

/*int main()
{
	printf("%s", ft_calloc(3,5));
	return (0);
}*/
