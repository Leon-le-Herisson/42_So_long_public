/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:22:13 by linux-babas       #+#    #+#             */
/*   Updated: 2025/12/05 17:31:50 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_printfs.h"

int	write_padded_left(const char *core, int width)
{
	int	len;
	int	pad;
	int	count;

	len = ft_strlen(core);
	pad = width - len;
	if (pad < 0)
		pad = 0;
	count = 0;
	while (pad > 0)
	{
		count += write(1, " ", 1);
		pad--;
	}
	count += write(1, core, len);
	return (count);
}

int	write_padded_right(const char *core, int width)
{
	int	len;
	int	pad;
	int	count;

	len = ft_strlen(core);
	pad = width - len;
	if (pad < 0)
		pad = 0;
	count = 0;
	count += write(1, core, len);
	while (pad > 0)
	{
		count += write(1, " ", 1);
		pad--;
	}
	return (count);
}

int	write_zero_left(const char *prefix, const char *digits, int width)
{
	int	lp;
	int	ld;
	int	pad;
	int	count;

	lp = ft_strlen(prefix);
	ld = ft_strlen(digits);
	pad = width - (lp + ld);
	if (pad < 0)
		pad = 0;
	count = 0;
	count += write(1, prefix, lp);
	while (pad > 0)
	{
		count += write(1, "0", 1);
		pad--;
	}
	count += write(1, digits, ld);
	return (count);
}
