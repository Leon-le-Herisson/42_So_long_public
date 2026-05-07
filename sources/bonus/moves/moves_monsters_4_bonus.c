/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_monsters_4_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:12:10 by linux-babas       #+#    #+#             */
/*   Updated: 2026/05/07 15:47:04 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static t_step	get_step_from_dir(int dir)
{
	t_step	step;

	step.x = 0;
	step.y = 0;
	if (dir == 0)
		step.x = 1;
	else if (dir == 1)
		step.x = -1;
	else if (dir == 2)
		step.y = 1;
	else
		step.y = -1;
	return (step);
}

static t_step	get_free_patrol_step(t_mlx_data *data, int i, int dir)
{
	t_step	step;
	int		try;
	int		x;
	int		y;

	try = 0;
	while (try < 4)
	{
		step = get_step_from_dir((dir + try) % 4);
		x = data->game->monster[i].x + step.x;
		y = data->game->monster[i].y + step.y;
		if (!monster_tile_blocked(data, x, y, i))
			return (step);
		try++;
	}
	step.x = 0;
	step.y = 0;
	return (step);
}

t_step	get_patrol_step(t_mlx_data *data, int i)
{
	int		dir;
	t_step	step;

	dir = (data->game->moves + i
			+ data->hero.hero_posx - data->hero.hero_posy) % 4;
	if (dir < 0)
		dir = dir + 4;
	step = get_free_patrol_step(data, i, dir);
	return (step);
}
