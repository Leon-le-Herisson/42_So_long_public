/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 13:47:27 by linux-babas       #+#    #+#             */
/*   Updated: 2026/05/01 12:18:57 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_exit(t_game *game, t_mlx_data *data)
{
	int	x;
	int	y;

	x = game->exit_posx;
	y = game->exit_posy;
	if (game->nb_collectible == 0)
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->exit_open, x * TILE, y * TILE);
	else
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->exit_close, x * TILE, y * TILE);
}

void	draw_line(t_game *game, t_mlx_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(data->mlx_ptr,
					data->win_ptr, data->wall, x * TILE, y * TILE);
			else if (game->map[y][x] == '0' || game->map[y][x] == 'P')
				mlx_put_image_to_window(data->mlx_ptr,
					data->win_ptr, data->floor, x * TILE, y * TILE);
			else if (game->map[y][x] == 'C')
				mlx_put_image_to_window(data->mlx_ptr,
					data->win_ptr, data->collectible, x * TILE, y * TILE);
			x++;
		}
		y++;
	}
	draw_exit(game, data);
	what_hero_image(game, data, game->hero_posx, game->hero_posy);
}
