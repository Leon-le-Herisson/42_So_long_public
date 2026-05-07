/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_power_1_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 10:40:11 by bamagere          #+#    #+#             */
/*   Updated: 2026/04/24 11:12:25 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	init_power_dir(t_mlx_data *data)
{
	if (data->hero.hero_dir_x == 0 && data->hero.hero_dir_y == 0)
	{
		data->hero.hero_dir_x = 1;
		data->hero.hero_dir_y = 0;
	}
	data->game->power.dir_x = data->hero.hero_dir_x;
	data->game->power.dir_y = data->hero.hero_dir_y;
}

static void	reset_power_state(t_mlx_data *data)
{
	data->game->power.active = 0;
	data->game->power.pending = 0;
	data->game->power.frame = 0;
	data->game->power.stop = 0;
	data->game->power.next_active = 0;
	data->game->power.next_x = 0;
	data->game->power.next_y = 0;
	data->game->power.next_frame = 0;
}

static void	init_power(t_mlx_data *data)
{
	init_power_dir(data);
	reset_power_state(data);
	data->game->power.x = data->hero.hero_posx + data->game->power.dir_x;
	data->game->power.y = data->hero.hero_posy + data->game->power.dir_y;
}

void	love_power(t_mlx_data *data)
{
	if (!data || !data->game)
		return ;
	if (data->hero_casting || data->game->power.active)
		return ;
	if (data->game->power.pending)
		return ;
	init_power(data);
	data->game->power.pending = 1;
	idle_anim_hero(data);
}
