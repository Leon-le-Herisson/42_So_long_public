/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:40:10 by linux-babas       #+#    #+#             */
/*   Updated: 2025/12/05 17:32:02 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_printfs.h"

static int	write_num(t_format *f, char *core)
{
	int			count;
	const char	*digits;
	char		sign[2];

	if (f->width == -1)
		return ((int)write(1, core, ft_strlen(core)));
	if (!f->flag_minus && f->flag_zero && f->precision == -1)
	{
		if (core[0] == '-' || core[0] == '+' || core[0] == ' ')
		{
			sign[0] = core[0];
			sign[1] = '\0';
			digits = core + 1;
			count = write_zero_left(sign, digits, f->width);
		}
		else
			count = write_zero_left("", core, f->width);
		return (count);
	}
	if (f->flag_minus)
		return (write_padded_right(core, f->width));
	return (write_padded_left(core, f->width));
}

int	print_int_bonus(t_format *f, long n)
{
	char	*core;
	int		count;

	count = 0;
	core = build_signed_core(f, n);
	if (!core)
		return (0);
	count = write_num(f, core);
	free(core);
	return (count);
}

int	print_uint_bonus(t_format *f, unsigned int n)
{
	char	*core;
	int		count;

	count = 0;
	core = build_unsigned_core(f, (unsigned long)n, 10, 0);
	if (!core)
		return (0);
	count = write_num(f, core);
	free(core);
	return (count);
}
