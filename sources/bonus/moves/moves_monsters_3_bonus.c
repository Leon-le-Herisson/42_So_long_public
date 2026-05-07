/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_monsters_3_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 11:24:01 by linux-babas       #+#    #+#             */
/*   Updated: 2026/05/04 12:14:20 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static t_step	get_chase_step(t_mlx_data *data, int i)
{
	t_bfs	bfs;
	t_step	step;
	int		x;
	int		y;

	step.x = 0;
	step.y = 0;
	if (!init_bfs(data, &bfs))
		return (step);
	fill_bfs(data, &bfs);
	x = data->game->monster[i].x;
	y = data->game->monster[i].y;
	step = get_bfs_step(data, &bfs, x, y);
	clear_bfs(&bfs);
	return (step);
}

static void	apply_monster_step(t_mlx_data *data, int i, t_step step)
{
	int	x;
	int	y;

	if (step.x == 0 && step.y == 0)
		return ;
	x = data->game->monster[i].x + step.x;
	y = data->game->monster[i].y + step.y;
	if (monster_tile_blocked(data, x, y, i))
		return ;
	data->game->monster[i].x = x;
	data->game->monster[i].y = y;
}

static void	move_one_monster(t_mlx_data *data, int i)
{
	t_step	step;

	if (data->game->monster[i].sleep > 0)
		return ;
	if (data->game->nb_collectible == 0)
		step = get_chase_step(data, i);
	else
		step = get_patrol_step(data, i);
	apply_monster_step(data, i, step);
}

void	move_monsters(t_mlx_data *data)
{
	int	i;

	if (!data || !data->game)
		return ;
	if (!data->game->monster || data->game->nb_monster <= 0)
		return ;
	i = 0;
	while (i < data->game->nb_monster)
	{
		move_one_monster(data, i);
		i++;
	}
}
