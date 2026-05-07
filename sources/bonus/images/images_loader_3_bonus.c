/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_loader_3_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 14:40:17 by linux-babas       #+#    #+#             */
/*   Updated: 2026/05/01 14:11:09 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	load_hero_north(t_mlx_data *data)
{
	data->hero.hero_up[0] = load_image(data, "textures/bonus/hero/N/n1.xpm");
	data->hero.hero_up[1] = load_image(data, "textures/bonus/hero/N/n2.xpm");
	data->hero.hero_up[2] = load_image(data, "textures/bonus/hero/N/n3.xpm");
	data->hero.hero_up[3] = load_image(data, "textures/bonus/hero/N/n4.xpm");
	check_image_tab(data, data->hero.hero_up, 4,
		"Error\nHERO image failed to load");
}

static void	load_hero_east(t_mlx_data *data)
{
	data->hero.hero_r[0] = load_image(data, "textures/bonus/hero/E/e1.xpm");
	data->hero.hero_r[1] = load_image(data, "textures/bonus/hero/E/e2.xpm");
	data->hero.hero_r[2] = load_image(data, "textures/bonus/hero/E/e3.xpm");
	data->hero.hero_r[3] = load_image(data, "textures/bonus/hero/E/e4.xpm");
	check_image_tab(data, data->hero.hero_r, 4,
		"Error\nHERO image failed to load");
}

static void	load_hero_west(t_mlx_data *data)
{
	data->hero.hero_l[0] = load_image(data, "textures/bonus/hero/W/w1.xpm");
	data->hero.hero_l[1] = load_image(data, "textures/bonus/hero/W/w2.xpm");
	data->hero.hero_l[2] = load_image(data, "textures/bonus/hero/W/w3.xpm");
	data->hero.hero_l[3] = load_image(data, "textures/bonus/hero/W/w4.xpm");
	check_image_tab(data, data->hero.hero_l, 4,
		"Error\nHERO image failed to load");
}

static void	load_hero_south(t_mlx_data *data)
{
	data->hero.hero_d[0] = load_image(data, "textures/bonus/hero/S/s1.xpm");
	data->hero.hero_d[1] = load_image(data, "textures/bonus/hero/S/s2.xpm");
	data->hero.hero_d[2] = load_image(data, "textures/bonus/hero/S/s3.xpm");
	data->hero.hero_d[3] = load_image(data, "textures/bonus/hero/S/s4.xpm");
	check_image_tab(data, data->hero.hero_d, 4,
		"Error\nHERO image failed to load");
}

void	load_hero(t_mlx_data *data)
{
	load_hero_north(data);
	load_hero_east(data);
	load_hero_west(data);
	load_hero_south(data);
}
