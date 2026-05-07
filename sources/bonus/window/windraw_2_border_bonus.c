/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windraw_2_border_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamagere <bamagere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 12:04:25 by bamagere          #+#    #+#             */
/*   Updated: 2026/01/15 17:23:33 by bamagere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	draw_top(t_mlx_data *data)
{
	int	x;

	x = 0;
	while (x < data->win_w)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->object.frame, x, 0);
		x += TILE;
	}
}

static void	draw_bottom(t_mlx_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = data->win_h - TILE;
	while (x < data->win_w)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->object.frame, x, y);
		x += TILE;
	}
}

static void	draw_sides(t_mlx_data *data)
{
	int	y;

	y = TILE;
	while (y < data->win_h - TILE)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->object.frame, 0, y);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->object.frame, data->win_w - TILE, y);
		y += TILE;
	}
}

void	draw_border(t_mlx_data *data)
{
	draw_top(data);
	draw_bottom(data);
	draw_sides(data);
}
