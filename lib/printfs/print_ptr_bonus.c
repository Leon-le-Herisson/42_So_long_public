/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamagere <bamagere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 12:45:10 by bamagere          #+#    #+#             */
/*   Updated: 2026/01/06 12:45:14 by bamagere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_printfs.h"

static int	handle_ptr_zero_mode(t_format *f, char *core)
{
	int	count;

	if (!f->flag_minus && f->flag_zero && f->precision == -1)
	{
		count = write_zero_left("0x", core + 2, f->width);
		free(core);
		return (count);
	}
	return (-1);
}

static int	write_ptr_padded(t_format *f, char *core)
{
	int	count;

	if (f->flag_minus)
		count = write_padded_right(core, f->width);
	else
		count = write_padded_left(core, f->width);
	free(core);
	return (count);
}

int	print_ptr_bonus(t_format *f, unsigned long p)
{
	char	*digits;
	char	*core;
	int		count;

	if (p == 0)
		return ((int)write(1, "(nil)", 5));
	f->flag_hash = 0;
	digits = build_unsigned_core(f, p, 16, 0);
	if (!digits)
		return (0);
	core = join2("0x", digits);
	free(digits);
	if (!core)
		return (0);
	count = handle_ptr_zero_mode(f, core);
	if (count != -1)
		return (count);
	count = write_ptr_padded(f, core);
	return (count);
}
