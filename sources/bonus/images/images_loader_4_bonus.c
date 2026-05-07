/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_loader_4_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 14:02:14 by linux-babas       #+#    #+#             */
/*   Updated: 2026/05/04 17:06:06 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	image_load_error(t_mlx_data *data, char *msg)
{
	ft_puts(msg);
	if (data && data->game)
		free_maps(data->game);
	destroy_images(data);
	exit(EXIT_FAILURE);
}

void	check_image_tab(t_mlx_data *data, void **tab, int size, char *msg)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (!tab[i])
			image_load_error(data, msg);
		i++;
	}
}

void	load_end_images(t_mlx_data *data)
{
	data->object.victory = load_image(data, "textures/bonus/obj/victory.xpm");
	data->object.lose = load_image(data, "textures/bonus/obj/lose.xpm");
	if (!data->object.victory)
		image_load_error(data, "Error\nVICTORY image failed to load");
	if (!data->object.lose)
		image_load_error(data, "Error\nLOSE image failed to load");
}
