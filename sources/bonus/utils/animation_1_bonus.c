/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_1_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:53:45 by bamagere          #+#    #+#             */
/*   Updated: 2026/05/04 17:48:57 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	idle_anim_hook(void *param)
{
	t_mlx_data	*data;
	long		now;
	int			redraw;

	data = (t_mlx_data *)param;
	if (!data || !data->mlx_ptr || !data->win_ptr)
		return (0);
	if (data->end_screen)
	{
		end_game_after_delay(data);
		return (0);
	}
	now = get_time_ms();
	redraw = 0;
	if (update_hero_anim(data, now))
		redraw = 1;
	if (update_monster_anim(data, now))
		redraw = 1;
	if (update_cast_anim(data, now))
		redraw = 1;
	if (update_power_anim(data, now))
		redraw = 1;
	if (redraw)
		draw_all(data);
	return (0);
}

void	what_monster_image(t_mlx_data *data, int x, int y, int sleep)
{
	int	sx;
	int	sy;
	int	f;

	if (!data || !data->game)
		return ;
	if (data->game->nb_monster <= 0)
		return ;
	if (!data->game->monster)
		return ;
	sx = x * TILE - data->cam_x + TILE;
	sy = y * TILE - data->cam_y + TILE;
	f = data->monster_frame;
	if (sleep > 0)
		f = 0;
	if (f < 0)
		f = 0;
	if (f > 3)
		f = 3;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->monster.m_up[f], sx, sy);
}

static void	put_hero_frame(t_mlx_data *data, int f, int sx, int sy)
{
	if (data->game->flag == 2)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->hero.hero_up[f], sx, sy);
	else if (data->game->flag == 1)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->hero.hero_r[f], sx, sy);
	else if (data->game->flag == 3)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->hero.hero_d[f], sx, sy);
	else
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->hero.hero_l[f], sx, sy);
}

void	what_hero_image(t_mlx_data *data, int x, int y)
{
	int	sx;
	int	sy;
	int	f;

	sx = x * TILE - data->cam_x + TILE;
	sy = y * TILE - data->cam_y + TILE;
	if (data->hero_casting)
	{
		f = data->hero_cast_frame;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->hero.power[f], sx, sy);
		return ;
	}
	f = data->hero_frame;
	if (f < 0)
		f = 0;
	if (f > 3)
		f = 3;
	put_hero_frame(data, f, sx, sy);
}

void	idle_anim_hero(t_mlx_data *data)
{
	if (!data)
		return ;
	data->hero_casting = 1;
	data->hero_cast_frame = 0;
	data->last_cast_time = get_time_ms();
}
