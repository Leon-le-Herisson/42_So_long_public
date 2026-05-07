/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:53:07 by bamagere          #+#    #+#             */
/*   Updated: 2026/05/05 12:35:52 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	safe_destroy_image(t_mlx_data *data, void **img)
{
	if (!data || !data->mlx_ptr)
		return ;
	if (!img || !*img)
		return ;
	mlx_destroy_image(data->mlx_ptr, *img);
	*img = NULL;
}

void	destroy_images(t_mlx_data *data)
{
	if (!data)
		return ;
	safe_destroy_image(data, &data->wall);
	safe_destroy_image(data, &data->floor);
	safe_destroy_image(data, &data->collectible);
	safe_destroy_image(data, &data->hero_look_left);
	safe_destroy_image(data, &data->hero_look_right);
	safe_destroy_image(data, &data->hero_look_up);
	safe_destroy_image(data, &data->exit_open);
	safe_destroy_image(data, &data->exit_close);
	if (data->mlx_ptr && data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	data->win_ptr = NULL;
	data->mlx_ptr = NULL;
}

int	handle_input(int keysym, void *param)
{
	t_mlx_data	*data;
	t_game		*game;

	data = (t_mlx_data *)param;
	game = data->game;
	if (keysym == XK_Escape)
		game_won(game, data, 'n');
	else if (keysym == 'w' || keysym == 65362)
		move_up(game);
	else if (keysym == 's' || keysym == 65364)
		move_down(game);
	else if (keysym == 'a' || keysym == 65361)
		move_left(game);
	else if (keysym == 'd' || keysym == 65363)
		move_right(game);
	if (game->moves < 0)
		game->moves = 0;
	draw_line(game, data);
	if (game_completion(game) == true)
		game_won(game, data, 'y');
	return (0);
}

int	handle_close(void *param)
{
	t_mlx_data	*data;
	t_game		*game;

	data = (t_mlx_data *)param;
	game = data->game;
	game_won(game, data, 'n');
	return (0);
}
