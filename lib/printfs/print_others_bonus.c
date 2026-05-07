/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_others_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamagere <bamagere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:13:28 by linux-babas       #+#    #+#             */
/*   Updated: 2026/01/06 12:45:01 by bamagere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_printfs.h"

int	print_char_bonus(t_format *f, char c)
{
	int	count;
	int	pad;

	count = 0;
	if (f->width < 1)
		f->width = 1;
	pad = f->width - 1;
	if (!f->flag_minus)
	{
		while (pad > 0)
		{
			count += write(1, " ", 1);
			pad--;
		}
	}
	count += write(1, &c, 1);
	if (f->flag_minus)
	{
		while (pad > 0)
		{
			count += write(1, " ", 1);
			pad--;
		}
	}
	return (count);
}

int	print_percent_bonus(t_format *f)
{
	int	count;

	(void)f;
	count = (int)write(1, "%", 1);
	return (count);
}

int	print_str_bonus(t_format *f, const char *s)
{
	int		len;
	int		cut;
	char	*core;
	int		count;

	if (!s)
		s = "(null)";
	len = (int)ft_strlen(s);
	if (f->precision != -1 && f->precision < len)
		cut = f->precision;
	else
		cut = len;
	core = (char *)ft_calloc(cut + 1, sizeof(char));
	if (!core)
		return (0);
	if (cut > 0)
		ft_memcpy(core, s, cut);
	if (f->width == -1)
		count = (int)write(1, core, cut);
	else if (f->flag_minus)
		count = write_padded_right(core, f->width);
	else
		count = write_padded_left(core, f->width);
	free(core);
	return (count);
}
