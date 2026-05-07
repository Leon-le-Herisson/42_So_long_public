/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_power_3_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 14:52:25 by linux-babas       #+#    #+#             */
/*   Updated: 2026/04/24 11:04:47 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	prepare_next_tile(t_mlx_data *data)
{
	int	nx;
	int	ny;

	nx = data->game->power.x + data->game->power.dir_x;
	ny = data->game->power.y + data->game->power.dir_y;
	if (is_wall_tile(data, nx, ny))
	{
		data->game->power.stop = 1;
		return ;
	}
	if (is_monster_tile(data, nx, ny))
	{
		sleep_beauty(data, nx, ny);
		data->game->power.stop = 1;
		return ;
	}
	data->game->power.next_active = 1;
	data->game->power.next_x = nx;
	data->game->power.next_y = ny;
	data->game->power.next_frame = 0;
}

static void	promote_next_tile(t_mlx_data *data)
{
	if (!data->game->power.next_active)
	{
		data->game->power.active = 0;
		data->game->power.frame = 0;
		data->game->power.stop = 0;
		return ;
	}
	data->game->power.x = data->game->power.next_x;
	data->game->power.y = data->game->power.next_y;
	data->game->power.frame = 2;
	data->game->power.next_active = 0;
	data->game->power.next_frame = 0;
	data->game->power.stop = 0;
}

void	idle_animation_power(t_mlx_data *data)
{
	if (!data || !data->game || !data->game->power.active)
		return ;
	if (data->game->power.frame < POWER_FRAME - 1)
		data->game->power.frame++;
	if (data->game->power.frame == 5
		&& !data->game->power.next_active
		&& !data->game->power.stop)
		prepare_next_tile(data);
	if (data->game->power.next_active
		&& data->game->power.next_frame < POWER_FRAME - 1)
		data->game->power.next_frame++;
	if (data->game->power.frame >= POWER_FRAME - 1)
		promote_next_tile(data);
}
