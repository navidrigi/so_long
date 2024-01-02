/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narigi-e <narigi-e@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:52:05 by narigi-e          #+#    #+#             */
/*   Updated: 2023/07/24 14:52:05 by narigi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_strchrr(char *s, int c);
void	calcss(char *temp, char *line);
void	ft_bzero(void *s, size_t n);
char	*ft_strjoinn(char *line, char *buff);
size_t	ft_strlenn(char *str);
char	*ft_append(char *dest, char *s1, char *s2);
char	*ft_read(char *str);
char	*ft_continue(char *str);

#endif
