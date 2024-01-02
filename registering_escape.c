/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   registering_escape.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narigi-e <narigi-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:04:24 by narigi-e          #+#    #+#             */
/*   Updated: 2023/10/06 13:04:29 by narigi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->img);
	exit (0);
	return (0);
}
