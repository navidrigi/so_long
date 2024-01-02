/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narigi-e <narigi-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:03:41 by narigi-e          #+#    #+#             */
/*   Updated: 2023/10/11 15:22:54 by narigi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_file(t_data *data, char *argv)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	line = NULL;
	fd = open(argv, O_RDWR);
	data->rows = get_height(argv);
	data->columns = get_width(data, argv);
	data->array = (char **) malloc(sizeof(char *) * (data->rows + 1));
	while (i < data->rows)
		data->array[i++] = (char *) malloc(sizeof(char) * (data->columns + 1));
	i = 0;
	while (i < data->rows)
	{
		line = get_next_line(fd);
		fill_array(data->array[i], line, data);
		free(line);
		i++;
	}
	find_player_position(data);
	close(fd);
	data->array[i] = NULL;
}

int	get_height(char *argv)
{
	int		fd;
	int		height;
	char	*line;

	line = NULL;
	fd = open(argv, O_RDWR);
	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free (line);
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

int	get_width(t_data *data, char *argv)
{
	int		i;
	int		fd;
	int		width;
	char	*line;

	i = 0;
	line = NULL;
	fd = open(argv, O_RDWR);
	line = get_next_line(fd);
	width = ft_strlenn(line) - 1;
	while (i < data->rows)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (width);
}

void	fill_array(char *dest, char *src, t_data *data)
{
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		if (src[i] == '\n')
			break ;
		if (src[i] == 'C')
			data->collect_count++;
		else if (src[i] == 'P')
			data->players++;
		else if (src[i] == 'E')
			data->exits++;
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

void	find_player_position(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j < data->columns)
		{
			if (data->array[i][j] == 'P')
			{
				saving_player_position(data, i * 64, j * 64);
				return ;
			}
			j++;
		}
		i++;
	}
}
