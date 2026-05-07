/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rules_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:53:07 by bamagere          #+#    #+#             */
/*   Updated: 2026/05/04 18:29:48 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

bool	monster_win(t_mlx_data *data)
{
	int	counter;

	if (!data || !data->game)
		return (false);
	if (data->game->nb_monster <= 0)
		return (false);
	if (!data->game->monster)
		return (false);
	counter = 0;
	while (counter < data->game->nb_monster)
	{
		if (data->hero.hero_posx == data->game->monster[counter].x
			&& data->hero.hero_posy == data->game->monster[counter].y)
		{
			if (data->game->monster[counter].sleep > 0)
				return (false);
			return (true);
		}
		counter++;
	}
	return (false);
}

bool	game_completion(t_mlx_data *data)
{
	if (data->game->nb_collectible == 0
		&& data->hero.hero_posx == data->game->exit_posx
		&& data->hero.hero_posy == data->game->exit_posy)
		return (true);
	return (false);
}

void	game_won(t_game *game, t_mlx_data *data, char answer)
{
	ft_puts("");
	if (answer == 'y')
	{
		ft_gamewon();
		ft_puts_color(GRE, "You won. YAY !");
		ft_printf("%sFINAL SCORE : %s%d%s\n", GRE, B_G, game->moves, NC);
		ft_puts_rainbow("BOB THE FISHERMAN CAUGHT A MAGICARPE\n");
	}
	else
	{
		ft_gameover();
		if (answer == 'n')
		{
			ft_puts_color(RED, "Oh no... You exited the game... ");
			ft_printf("%sFINAL SCORE : %s%d%s\n", RED, B_R, game->moves, NC);
			ft_puts_rainbow("You'll do better next time :)\n");
		}
		if (answer == 'm')
		{
			ft_puts_color(RED, "Oh no... Your girlfriend caught you ! ");
			ft_printf("%sFINAL SCORE : %s%d%s\n", RED, B_R, game->moves, NC);
			ft_puts_rainbow("Use the power of love better next time <3\n");
		}
	}
	start_end_screen(data, answer);
}

void	destroy_images(t_mlx_data *data)
{
	if (!data)
		return ;
	if (!data->mlx_ptr)
		return ;
	destroy_objects(data);
	destroy_hero(data);
	destroy_hud(data);
	destroy_powers(data);
	if (data->game && data->game->nb_monster != 0)
		destroy_monster(data);
	if (data->win_ptr)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	data->mlx_ptr = NULL;
}
