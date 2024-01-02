/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narigi-e <narigi-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:48:13 by narigi-e          #+#    #+#             */
/*   Updated: 2023/10/10 15:18:55 by narigi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_invalid(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->rows)
	{
		free(data->visited[i]);
		i++;
	}
	free(data->visited);
	if (data->array)
		free_array(data);
	printf("Error\nInvalid map\n");
	exit(1);
}
