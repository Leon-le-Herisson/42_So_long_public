/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_loader_1_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:17:06 by bamagere          #+#    #+#             */
/*   Updated: 2026/05/04 17:06:03 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	*load_image(t_mlx_data *data, char *path)
{
	void	*img;
	int		use;
	int		less;

	img = NULL;
	use = 0;
	less = 0;
	img = mlx_xpm_file_to_image(data->mlx_ptr, path, &use, &less);
	return (img);
}

void	load_monster(t_mlx_data *data)
{
	data->monster.m_up[0] = load_image(data, "textures/bonus/monster/bs1.xpm");
	data->monster.m_up[1] = load_image(data, "textures/bonus/monster/bs2.xpm");
	data->monster.m_up[2] = load_image(data, "textures/bonus/monster/bs3.xpm");
	data->monster.m_up[3] = load_image(data, "textures/bonus/monster/bs4.xpm");
	check_image_tab(data, data->monster.m_up, 4,
		"Error\nMONSTER image failed to load");
}

void	load_hud(t_mlx_data *data)
{
	data->hud.digits[0] = load_image(data, "textures/bonus/hud/0.xpm");
	data->hud.digits[1] = load_image(data, "textures/bonus/hud/1.xpm");
	data->hud.digits[2] = load_image(data, "textures/bonus/hud/2.xpm");
	data->hud.digits[3] = load_image(data, "textures/bonus/hud/3.xpm");
	data->hud.digits[4] = load_image(data, "textures/bonus/hud/4.xpm");
	data->hud.digits[5] = load_image(data, "textures/bonus/hud/5.xpm");
	data->hud.digits[6] = load_image(data, "textures/bonus/hud/6.xpm");
	data->hud.digits[7] = load_image(data, "textures/bonus/hud/7.xpm");
	data->hud.digits[8] = load_image(data, "textures/bonus/hud/8.xpm");
	data->hud.digits[9] = load_image(data, "textures/bonus/hud/9.xpm");
	check_image_tab(data, data->hud.digits, 10,
		"Error\nHUD image failed to load");
}

void	load_objects(t_mlx_data *data)
{
	data->object.wall = load_image(data, "textures/bonus/obj/wall.xpm");
	data->object.floor = load_image(data, "textures/bonus/obj/floor.xpm");
	data->object.collectible = load_image(data, "textures/bonus/obj/col.xpm");
	data->object.exit_close = load_image(data, "textures/bonus/obj/closed.xpm");
	data->object.exit_open = load_image(data, "textures/bonus/obj/opened.xpm");
	data->object.frame = load_image(data, "textures/bonus/obj/frame.xpm");
	if (!data->object.wall || !data->object.floor)
		image_load_error(data, "Error\nOBJECT image failed to load");
	if (!data->object.collectible || !data->object.exit_close)
		image_load_error(data, "Error\nOBJECT image failed to load");
	if (!data->object.exit_open || !data->object.frame)
		image_load_error(data, "Error\nOBJECT image failed to load");
}

void	download_images(t_mlx_data *data)
{
	load_hero(data);
	if (data->game->nb_monster > 0)
		load_monster(data);
	load_hud(data);
	load_objects(data);
	load_power(data);
	load_power_u(data);
	load_power_l(data);
	load_power_d(data);
	load_power_r(data);
	load_end_images(data);
}
