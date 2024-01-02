/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narigi-e <narigi-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:58:36 by narigi-e          #+#    #+#             */
/*   Updated: 2023/10/06 12:58:36 by narigi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	g_moves = 1;

bool	is_valid_move(t_data *data, int row, int col)
{
	static int	moves = 0;
	char		*moves_itoa;

	moves_itoa = NULL;
	if (row >= 0 && row < data->rows * 64
		&& col >= 0 && col < data->columns * 64)
	{
		if (data->array[row / 64][col / 64] == '1')
			return (false);
		else if (data->array[row / 64][col / 64] == 'E' && data->collect_count)
			return (false);
		else if (data->array[row / 64][col / 64] == 'E' && !data->collect_count)
			end_game(data);
		moves++;
		write (1, "number of movements: ", 21);
		moves_itoa = ft_itoa(moves);
		write (1, moves_itoa, ft_strlennn(moves_itoa));
		write (1, "\n", 1);
		free(moves_itoa);
		return (true);
	}
	else
		return (false);
}

int	handle_player_movement(t_data *data, int key)
{
	int	next_row;
	int	next_col;

	next_row = data->player_row;
	next_col = data->player_col;
	if (key == 13)
		next_row -= 64;
	else if (key == 1)
		next_row += 64;
	else if (key == 0)
		next_col -= 64;
	else if (key == 2)
		next_col += 64;
	if (is_valid_move(data, next_row, next_col))
	{
		if (data->array[next_row / 64][next_col / 64] == 'C')
			data->collect_count--;
		data->array[data->player_row / 64][data->player_col / 64] = '0';
		data->array[next_row / 64][next_col / 64] = 'P';
		data->player_row = next_row;
		data->player_col = next_col;
		put_xpm_to_print(data);
		print_moves(data, g_moves++);
	}
	return (0);
}

void	saving_player_position(t_data *data, int row, int col)
{
	data->player_row = row;
	data->player_col = col;
}

int	handle_key_press(int key, t_data *data)
{
	if (key == 53)
		close_window(data);
	else if (key == 13 || key == 0 || key == 1 || key == 2)
		handle_player_movement(data, key);
	return (0);
}

void	end_game(t_data *data)
{
	cleanup(data);
	exit(0);
}
