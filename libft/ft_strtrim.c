/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmart2 <albmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:07:27 by albmart2          #+#    #+#             */
/*   Updated: 2024/03/05 18:57:52 by albmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	while (ft_strchr (set, *s1) && *s1 != '\0')
		s1++;
	i = ft_strlen((char *)s1);
	while (ft_strchr (set, s1[i]) && i != 0)
		i--;
	return (ft_substr((char *)s1, 0, i + 1));
}

/*int main()
{
	char str[] = "   hola  ";
	char set[] = " ";

	printf("%s", ft_strtrim(str, set));
	return (0);
}*/
