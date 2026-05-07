/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_power_2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 14:09:17 by linux-babas       #+#    #+#             */
/*   Updated: 2026/04/23 14:49:55 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	decrement_monster_sleep(t_mlx_data *data)
{
	int	i;

	if (!data || !data->game)
		return ;
	if (!data->game->monster || data->game->nb_monster <= 0)
		return ;
	i = 0;
	while (i < data->game->nb_monster)
	{
		if (data->game->monster[i].sleep > 0)
			data->game->monster[i].sleep--;
		i++;
	}
}

void	sleep_beauty(t_mlx_data *data, int x, int y)
{
	int	i;

	if (!data || !data->game || !data->game->monster)
		return ;
	i = 0;
	while (i < data->game->nb_monster)
	{
		if (data->game->monster[i].x == x && data->game->monster[i].y == y)
		{
			data->game->monster[i].sleep = 5;
			return ;
		}
		i++;
	}
}

int	is_wall_tile(t_mlx_data *data, int x, int y)
{
	if (!data || !data->game)
		return (1);
	if (x < 0 || y < 0)
		return (1);
	if (x >= data->game->width || y >= data->game->height)
		return (1);
	if (data->game->map[y][x] == '1')
		return (1);
	return (0);
}

int	is_monster_tile(t_mlx_data *data, int x, int y)
{
	int	i;

	if (!data || !data->game)
		return (0);
	if (!data->game->monster || data->game->nb_monster <= 0)
		return (0);
	i = 0;
	while (i < data->game->nb_monster)
	{
		if (data->game->monster[i].x == x && data->game->monster[i].y == y)
			return (1);
		i++;
	}
	return (0);
}
