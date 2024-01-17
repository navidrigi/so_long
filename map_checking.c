/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narigi-e <narigi-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:49:19 by narigi-e          #+#    #+#             */
/*   Updated: 2023/10/06 12:58:28 by narigi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	are_borders_all_wall(t_data *data)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (data->array[i])
		i++;
	while (data->array[0][j] && data->array[i - 1][j])
	{
		if (data->array[0][j] != '1' || data->array[i - 1][j] != '1')
			return (0);
		j++;
	}
	i = 1;
	len = ft_strlennn(data->array[i]);
	while (data->array[i])
	{
		if (data->array[i][0] != '1' || data->array[i][len - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	are_all_characters_valid(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->array[i])
	{
		j = 0;
		while (data->array[i][j])
		{
			if (data->array[i][j] != '1' && data->array[i][j] != '0' &&
				data->array[i][j] != 'P' && data->array[i][j] != 'E' &&
				data->array[i][j] != 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_number_of_characters_valid(t_data *data)
{
	if (data->collect_count < 1 || data->players != 1 || data->exits != 1)
		return (0);
	return (1);
}

int	do_lines_have_same_length(t_data *data)
{
	int	i;
	int	len;

	len = ft_strlennn(data->array[0]);
	i = 1;
	while (data->array[i])
	{
		if (ft_strlennn(data->array[i]) != len)
			return (0);
		i++;
	}
	return (1);
}
