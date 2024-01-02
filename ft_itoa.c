/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narigi-e <narigi-e@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:06:11 by narigi-e          #+#    #+#             */
/*   Updated: 2023/06/06 12:06:11 by narigi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	num_lenn(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	len;
	long	nl;
	char	*result;

	len = num_lenn(n);
	nl = n;
	if (n < 0)
		nl *= -1;
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[len] = 0;
	if (nl == 0)
		result[0] = '0';
	else
	{
		while (len--, nl != 0)
		{
			result[len] = (nl % 10) + '0';
			nl = (nl - (nl % 10)) / 10;
		}
		if (n < 0)
			result[len] = '-';
	}
	return (result);
}

void	copying_original_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->copy = (char **) malloc(data->rows * (sizeof(char *) + 1));
	while (i < data->rows)
	{
		j = 0;
		data->copy[i] = (char *) malloc(data->columns * (sizeof(char) + 1));
		while (j < data->columns)
		{
			data->copy[i][j] = data->array[i][j];
			j++;
		}
		data->copy[i][j] = '\0';
		i++;
	}
	data->copy[i] = NULL;
}

void	print_moves(t_data *data, int moves)
{
	char	*moves_str;

	moves_str = ft_itoa(moves);
	mlx_string_put(data->mlx, data->win, 10, 10, 0xFFFFFF, "Moves: ");
	mlx_string_put(data->mlx, data->win, 80, 10, 0xFFFFFF, moves_str);
	free(moves_str);
}
