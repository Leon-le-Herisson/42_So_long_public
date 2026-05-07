/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils_two.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:30:41 by bamagere          #+#    #+#             */
/*   Updated: 2026/04/21 12:42:37 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_game *game)
{
	int	x;
	int	y;

	y = 1;
	while (y < game->height - 1)
	{
		x = 1;
		while (x < game->width - 1)
		{
			if (game->copy[y][x] == 'P')
			{
				if (game->copy[y][x + 1] != '1')
					game->copy[y][x + 1] = 'P';
				if (game->copy[y][x - 1] != '1')
					game->copy[y][x - 1] = 'P';
				if (game->copy[y - 1][x] != '1')
					game->copy[y - 1][x] = 'P';
				if (game->copy[y + 1][x] != '1')
					game->copy[y + 1][x] = 'P';
			}
			x++;
		}
		y++;
	}
}

bool	call_flood_fill(int *p, t_game *game)
{
	int	check;
	int	x;
	int	y;

	check = 0;
	y = 1;
	while (y < game->height - 1)
	{
		x = 1;
		while (x < game->width - 1)
		{
			if (game->copy[y][x] == 'P')
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

void	find_the_door(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'P')
			{
				game->hero_posx = x;
				game->hero_posy = y;
			}
			else if (game->map[y][x] == 'E')
			{
				game->exit_posx = x;
				game->exit_posy = y;
			}
			x++;
		}
		y++;
	}
}
