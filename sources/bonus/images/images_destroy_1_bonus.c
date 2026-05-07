/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_destroy_1_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:26:17 by bamagere          #+#    #+#             */
/*   Updated: 2026/05/04 17:42:14 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	safe_destroy_image(t_mlx_data *data, void **img)
{
	if (!data || !data->mlx_ptr)
		return ;
	if (!img || !*img)
		return ;
	mlx_destroy_image(data->mlx_ptr, *img);
	*img = NULL;
}

static void	destroy_tab(t_mlx_data *data, void **tab, int size)
{
	int	i;

	if (!data || !tab)
		return ;
	i = 0;
	while (i < size)
	{
		safe_destroy_image(data, &tab[i]);
		i++;
	}
}

void	destroy_hero(t_mlx_data *data)
{
	if (!data)
		return ;
	destroy_tab(data, data->hero.hero_up, 4);
	destroy_tab(data, data->hero.hero_l, 4);
	destroy_tab(data, data->hero.hero_r, 4);
	destroy_tab(data, data->hero.hero_d, 4);
}

void	destroy_monster(t_mlx_data *data)
{
	if (!data)
		return ;
	destroy_tab(data, data->monster.m_up, 4);
	if (data->game && data->game->monster)
		free(data->game->monster);
	if (data->game)
		data->game->monster = NULL;
}

void	destroy_objects(t_mlx_data *data)
{
	if (!data)
		return ;
	safe_destroy_image(data, &data->object.wall);
	safe_destroy_image(data, &data->object.floor);
	safe_destroy_image(data, &data->object.exit_open);
	safe_destroy_image(data, &data->object.exit_close);
	safe_destroy_image(data, &data->object.collectible);
	safe_destroy_image(data, &data->object.frame);
	safe_destroy_image(data, &data->object.victory);
	safe_destroy_image(data, &data->object.lose);
}
