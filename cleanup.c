/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narigi-e <narigi-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:53:35 by narigi-e          #+#    #+#             */
/*   Updated: 2023/10/11 15:57:16 by narigi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	cleanup(t_data *data)
{
	int	i;

	i = 0;
	mlx_destroy_window(data->mlx, data->win);
	while (i < data->rows)
	{
		free(data->visited[i]);
		i++;
	}
	free(data->visited);
	free_array(data);
	free(data->mlx);
	exit(0);
	return (0);
}

void	free_array(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->rows)
	{
		free(data->array[i]);
		i++;
	}
	free(data->array);
	data->array = NULL;
	i = 0;
	while (i < data->rows)
	{
		free(data->copy[i]);
		i++;
	}
	free(data->copy);
	data->copy = NULL;
}

void	map_errors_cleaning(t_data *data)
{
	free_array(data);
	free(data->mlx);
	exit(0);
}
