/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_3_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 15:02:14 by linux-babas       #+#    #+#             */
/*   Updated: 2026/05/04 17:08:53 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	clamp_window_size(int map_size, int screen_size, int max_size)
{
	if (screen_size > max_size)
		screen_size = max_size;
	screen_size = screen_size - (2 * TILE);
	if (screen_size < (3 * TILE))
		return (3 * TILE);
	screen_size = (screen_size / TILE) * TILE;
	if (map_size < screen_size)
		return (map_size);
	return (screen_size);
}

void	set_window_size(t_mlx_data *data)
{
	int	screen_w;
	int	screen_h;
	int	map_w;
	int	map_h;

	screen_w = 0;
	screen_h = 0;
	mlx_get_screen_size(data->mlx_ptr, &screen_w, &screen_h);
	map_w = data->game->width * TILE + (2 * TILE);
	map_h = data->game->height * TILE + (2 * TILE);
	data->win_w = clamp_window_size(map_w, screen_w, MAX_WIN_W);
	data->win_h = clamp_window_size(map_h, screen_h, MAX_WIN_H);
}

void	free_before_mlx_exit(t_mlx_data *data)
{
	if (!data || !data->game)
		exit(EXIT_FAILURE);
	if (data->game->monster)
	{
		free(data->game->monster);
		data->game->monster = NULL;
	}
	free_maps(data->game);
	exit(EXIT_FAILURE);
}
