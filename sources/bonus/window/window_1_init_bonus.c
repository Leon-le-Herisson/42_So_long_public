/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_1_init_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:24:25 by bamagere          #+#    #+#             */
/*   Updated: 2026/05/05 12:35:52 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	init_mlx_ptr(t_mlx_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
	{
		ft_puts("Error\nMLX init failed.");
		free_before_mlx_exit(data);
	}
}

static void	init_window(t_mlx_data *data)
{
	set_window_size(data);
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			data->win_w, data->win_h, "bamagere game");
	if (data->win_ptr == NULL)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		ft_puts("Error\nWindow creation failed.");
		free_before_mlx_exit(data);
	}
}

static void	init_view(t_mlx_data *data)
{
	data->view_w = data->win_w - (2 * TILE);
	data->view_h = data->win_h - (2 * TILE);
	if (data->view_w < TILE)
		data->view_w = TILE;
	if (data->view_h < TILE)
		data->view_h = TILE;
}

static void	start_game_loop(t_mlx_data *data)
{
	draw_all(data);
	mlx_hook(data->win_ptr, 17, 0, handle_close, data);
	mlx_key_hook(data->win_ptr, handle_input, data);
	mlx_loop_hook(data->mlx_ptr, idle_anim_hook, data);
	mlx_loop(data->mlx_ptr);
}

void	get_image(t_mlx_data *data)
{
	init_mlx_ptr(data);
	init_window(data);
	download_images(data);
	init_view(data);
	start_game_loop(data);
}
