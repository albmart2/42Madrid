/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmart2 <albmart2@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 22:04:11 by albmart2          #+#    #+#             */
/*   Updated: 2024/03/04 15:30:00 by albmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strchr(const char *string, int c)
{
	int	n;

	n = 0;
	while (string[n] != '\0')
	{
		if (string[n] == (char) c)
			return ((char *) string);
		string++;
	}
	if ((char) c == '\0')
		return ((char *) string);
	return (NULL);
}

/*int main()
{
	char string[] = "hola";

	printf("%s", ft_strchr(string, 'o'));
	return (0);
}*/
