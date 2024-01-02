/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narigi-e <narigi-e@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:51:54 by narigi-e          #+#    #+#             */
/*   Updated: 2023/07/24 14:51:54 by narigi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchrr(char *s, int c)
{
	size_t	i;

	if (!s)
		return (0);
	if (c == 0)
	{
		i = ft_strlenn((char *)s);
		return (&s[i]);
	}
	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			return (&s[i]);
		i++;
	}
	return (0);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*temp;

	i = 0;
	temp = s;
	while (i < n)
	{
		temp[i] = 0;
		i++;
	}
}

char	*ft_strjoinn(char *line, char *buff)
{
	char	*ptr;

	if (line == 0)
	{
		line = (char *) malloc(1);
		line[0] = '\0';
	}
	if (line == 0 || buff == 0)
		return (0);
	ptr = (char *) malloc(ft_strlenn(line) + ft_strlenn(buff) + 1);
	if (ptr == 0)
		return (0);
	ptr = ft_append(ptr, line, buff);
	free (line);
	return (ptr);
}

size_t	ft_strlenn(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_append(char *dest, char *s1, char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1 && s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}
