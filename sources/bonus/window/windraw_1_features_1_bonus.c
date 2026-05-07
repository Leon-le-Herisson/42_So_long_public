/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windraw_1_features_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:04:30 by bamagere          #+#    #+#             */
/*   Updated: 2026/04/23 14:33:34 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	*get_power_img(t_mlx_data *data, int f)
{
	if (data->game->power.dir_y == -1)
		return (data->hero.power_u[f]);
	if (data->game->power.dir_y == 1)
		return (data->hero.power_d[f]);
	if (data->game->power.dir_x == -1)
		return (data->hero.power_l[f]);
	return (data->hero.power_r[f]);
}

static void	put_power_tile(t_mlx_data *data, int x, int y, int f)
{
	int		sx;
	int		sy;
	void	*img;

	if (f < 0)
		f = 0;
	if (f > 6)
		f = 6;
	img = get_power_img(data, f);
	sx = x * TILE - data->cam_x + TILE;
	sy = y * TILE - data->cam_y + TILE;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img, sx, sy);
}

void	draw_power(t_mlx_data *data)
{
	if (!data || !data->game)
		return ;
	if (!data->game->power.active)
		return ;
	put_power_tile(data, data->game->power.x,
		data->game->power.y, data->game->power.frame);
	if (data->game->power.next_active)
		put_power_tile(data, data->game->power.next_x,
			data->game->power.next_y, data->game->power.next_frame);
}

void	draw_all(t_mlx_data *data)
{
	update_camera(data);
	draw_world(data);
	draw_exit(data);
	draw_power(data);
	draw_monsters(data);
	draw_hero(data);
	draw_border(data);
	draw_hud(data);
}
