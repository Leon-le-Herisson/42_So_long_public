/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 21:25:44 by bamagere          #+#    #+#             */
/*   Updated: 2026/04/21 12:43:19 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game)
{
	if (game->map[game->hero_posy - 1][game->hero_posx] != '1')
	{
		if (game->map[game->hero_posy - 1][game->hero_posx] == 'C')
			game->nb_collectible--;
		game->map[game->hero_posy - 1][game->hero_posx] = 'P';
		game->map[game->hero_posy][game->hero_posx] = '0';
		game->hero_posy--;
		game->moves++;
		ft_printf("\033[0;33mScore : \033[0m%d\n", game->moves);
	}
	game->flag = 2;
}

void	move_down(t_game *game)
{
	if (game->map[game->hero_posy + 1][game->hero_posx] != '1')
	{
		if (game->map[game->hero_posy + 1][game->hero_posx] == 'C')
			game->nb_collectible--;
		game->map[game->hero_posy + 1][game->hero_posx] = 'P';
		game->map[game->hero_posy][game->hero_posx] = '0';
		game->hero_posy++;
		game->moves++;
		ft_printf("\033[0;33mScore : \033[0m%d\n", game->moves);
	}
	game->flag = 1;
}

void	move_left(t_game *game)
{
	if (game->map[game->hero_posy][game->hero_posx - 1] != '1')
	{
		if (game->map[game->hero_posy][game->hero_posx - 1] == 'C')
			game->nb_collectible--;
		game->map[game->hero_posy][game->hero_posx - 1] = 'P';
		game->map[game->hero_posy][game->hero_posx] = '0';
		game->hero_posx--;
		game->moves++;
		ft_printf("\033[0;33mScore : \033[0m%d\n", game->moves);
	}
	game->flag = 0;
}

void	move_right(t_game *game)
{
	if (game->map[game->hero_posy][game->hero_posx + 1] != '1')
	{
		if (game->map[game->hero_posy][game->hero_posx + 1] == 'C')
			game->nb_collectible--;
		game->map[game->hero_posy][game->hero_posx + 1] = 'P';
		game->map[game->hero_posy][game->hero_posx] = '0';
		game->hero_posx++;
		game->moves++;
		ft_printf("\033[0;33mScore : \033[0m%d\n", game->moves);
	}
	game->flag = 1;
}

void	what_hero_image(t_game *game, t_mlx_data *data, int x, int y)
{
	if (game->map[y][x] == 'P' && (game->flag == 3 || game->flag == 0))
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->hero_look_right, x * TILE, y * TILE);
	else if (game->map[y][x] == 'P' && game->flag == 2)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->hero_look_up, x * TILE, y * TILE);
	else if (game->map[y][x] == 'P' && game->flag == 1)
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->hero_look_left, x * TILE, y * TILE);
}
