/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windraw_3_hud_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamagere <bamagere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:56:51 by bamagere          #+#    #+#             */
/*   Updated: 2026/01/15 17:23:27 by bamagere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	put_digit(t_mlx_data *data, int d, int x, int y)
{
	if (d < 0 || d > 9)
		return ;
	if (!data->hud.digits[d])
		return ;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->hud.digits[d], x, y);
}

static int	count_digits(int n)
{
	int	c;

	c = 1;
	while (n >= 10)
	{
		n = n / 10;
		c++;
	}
	return (c);
}

static void	draw_number(t_mlx_data *data, int n, int x, int y)
{
	int	digits;
	int	i;
	int	div;
	int	d;

	if (n < 0)
		n = 0;
	digits = count_digits(n);
	div = 1;
	i = 1;
	while (i < digits)
	{
		div = div * 10;
		i++;
	}
	while (div > 0)
	{
		d = n / div;
		put_digit(data, d, x, y);
		n = n % div;
		div = div / 10;
		x += TILE;
	}
}

void	draw_hud(t_mlx_data *data)
{
	int	x;
	int	y;

	x = TILE;
	y = 0;
	draw_number(data, data->game->moves, x, y);
}
