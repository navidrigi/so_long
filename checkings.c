/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkings.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narigi-e <narigi-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:50:42 by narigi-e          #+#    #+#             */
/*   Updated: 2023/10/11 16:20:44 by narigi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	does_map_exist(char *argv)
{
	int	fd;

	fd = open(argv, O_RDWR);
	if (fd == -1)
	{
		perror("open");
		return (0);
	}
	close(fd);
	return (1);
}

int	is_argument_valid(char *argv)
{
	int	argv_len;

	if (argv[1] == 0)
		return (0);
	argv_len = ft_strlennn(argv);
	if (argv[argv_len - 1] == 'r' && argv[argv_len - 2] == 'e'
		&& argv[argv_len - 3] == 'b' && argv[argv_len - 4] == '.')
		return (1);
	return (0);
}

int	is_map_valid(t_data *data)
{
	if (are_borders_all_wall(data) && is_number_of_characters_valid(data)
		&& are_all_characters_valid(data) && do_lines_have_same_length(data)
		&& is_collectible_reachable(data)
		&& can_collect_all_collectibles(data))
		return (1);
	return (0);
}

int	is_collectible_reachable(t_data *data)
{
	int	i;
	int	j;

	i = 1;
	while (i < data->rows)
	{
		j = 1;
		while (j < data->columns)
		{
			if (data->array[i][j] == 'C')
			{
				if (data->array[i - 1][j] == '1'
					&& data->array[i + 1][j] == '1'
					&& data->array[i][j - 1] == '1'
					&& data->array[i][j + 1] == '1')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
