/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmart2 <albmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:41:39 by albmart2          #+#    #+#             */
/*   Updated: 2024/03/05 19:56:00 by albmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dst2;
	unsigned const char	*src2;

	dst2 = dst;
	src2 = src;
	if (dst < src)
		return (ft_memcpy(dst, src, len));
	if (!len || dst2 == src2)
		return (dst);
	while (len--)
		dst2[len] = src2[len];
	return (dst);
}

/*int main()
{
	char dst[] = "";
	char src[] = "hola";

	printf("%s", ft_memmove(dst, src, 2));
	return (0);
}*/
