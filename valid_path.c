/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narigi-e <narigi-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:45:23 by narigi-e          #+#    #+#             */
/*   Updated: 2023/10/11 16:21:59 by narigi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	g_dx[] = {-64, 64, 0, 0};
int	g_dy[] = {0, 0, -64, 64};

int	can_reach_exit(t_data *data, int x, int y)
{
	int	i;
	int	new_x;
	int	new_y;

	i = 0;
	if (x < 0 || x >= data->columns * 64 || y < 0
		|| y >= data->rows * 64 || data->visited[y / 64][x / 64] == 1
		|| data->array[y / 64][x / 64] == '1')
		return (0);
	if (data->array[y / 64][x / 64] == 'E')
		return (1);
	data->visited[y / 64][x / 64] = 1;
	while (i < 4)
	{
		new_x = x + g_dx[i];
		new_y = y + g_dy[i];
		if (can_reach_exit(data, new_x, new_y))
			return (1);
		i++;
	}
	return (0);
}

void	zero_all_elements(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j < data->columns)
		{
			data->visited[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	valid_path(t_data *data, int x, int y, int **visited)
{
	if (x < 0 || x >= data->columns * 64 || y < 0
		|| y >= data->rows * 64 || visited[y / 64][x / 64] == 1
		|| data->array[y / 64][x / 64] == '1')
		return (1);
	return (0);
}

int	can_reach_element(t_data *data, int x, int y, char c)
{
	int	i;
	int	new_x;
	int	new_y;

	i = 0;
	if (valid_path(data, x, y, data->visited))
		return (0);
	if (data->copy[y / 64][x / 64] == 'C'
		&& data->visited[y / 64][x / 64] == 0)
	{
		data->player_col = x;
		data->player_row = y;
		return (1);
	}
	data->visited[y / 64][x / 64] = 1;
	while (i < 4)
	{
		new_x = x + g_dx[i];
		new_y = y + g_dy[i];
		if (can_reach_element(data, new_x, new_y, c))
			return (1);
		i++;
	}
	return (0);
}

int	can_collect_all_collectibles(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->collect_count)
	{
		if (can_reach_element(data, data->player_col, data->player_row, 'C'))
			data->collected++;
		zero_all_elements(data);
		data->copy[data->player_row / 64][data->player_col / 64] = 0;
		i++;
	}
	if (data->collected == data->collect_count)
	{
		if (can_reach_exit(data, data->player_col, data->player_row))
			return (1);
	}
	return (0);
}
