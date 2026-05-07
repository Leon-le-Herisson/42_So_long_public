/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_monsters_2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 11:24:01 by linux-babas       #+#    #+#             */
/*   Updated: 2026/04/24 11:56:04 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	clear_bfs(t_bfs *bfs)
{
	if (bfs->dist)
		free(bfs->dist);
	if (bfs->queue)
		free(bfs->queue);
	bfs->dist = NULL;
	bfs->queue = NULL;
}

static void	try_bfs_cell(t_mlx_data *data, t_bfs *bfs, int x, int y)
{
	int	index;

	if (monster_tile_blocked(data, x, y, -1))
		return ;
	index = bfs_index(data, x, y);
	if (bfs->dist[index] != -1)
		return ;
	if (bfs->tail >= bfs->size)
		return ;
	bfs->dist[index] = bfs->next_dist;
	bfs->queue[bfs->tail].x = x;
	bfs->queue[bfs->tail].y = y;
	bfs->tail++;
}

void	fill_bfs(t_mlx_data *data, t_bfs *bfs)
{
	t_step	cur;
	int		index;

	index = bfs_index(data, data->hero.hero_posx, data->hero.hero_posy);
	bfs->dist[index] = 0;
	bfs->queue[bfs->tail].x = data->hero.hero_posx;
	bfs->queue[bfs->tail].y = data->hero.hero_posy;
	bfs->tail++;
	while (bfs->head < bfs->tail)
	{
		cur = bfs->queue[bfs->head];
		bfs->head++;
		index = bfs_index(data, cur.x, cur.y);
		bfs->next_dist = bfs->dist[index] + 1;
		try_bfs_cell(data, bfs, cur.x + 1, cur.y);
		try_bfs_cell(data, bfs, cur.x - 1, cur.y);
		try_bfs_cell(data, bfs, cur.x, cur.y + 1);
		try_bfs_cell(data, bfs, cur.x, cur.y - 1);
	}
}

static void	try_best(t_mlx_data *data, t_bfs *bfs, t_best *best, t_step c)
{
	int	index;

	if (monster_tile_blocked(data, c.x, c.y, -1))
		return ;
	index = bfs_index(data, c.x, c.y);
	if (bfs->dist[index] == -1)
		return ;
	if (best->dist != -1 && bfs->dist[index] >= best->dist)
		return ;
	best->dist = bfs->dist[index];
	best->dx = c.x - best->ox;
	best->dy = c.y - best->oy;
}

t_step	get_bfs_step(t_mlx_data *data, t_bfs *bfs, int x, int y)
{
	t_best	best;
	t_step	c;
	t_step	step;

	best.ox = x;
	best.oy = y;
	best.dx = 0;
	best.dy = 0;
	best.dist = -1;
	c.x = x + 1;
	c.y = y;
	try_best(data, bfs, &best, c);
	c.x = x - 1;
	try_best(data, bfs, &best, c);
	c.x = x;
	c.y = y + 1;
	try_best(data, bfs, &best, c);
	c.y = y - 1;
	try_best(data, bfs, &best, c);
	step.x = best.dx;
	step.y = best.dy;
	return (step);
}
