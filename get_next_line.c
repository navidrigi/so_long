/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narigi-e <narigi-e@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:51:31 by narigi-e          #+#    #+#             */
/*   Updated: 2023/07/24 14:51:31 by narigi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*temp;
	int			fd_read;
	static char	*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	fd_read = 1;
	temp = (char *) malloc(BUFFER_SIZE + 1);
	if (temp == 0)
		return (0);
	while (ft_strchrr(line, '\n') == 0 && fd_read)
	{
		fd_read = read(fd, temp, BUFFER_SIZE);
		if (fd_read == -1)
		{
			calcss(temp, line);
			return (0);
		}
		temp[fd_read] = '\0';
		line = ft_strjoinn(line, temp);
	}
	free(temp);
	temp = ft_read(line);
	line = ft_continue(line);
	return (temp);
}

void	calcss(char *temp, char *line)
{
	free(temp);
	ft_bzero(line, ft_strlenn(line));
}

char	*ft_read(char *str)
{
	int		i;
	char	*line;

	if (str == 0 || str[0] == 0)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = (char *) malloc(i + 1);
	if (line == 0)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_continue(char	*str)
{
	char	*new_buff;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (0);
	}
	i++;
	new_buff = (char *) malloc(ft_strlenn(str) - i + 1);
	if (new_buff == 0)
		return (0);
	while (str[i + j])
	{
		new_buff[j] = str[i + j];
		j++;
	}
	new_buff[j] = '\0';
	free(str);
	return (new_buff);
}

// int    main(void)
// {
// 	int		fd;
// 	int		i;
// 	char	*string;
// 	char	*file_name;

// 	file_name = "map1.ber";
// 	i = 0;
// 	printf("BUFFER_SIZE: %d\n", BUFFER_SIZE);
// 	fd = open(file_name, O_RDWR);
// 	if (fd == -1)
// 	{
// 		printf("open() failed.");
// 		return (0);
// 	}
// 	printf("File descriptor chosen: %d\n", fd);
// 	while (i < 20)
// 	{
// 		string = get_next_line(fd);
// 		printf("Return string: %s", string);
// 		i++;
// 		free(string);
// 	}
// 	if (close(fd) == -1)
// 	{
// 		printf("close() failed.");
// 		return (0);
// 	}
// }