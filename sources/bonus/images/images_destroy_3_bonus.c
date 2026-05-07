/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_destroy_3_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 14:31:05 by linux-babas       #+#    #+#             */
/*   Updated: 2026/05/01 10:50:20 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	destroy_hud(t_mlx_data *data)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		safe_destroy_image(data, &data->hud.digits[i]);
		i++;
	}
}
