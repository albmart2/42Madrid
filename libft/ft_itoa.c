/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmart2 <albmart2@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:26:40 by albmart2          #+#    #+#             */
/*   Updated: 2024/02/13 17:02:50 by albmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static int	length(int n)
{
	int	length;

	length = 0;
	if (n <= 0)
		length++;
	while (n != 0)
	{
		length++;
		n /= 10;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	char	*string;
	int		len;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	len = length(n);
	string = (char *)malloc((len + 1) * sizeof(char));
	i = n;
	if (string == NULL)
		return (NULL);
	string[len--] = 0;
	if (i < 0)
	{
		string[0] = '-';
		i = i * -1;
	}
	while (i > 0)
	{
		string[len--] = '0' + (i % 10);
		i = i / 10;
	}
	return (string);
}

/*int main()
{
	printf("%s", ft_itoa(50));
	return (0);
}*/
