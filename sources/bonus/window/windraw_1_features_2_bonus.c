/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windraw_1_features_2_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 14:33:10 by linux-babas       #+#    #+#             */
/*   Updated: 2026/05/01 11:18:06 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw_tile(t_mlx_data *data, int x, int y)
{
	int		sx;
	int		sy;
	char	c;

	sx = x * TILE - data->cam_x + TILE;
	sy = y * TILE - data->cam_y + TILE;
	c = data->game->map[y][x];
	if (c == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->object.wall, sx, sy);
	else if (c == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->object.floor, sx, sy);
	else if (c == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->object.collectible, sx, sy);
}

void	draw_monsters(t_mlx_data *data)
{
	int	i;

	i = 0;
	while (i < data->game->nb_monster)
	{
		what_monster_image(data, data->game->monster[i].x,
			data->game->monster[i].y, data->game->monster[i].sleep);
		i++;
	}
}

void	draw_hero(t_mlx_data *data)
{
	int	x;
	int	y;

	if (!data || !data->game)
		return ;
	x = data->hero.hero_posx;
	y = data->hero.hero_posy;
	what_hero_image(data, x, y);
}

void	draw_world(t_mlx_data *data)
{
	int	x;
	int	y;

	y = data->view_y0;
	while (y < data->view_y1)
	{
		x = data->view_x0;
		while (x < data->view_x1)
		{
			draw_tile(data, x, y);
			x++;
		}
		y++;
	}
}

void	draw_exit(t_mlx_data *data)
{
	int	x;
	int	y;
	int	sx;
	int	sy;

	x = data->game->exit_posx;
	y = data->game->exit_posy;
	sx = x * TILE - data->cam_x + TILE;
	sy = y * TILE - data->cam_y + TILE;
	if (data->game->map[y][x] != 'E' && data->game->map[y][x] != 'P')
		data->game->map[y][x] = 'E';
	if (data->game->nb_collectible == 0 && data->game->map[y][x] == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->object.exit_open, sx, sy);
	else if (data->game->map[y][x] == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->object.exit_close, sx, sy);
}
