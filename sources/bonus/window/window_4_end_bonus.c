/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_4_end_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 17:09:01 by linux-babas       #+#    #+#             */
/*   Updated: 2026/05/05 12:35:52 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	set_end_window_size(t_mlx_data *data, char result)
{
	if (result == 'y')
	{
		data->win_w = VICTORY_WIN_W;
		data->win_h = VICTORY_WIN_H;
		return ;
	}
	data->win_w = LOSE_WIN_W;
	data->win_h = LOSE_WIN_H;
}

static void	reopen_end_window(t_mlx_data *data)
{
	if (data->win_ptr)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			data->win_w, data->win_h, "bamagere end screen");
	if (!data->win_ptr)
	{
		free_maps(data->game);
		destroy_images(data);
		exit(EXIT_FAILURE);
	}
	mlx_hook(data->win_ptr, 17, 0, handle_close, data);
	mlx_key_hook(data->win_ptr, handle_input, data);
}

void	draw_end_screen(t_mlx_data *data)
{
	void	*img;

	if (!data || !data->mlx_ptr || !data->win_ptr)
		return ;
	img = data->object.lose;
	if (data->end_result == 'y')
		img = data->object.victory;
	if (!img)
		return ;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img, 0, 0);
}

void	start_end_screen(t_mlx_data *data, char result)
{
	if (!data || data->end_screen)
		return ;
	data->end_screen = 1;
	data->end_result = result;
	data->end_start = get_time_ms();
	set_end_window_size(data, result);
	reopen_end_window(data);
	draw_end_screen(data);
}

void	end_game_after_delay(t_mlx_data *data)
{
	if (!data || !data->end_screen)
		return ;
	if (get_time_ms() - data->end_start < END_DELAY)
	{
		draw_end_screen(data);
		return ;
	}
	free_maps(data->game);
	destroy_images(data);
	exit(0);
}
