/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:30:55 by bamagere          #+#    #+#             */
/*   Updated: 2026/05/05 12:35:52 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*load_image(t_mlx_data *data, char *path)
{
	void	*img;
	int		use;
	int		less;

	use = 0;
	less = 0;
	img = mlx_xpm_file_to_image(data->mlx_ptr, path, &use, &less);
	return (img);
}

void	image_load_error(t_mlx_data *data)
{
	ft_puts("Error\nAn accessible image couldn't load for some reasons");
	if (data && data->game)
		free_maps(data->game);
	destroy_images(data);
	exit(EXIT_FAILURE);
}

void	select_image(t_mlx_data *data)
{
	data->wall = load_image(data, "textures/manda/wall.xpm");
	data->floor = load_image(data, "textures/manda/floor.xpm");
	data->collectible = load_image(data, "textures/manda/collectible.xpm");
	data->exit_close = load_image(data, "textures/manda/door_closed.xpm");
	data->exit_open = load_image(data, "textures/manda/door_opened.xpm");
	data->hero_look_up = load_image(data, "textures/manda/hero_u.xpm");
	data->hero_look_right = load_image(data, "textures/manda/hero_r.xpm");
	data->hero_look_left = load_image(data, "textures/manda/hero_l.xpm");
	if (!data->wall || !data->floor || !data->collectible)
		image_load_error(data);
	if (!data->exit_close || !data->exit_open)
		image_load_error(data);
	if (!data->hero_look_up || !data->hero_look_right)
		image_load_error(data);
	if (!data->hero_look_left)
		image_load_error(data);
}

static void	free_before_mlx_exit(t_game *game)
{
	if (!game)
		exit(EXIT_FAILURE);
	free_maps(game);
	exit(EXIT_FAILURE);
}

void	get_image(t_game *game, t_mlx_data *data)
{
	data->game = game;
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
	{
		ft_puts("Error\nMLX init failed.");
		free_before_mlx_exit(game);
	}
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			game->width * TILE, game->height * TILE, "bamagere game");
	if (data->win_ptr == NULL)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		ft_puts("Error\nWindow creation failed.");
		free_before_mlx_exit(game);
	}
	select_image(data);
	game->moves = 0;
	draw_line(game, data);
	ft_printf("\033[0;33mScore : \033[0m%d\n", game->moves);
	mlx_hook(data->win_ptr, 17, 0, handle_close, data);
	mlx_key_hook(data->win_ptr, handle_input, data);
	if (data->mlx_ptr)
		mlx_loop(data->mlx_ptr);
}
