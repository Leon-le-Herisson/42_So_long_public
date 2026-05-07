/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_destroy_2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamagere <bamagere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:43:47 by bamagere          #+#    #+#             */
/*   Updated: 2026/01/18 19:06:16 by bamagere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	destroy_power_u(t_mlx_data *data)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		safe_destroy_image(data, &data->hero.power_u[i]);
		i++;
	}
}

static void	destroy_power_l(t_mlx_data *data)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		safe_destroy_image(data, &data->hero.power_l[i]);
		i++;
	}
}

static void	destroy_power_d(t_mlx_data *data)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		safe_destroy_image(data, &data->hero.power_d[i]);
		i++;
	}
}

static void	destroy_power_r(t_mlx_data *data)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		safe_destroy_image(data, &data->hero.power_r[i]);
		i++;
	}
}

void	destroy_powers(t_mlx_data *data)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		safe_destroy_image(data, &data->hero.power[i]);
		i++;
	}
	destroy_power_u(data);
	destroy_power_l(data);
	destroy_power_d(data);
	destroy_power_r(data);
}
