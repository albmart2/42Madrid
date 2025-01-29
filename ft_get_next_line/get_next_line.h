/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmart2 <albmart2@student.madrid42>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:25:21 by albmart2          #+#    #+#             */
/*   Updated: 2025/01/29 18:01:54 by albmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stddef.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *c);
char	*ft_strchr(const char *string, int c);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
