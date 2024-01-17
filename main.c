/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narigi-e <narigi-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:54:27 by narigi-e          #+#    #+#             */
/*   Updated: 2023/10/11 18:44:02 by narigi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2)
	{
		read_file(&data, argv[1]);
		find_player_position(&data);
		allocating_visited(&data);
		zero_all_elements(&data);
		copying_original_map(&data);
		if (is_argument_valid(argv[1]) && does_map_exist(argv[1])
			&& is_map_valid(&data))
			game_start(&data);
		else
			map_invalid(&data);
		cleanup(&data);
	}
	else
	{
		write (2, "Error\nWrong number of Arguments\n", 32);
		exit(1);
	}
	return (0);
}

void	put_xpm_to_print(t_data *data)
{
	int		row;
	int		col;
	char	*filename;

	row = 0;
	col = 0;
	filename = NULL;
	while (row < data->rows * 64)
	{
		col = 0;
		while (col < data->columns * 64)
		{
			filename = character_checking(data, row, col);
			if (data->array[row / 64][col / 64] == 'P')
				saving_player_position(data, row, col);
			if (filename)
				image_process(data, filename, row, col);
			col += 64;
			free(filename);
		}
		row += 64;
	}
}

char	*character_checking(t_data *data, int row, int col)
{
	char	*file;

	file = NULL;
	if (data->array[row / 64][col / 64] == 'C')
		file = ft_strdupp("/workspaces/so_long/xpm/collect.xpm");
	else if (data->array[row / 64][col / 64] == 'E')
		file = ft_strdupp("/workspaces/so_long/xpm/exit.xpm");
	else if (data->array[row / 64][col / 64] == 'P')
		file = ft_strdupp("/workspaces/so_long/xpm/player.xpm");
	else if (data->array[row / 64][col / 64] == '1')
		file = ft_strdupp("/workspaces/so_long/xpm/wall.xpm");
	else if (data->array[row / 64][col / 64] == '0')
		file = ft_strdupp("/workspaces/so_long/xpm/path.xpm");
	return (file);
}

void	image_process(t_data *data, char *filename, int row, int col)
{
	data->img = mlx_xpm_file_to_image(data->mlx, filename,
			&(data->x), &(data->y));
	mlx_put_image_to_window(data->mlx, data->win,
		data->img, col, row);
}

void	game_start(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return ;
	data->win = mlx_new_window(data->mlx, data->columns * 64, data->rows * 64,
			"So_Long");
	if (!data->win)
	{
		free(data->mlx);
		return ;
	}
	put_xpm_to_print(data);
	mlx_hook(data->win, ON_KEYDOWN, 0, handle_key_press, data);
	mlx_hook(data->win, ON_DESTROY, 0, close_window, data);
	mlx_loop(data->mlx);
}
