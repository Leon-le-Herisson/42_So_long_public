/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:50:21 by bamagere          #+#    #+#             */
/*   Updated: 2026/05/04 18:31:50 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	xpm_checker_1(void)
{
	ft_path_checker("./textures/bonus/obj/wall.xpm");
	ft_path_checker("./textures/bonus/obj/floor.xpm");
	ft_path_checker("./textures/bonus/obj/closed.xpm");
	ft_path_checker("./textures/bonus/obj/opened.xpm");
	ft_path_checker("./textures/bonus/obj/col.xpm");
	ft_path_checker("./textures/bonus/obj/victory.xpm");
	ft_path_checker("./textures/bonus/obj/lose.xpm");
	ft_path_checker("./textures/bonus/obj/frame.xpm");
	ft_path_checker("./textures/bonus/hud/0.xpm");
	ft_path_checker("./textures/bonus/hud/1.xpm");
	ft_path_checker("./textures/bonus/hud/2.xpm");
	ft_path_checker("./textures/bonus/hud/3.xpm");
	ft_path_checker("./textures/bonus/hud/4.xpm");
	ft_path_checker("./textures/bonus/hud/5.xpm");
	ft_path_checker("./textures/bonus/hud/6.xpm");
	ft_path_checker("./textures/bonus/hud/7.xpm");
	ft_path_checker("./textures/bonus/hud/8.xpm");
	ft_path_checker("./textures/bonus/hud/9.xpm");
}

void	get_dimensions(t_mlx_data *data)
{
	int	i;

	i = 0;
	data->game->width = ft_strlen(data->game->map[0]);
	while (data->game->map[i])
	{
		if ((int)ft_strlen(data->game->map[i]) != data->game->width)
		{
			ft_puts("Error\nThe Map isn't well dimensioned");
			free_maps(data->game);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	data->game->height = i;
}

void	wall_x(t_mlx_data *data)
{
	int	i;

	i = 0;
	while (i < data->game->width)
	{
		if (data->game->map[0][i] != '1'
			|| data->game->map[data->game->height - 1][i] != '1')
		{
			ft_puts("Error\nThe surrondings aren't only walls");
			free_maps(data->game);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	wall_y(t_mlx_data *data)
{
	int	i;

	i = 1;
	while (i < data->game->height)
	{
		if (data->game->map[i][0] != '1'
			|| data->game->map[i][data->game->width - 1] != '1')
		{
			ft_puts("Error\nThe surrondings aren't only walls.");
			free_maps(data->game);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	map_completable(t_mlx_data *data)
{
	int	p_counters;
	int	x;
	int	y;

	p_counters = 0;
	while (call_flood_fill(&p_counters, data) == true)
		flood_fill(data);
	y = 1;
	while (y < data->game->height - 1)
	{
		x = 1;
		while (x < data->game->width - 1)
		{
			if (data->game->copy[y][x] == 'E' || data->game->copy[y][x] == 'C')
			{
				ft_puts("Error\nThe map can't be finished without cheatcode.");
				free_maps(data->game);
				exit(EXIT_FAILURE);
			}
			x++;
		}
		y++;
	}
}
