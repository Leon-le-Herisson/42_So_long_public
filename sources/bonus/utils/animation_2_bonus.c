/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 14:21:28 by linux-babas       #+#    #+#             */
/*   Updated: 2026/04/24 11:12:38 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	update_hero_anim(t_mlx_data *data, long now)
{
	if (now - data->last_hero_time < HERO_DELAY)
		return (0);
	data->last_hero_time = now;
	data->hero_frame++;
	if (data->hero_frame >= H_FRAME)
		data->hero_frame = 0;
	return (1);
}

int	update_monster_anim(t_mlx_data *data, long now)
{
	if (now - data->last_monster_time < MONSTER_DELAY)
		return (0);
	data->last_monster_time = now;
	data->monster_frame++;
	if (data->monster_frame >= M_FRAME)
		data->monster_frame = 0;
	return (1);
}

void	start_pending_power(t_mlx_data *data)
{
	int	x;
	int	y;

	if (!data->game->power.pending)
		return ;
	x = data->game->power.x;
	y = data->game->power.y;
	data->game->power.pending = 0;
	if (is_wall_tile(data, x, y))
		return ;
	if (is_monster_tile(data, x, y))
	{
		sleep_beauty(data, x, y);
		return ;
	}
	data->last_power_time = get_time_ms();
	data->game->power.active = 1;
}

int	update_cast_anim(t_mlx_data *data, long now)
{
	if (!data->hero_casting)
		return (0);
	if (now - data->last_cast_time < CAST_DELAY)
		return (0);
	data->last_cast_time = now;
	data->hero_cast_frame++;
	if (data->hero_cast_frame >= POWER_FRAME)
	{
		data->hero_cast_frame = 0;
		data->hero_casting = 0;
		start_pending_power(data);
	}
	return (1);
}

int	update_power_anim(t_mlx_data *data, long now)
{
	if (!data->game->power.active)
		return (0);
	if (now - data->last_power_time < POWER_DELAY)
		return (0);
	data->last_power_time = now;
	idle_animation_power(data);
	return (1);
}
