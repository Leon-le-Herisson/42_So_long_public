/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamagere <bamagere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:50:37 by bamagere          #+#    #+#             */
/*   Updated: 2026/01/18 19:07:37 by bamagere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	flood_fill(t_mlx_data *data)
{
	int	x;
	int	y;

	y = 1;
	while (y < data->game->height - 1)
	{
		x = 1;
		while (x < data->game->width - 1)
		{
			if (data->game->copy[y][x] == 'P')
			{
				if (data->game->copy[y][x + 1] != '1')
					data->game->copy[y][x + 1] = 'P';
				if (data->game->copy[y][x - 1] != '1')
					data->game->copy[y][x - 1] = 'P';
				if (data->game->copy[y - 1][x] != '1')
					data->game->copy[y - 1][x] = 'P';
				if (data->game->copy[y + 1][x] != '1')
					data->game->copy[y + 1][x] = 'P';
			}
			x++;
		}
		y++;
	}
}

bool	call_flood_fill(int *p, t_mlx_data *data)
{
	int	check;
	int	x;
	int	y;

	check = 0;
	y = 1;
	while (y < data->game->height - 1)
	{
		x = 1;
		while (x < data->game->width - 1)
		{
			if (data->game->copy[y][x] == 'P')
				check++;
			x++;
		}
		y++;
	}
	if (check == *p)
		return (false);
	*p = check;
	return (true);
}

void	find_the_door(t_mlx_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->game->map[y])
	{
		x = 0;
		while (x < data->game->width)
		{
			if (data->game->map[y][x] == 'P')
			{
				data->hero.hero_posx = x;
				data->hero.hero_posy = y;
			}
			else if (data->game->map[y][x] == 'E')
			{
				data->game->exit_posx = x;
				data->game->exit_posy = y;
			}
			x++;
		}
		y++;
	}
}

void	find_the_monster(t_mlx_data *data)
{
	int	x;
	int	y;
	int	counter;

	if (!data->game->monster || data->game->nb_monster <= 0)
		return ;
	y = 0;
	counter = 0;
	while (data->game->map[y] && counter < data->game->nb_monster)
	{
		x = 0;
		while (x < data->game->width && counter < data->game->nb_monster)
		{
			if (data->game->map[y][x] == 'M')
			{
				data->game->monster[counter].x = x;
				data->game->monster[counter].y = y;
				data->game->map[y][x] = '0';
				counter++;
			}
			x++;
		}
		y++;
	}
}
