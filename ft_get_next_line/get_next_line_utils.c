/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmart2 <albmart2@student.madrid42>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:23:33 by albmart2          #+#    #+#             */
/*   Updated: 2025/01/29 18:02:14 by albmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

size_t	ft_strlen(const char *c)
{
	size_t	n;

	n = 0;
	while (c[n] != '\0')
		n++;
	return (n);
}

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		n;
	char	*str;

	str = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	n = 0;
	while (s2[n] != '\0')
	{
		str[i] = s2[n];
		i++;
		n++;
	}
	str[i] = '\0';
	return (str);
}
