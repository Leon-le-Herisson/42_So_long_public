/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:50:21 by bamagere          #+#    #+#             */
/*   Updated: 2026/05/01 13:08:26 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	reset_counters(t_game *game)
{
	game->nb_exit = 0;
	game->nb_collectible = 0;
	game->nb_hero = 0;
}

void	get_dimensions(t_game *game)
{
	int	i;

	i = 0;
	game->width = ft_strlen(game->map[0]);
	while (game->map[i])
	{
		if ((int)ft_strlen(game->map[i]) != game->width)
		{
			ft_puts("Error\nThe Map isn't well dimensioned");
			free_maps(game);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	game->height = i;
	if (game->width > 100 || game->height > 100)
	{
		ft_puts("Error\nThe Map is too big");
		free_maps(game);
		exit(EXIT_FAILURE);
	}
}

void	wall_x(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->width)
	{
		if (game->map[0][i] != '1' || game->map[game->height - 1][i] != '1')
		{
			ft_puts("Error\nThe surrondings aren't only walls");
			free_maps(game);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	wall_y(t_game *game)
{
	int	i;

	i = 1;
	while (i < game->height)
	{
		if (game->map[i][0] != '1' || game->map[i][game->width - 1] != '1')
		{
			ft_puts("Error\nThe surrondings aren't only walls.");
			free_maps(game);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	map_completable(t_game *game)
{
	int	p_counters;
	int	x;
	int	y;

	p_counters = 0;
	while (call_flood_fill(&p_counters, game) == true)
		flood_fill(game);
	y = 1;
	while (y < game->height - 1)
	{
		x = 1;
		while (x < game->width - 1)
		{
			if (game->copy[y][x] == 'E' || game->copy[y][x] == 'C')
			{
				ft_puts("Error\nThe map can't be finished without cheatcode.");
				free_maps(game);
				exit(EXIT_FAILURE);
			}
			x++;
		}
		y++;
	}
}
