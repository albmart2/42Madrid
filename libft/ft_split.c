/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmart2 <albmart2@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:01:51 by albmart2          #+#    #+#             */
/*   Updated: 2024/03/04 15:25:30 by albmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static size_t	count_len_str(const char *str, char c)
{
	size_t	i;
	size_t	cont;

	i = 0;
	cont = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		while (str[i] != c && str[i] != '\0')
		{
			i++;
			if (str[i] == c || str[i] == '\0')
				cont++;
		}
	}
	return (cont);
}

static char	**ft_free(char **src, int j)
{
	while (j >= 0)
	{
		free(src[j--]);
	}
	free(src);
	return (NULL);
}

static char	**whiletot(char const *s, char c, char **array)
{
	size_t	i;
	size_t	start;
	size_t	pos;

	i = 0;
	pos = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != '\0' && s[i] != c)
		{
			i++;
			if (s[i] == c || s[i] == '\0')
			{
				array[pos] = ft_substr(s, start, i - start);
				if (!array[pos])
					return (ft_free(array, pos));
				pos++;
			}
		}
	}
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	lens;

	lens = count_len_str(s, c);
	array = (char **)ft_calloc((lens + 1), sizeof(char *));
	if (!array)
		return (NULL);
	return (whiletot(s, c, array));
}

/*int main()
{
	char const *s = "Hola|este|es|un|ejemplo";
	char c = '|';
	char **result = ft_split(s, c);

	for (int i = 0; result[i] != NULL; i++)
		printf("%s\n", result[i]);
	return (0);
}*/
