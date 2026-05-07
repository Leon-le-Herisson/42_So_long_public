/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_loader_2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:36:15 by bamagere          #+#    #+#             */
/*   Updated: 2026/05/01 14:05:22 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_power(t_mlx_data *data)
{
	data->hero.power[0] = load_image(data, "textures/bonus/attack/a1.xpm");
	data->hero.power[1] = load_image(data, "textures/bonus/attack/a2.xpm");
	data->hero.power[2] = load_image(data, "textures/bonus/attack/a3.xpm");
	data->hero.power[3] = load_image(data, "textures/bonus/attack/a4.xpm");
	data->hero.power[4] = load_image(data, "textures/bonus/attack/a5.xpm");
	data->hero.power[5] = load_image(data, "textures/bonus/attack/a6.xpm");
	data->hero.power[6] = load_image(data, "textures/bonus/attack/a7.xpm");
	check_image_tab(data, data->hero.power, 7,
		"Error\nPOWER image failed to load");
}

void	load_power_u(t_mlx_data *data)
{
	data->hero.power_u[0] = load_image(data, "textures/bonus/attack/u1.xpm");
	data->hero.power_u[1] = load_image(data, "textures/bonus/attack/u2.xpm");
	data->hero.power_u[2] = load_image(data, "textures/bonus/attack/u3.xpm");
	data->hero.power_u[3] = load_image(data, "textures/bonus/attack/u4.xpm");
	data->hero.power_u[4] = load_image(data, "textures/bonus/attack/u5.xpm");
	data->hero.power_u[5] = load_image(data, "textures/bonus/attack/u6.xpm");
	data->hero.power_u[6] = load_image(data, "textures/bonus/attack/u7.xpm");
	check_image_tab(data, data->hero.power_u, 7,
		"Error\nPOWER image failed to load");
}

void	load_power_l(t_mlx_data *data)
{
	data->hero.power_l[0] = load_image(data, "textures/bonus/attack/l1.xpm");
	data->hero.power_l[1] = load_image(data, "textures/bonus/attack/l2.xpm");
	data->hero.power_l[2] = load_image(data, "textures/bonus/attack/l3.xpm");
	data->hero.power_l[3] = load_image(data, "textures/bonus/attack/l4.xpm");
	data->hero.power_l[4] = load_image(data, "textures/bonus/attack/l5.xpm");
	data->hero.power_l[5] = load_image(data, "textures/bonus/attack/l6.xpm");
	data->hero.power_l[6] = load_image(data, "textures/bonus/attack/l7.xpm");
	check_image_tab(data, data->hero.power_l, 7,
		"Error\nPOWER image failed to load");
}

void	load_power_d(t_mlx_data *data)
{
	data->hero.power_d[0] = load_image(data, "textures/bonus/attack/d1.xpm");
	data->hero.power_d[1] = load_image(data, "textures/bonus/attack/d2.xpm");
	data->hero.power_d[2] = load_image(data, "textures/bonus/attack/d3.xpm");
	data->hero.power_d[3] = load_image(data, "textures/bonus/attack/d4.xpm");
	data->hero.power_d[4] = load_image(data, "textures/bonus/attack/d5.xpm");
	data->hero.power_d[5] = load_image(data, "textures/bonus/attack/d6.xpm");
	data->hero.power_d[6] = load_image(data, "textures/bonus/attack/d7.xpm");
	check_image_tab(data, data->hero.power_d, 7,
		"Error\nPOWER image failed to load");
}

void	load_power_r(t_mlx_data *data)
{
	data->hero.power_r[0] = load_image(data, "textures/bonus/attack/r1.xpm");
	data->hero.power_r[1] = load_image(data, "textures/bonus/attack/r2.xpm");
	data->hero.power_r[2] = load_image(data, "textures/bonus/attack/r3.xpm");
	data->hero.power_r[3] = load_image(data, "textures/bonus/attack/r4.xpm");
	data->hero.power_r[4] = load_image(data, "textures/bonus/attack/r5.xpm");
	data->hero.power_r[5] = load_image(data, "textures/bonus/attack/r6.xpm");
	data->hero.power_r[6] = load_image(data, "textures/bonus/attack/r7.xpm");
	check_image_tab(data, data->hero.power_r, 7,
		"Error\nPOWER image failed to load");
}
