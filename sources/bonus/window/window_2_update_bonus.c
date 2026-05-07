/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_2_update_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamagere <bamagere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:18:24 by bamagere          #+#    #+#             */
/*   Updated: 2026/01/16 12:19:51 by bamagere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	update_view(t_mlx_data *data)
{
	data->view_x0 = 0;
	data->view_y0 = 0;
	data->view_x1 = data->game->width;
	data->view_y1 = data->game->height;
	if (data->cam_x > 0)
		data->view_x0 = data->cam_x / TILE;
	if (data->cam_y > 0)
		data->view_y0 = data->cam_y / TILE;
	data->view_x1 = (data->cam_x + data->view_w) / TILE + 1;
	data->view_y1 = (data->cam_y + data->view_h) / TILE + 1;
	if (data->view_x1 > data->game->width)
		data->view_x1 = data->game->width;
	if (data->view_y1 > data->game->height)
		data->view_y1 = data->game->height;
}

void	update_camera(t_mlx_data *data)
{
	int	map_w;
	int	map_h;

	map_w = data->game->width * TILE;
	map_h = data->game->height * TILE;
	data->cam_x = (data->hero.hero_posx * TILE + (TILE / 2))
		- (data->view_w / 2);
	data->cam_y = (data->hero.hero_posy * TILE + (TILE / 2))
		- (data->view_h / 2);
	if (map_w <= data->view_w)
		data->cam_x = -((data->view_w - map_w) / 2);
	if (map_h <= data->view_h)
		data->cam_y = -((data->view_h - map_h) / 2);
	if (map_w > data->view_w && data->cam_x < 0)
		data->cam_x = 0;
	if (map_h > data->view_h && data->cam_y < 0)
		data->cam_y = 0;
	if (map_w > data->view_w && data->cam_x > map_w - data->view_w)
		data->cam_x = map_w - data->view_w;
	if (map_h > data->view_h && data->cam_y > map_h - data->view_h)
		data->cam_y = map_h - data->view_h;
	update_view(data);
}
