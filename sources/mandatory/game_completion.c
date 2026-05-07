/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_completion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 12:41:48 by linux-babas       #+#    #+#             */
/*   Updated: 2026/05/01 12:26:23 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	game_completion(t_game *game)
{
	if (game->nb_collectible == 0
		&& game->hero_posx == game->exit_posx
		&& game->hero_posy == game->exit_posy)
		return (true);
	return (false);
}

void	game_won(t_game *game, t_mlx_data *data, char answer)
{
	ft_puts("");
	if (answer == 'y')
	{
		ft_puts_color("\033[1;32m", "You won. YAY !");
		ft_puts_rainbow("BOB THE FISHERMAN CAUGHT A MAGICARPE");
	}
	if (answer == 'n')
	{
		ft_puts_color("\033[1;31m", "Oh no. You exited the game... ");
		ft_puts_rainbow("You'll do better next time :)");
	}
	ft_puts("");
	ft_printf("\033[0;32mFINAL SCORE : \033[1;32m%d\033[0m\n", game->moves);
	ft_puts("");
	free_maps(game);
	destroy_images(data);
	exit(EXIT_SUCCESS);
}
