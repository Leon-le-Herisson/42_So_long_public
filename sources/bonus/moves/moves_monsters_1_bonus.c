/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_monsters_1_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 11:24:01 by linux-babas       #+#    #+#             */
/*   Updated: 2026/05/05 12:07:37 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	bfs_index(t_mlx_data *data, int x, int y)
{
	return (y * data->game->width + x);
}

int	monster_on_tile(t_mlx_data *data, int x, int y, int self)
{
	int	i;

	i = 0;
	while (i < data->game->nb_monster)
	{
		if (i != self && data->game->monster[i].x == x
			&& data->game->monster[i].y == y)
			return (1);
		i++;
	}
	return (0);
}

int	monster_tile_blocked(t_mlx_data *data, int x, int y, int self)
{
	char	c;

	if (x < 0 || y < 0)
		return (1);
	if (x >= data->game->width || y >= data->game->height)
		return (1);
	c = data->game->map[y][x];
	if (c == '1' || c == 'E' || c == 'C')
		return (1);
	if (x == data->game->exit_posx && y == data->game->exit_posy)
		return (1);
	if (self >= 0 && monster_on_tile(data, x, y, self))
		return (1);
	return (0);
}

static void	fill_dist(t_bfs *bfs)
{
	int	i;

	i = 0;
	while (i < bfs->size)
	{
		bfs->dist[i] = -1;
		i++;
	}
}

int	init_bfs(t_mlx_data *data, t_bfs *bfs)
{
	bfs->size = data->game->width * data->game->height;
	bfs->dist = malloc(sizeof(int) * bfs->size);
	if (!bfs->dist)
		return (0);
	bfs->queue = malloc(sizeof(t_step) * bfs->size);
	if (!bfs->queue)
	{
		free(bfs->dist);
		bfs->dist = NULL;
		return (0);
	}
	bfs->head = 0;
	bfs->tail = 0;
	bfs->next_dist = 0;
	fill_dist(bfs);
	return (1);
}
