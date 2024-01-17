/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narigi-e <narigi-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:05:44 by narigi-e          #+#    #+#             */
/*   Updated: 2023/10/11 18:42:48 by narigi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <string.h>
# include <errno.h>
# include <stdbool.h>
# include <errno.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include "get_next_line.h"

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		x;
	int		y;
	char	**array;
	int		rows;
	int		columns;
	int		player_row;
	int		player_col;
	int		collect_count;
	int		players;
	int		exits;
	int		**visited;
	int		collected;
	char 	**copy;
}				t_data;

typedef struct {
    int x;
    int y;
} 	t_position;

# define COLLECT	"/workspaces/so_long/xpm/collect.xpm"
# define EXIT		"/workspaces/so_long/xpm/exit.xpm"
# define PLAYER		"/workspaces/so_long/xpm/player.xpm"
# define WALL		"/workspaces/so_long/xpm/wall.xpm"
# define PATH		"/workspaces/so_long/xpm/path.xpm"

enum
{
	ON_KEYDOWN		= 2,
	ON_KEYUP		= 3,
	ON_MOUSEDOWN	= 4,
	ON_MOUSEUP		= 5,
	ON_MOUSEMOVE	= 6,
	ON_EXPOSE		= 12,
	ON_DESTROY		= 17
};

// checkings.c
int		does_map_exist(char *argv);
int		is_argument_valid(char *argv);
int		is_map_valid(t_data *data);
int		is_collectible_reachable(t_data *data);

// cleanup.c
int		cleanup(t_data *data);
void	free_array(t_data *data);
void	map_errors_cleaning(t_data *data);
int		is_collectible_reachable(t_data *data);

// errors.c
void	map_invalid(t_data *data);

// ft_itoa.c
char	*ft_itoa(int n);
void	copying_original_map(t_data *data);
void	print_moves(t_data *data, int moves);

// move_player.c
bool	is_valid_move(t_data *data, int row, int col);
int		handle_player_movement(t_data *data, int key);
void	saving_player_position(t_data *data, int row, int col);
int		handle_key_press(int key, t_data *data);
void	end_game(t_data *data);

// main.c
void	put_xpm_to_print(t_data *data);
char	*character_checking(t_data *data, int row, int col);
void	image_process(t_data *data, char *filename, int row, int col);
void	game_start(t_data *data);

// map_checking.c
int		are_borders_all_wall(t_data *data);
int		are_all_characters_valid(t_data *data);
int		is_number_of_characters_valid(t_data *data);
int		do_lines_have_same_length(t_data *data);

// read_map.c
void	read_file(t_data *data, char *argv);
int		get_height(char *argv);
int		get_width(t_data *data, char *argv);
void	fill_array(char *dest, char *src, t_data *data);
void	find_player_position(t_data *data);

// registering_escape.c
int		close_window(t_data *data);

// utils.c
char	*ft_strdupp(char *s1);
int		ft_strlennn(char *str);
int		ft_strncmpp(char *s1, char *s2, int n);
void	ft_strcatt(char *dest, char *src);
void	allocating_visited(t_data *data);

// valid_path.c
int		can_reach_exit(t_data *data, int x, int y);
void    zero_all_elements(t_data *data);
int		can_reach_element(t_data *data, int x, int y, char c);
int		can_collect_all_collectibles(t_data *data);

#endif
