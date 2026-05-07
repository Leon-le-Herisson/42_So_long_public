/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 22:42:49 by bamagere          #+#    #+#             */
/*   Updated: 2026/05/05 12:35:52 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	is_move_key(int keysym)
{
	if (keysym == 'w' || keysym == 65362)
		return (1);
	if (keysym == 's' || keysym == 65364)
		return (1);
	if (keysym == 'a' || keysym == 65361)
		return (1);
	if (keysym == 'd' || keysym == 65363)
		return (1);
	return (0);
}

static void	clean_exit_game(t_mlx_data *data)
{
	if (!data)
		exit(0);
	if (data->game)
		free_maps(data->game);
	destroy_images(data);
	exit(0);
}

static void	apply_key(int keysym, t_mlx_data *data)
{
	if (keysym == 'w' || keysym == 65362)
		move_up(data);
	else if (keysym == 's' || keysym == 65364)
		move_down(data);
	else if (keysym == 'a' || keysym == 65361)
		move_left(data);
	else if (keysym == 'd' || keysym == 65363)
		move_right(data);
	else if (keysym == XK_space || keysym == 32 || keysym == 65)
		love_power(data);
}

int	handle_input(int keysym, void *param)
{
	t_mlx_data	*data;

	data = (t_mlx_data *)param;
	if (!data || !data->game)
		return (0);
	if (data->end_screen)
		return (0);
	if (keysym == XK_Escape)
		clean_exit_game(data);
	if (data->hero_casting && is_move_key(keysym))
		return (0);
	apply_key(keysym, data);
	if (data->end_screen)
		return (0);
	if (monster_win(data))
	{
		game_won(data->game, data, 'm');
		return (0);
	}
	draw_all(data);
	if (game_completion(data) == true)
		game_won(data->game, data, 'y');
	return (0);
}

int	handle_close(void *param)
{
	t_mlx_data	*data;

	data = (t_mlx_data *)param;
	clean_exit_game(data);
	return (0);
}
