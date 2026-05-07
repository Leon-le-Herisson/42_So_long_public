/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:07:16 by linux-babas       #+#    #+#             */
/*   Updated: 2025/12/05 17:31:59 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_printfs.h"

static int	is_zero_str(const char *s)
{
	if (s[0] == '\0')
		return (1);
	if (s[0] == '0' && s[1] == '\0')
		return (1);
	return (0);
}

char	*get_hex_prefix(int upper)
{
	if (upper)
		return ("0X");
	return ("0x");
}

static int	write_hex(t_format *f, const char *core)
{
	int	count;

	count = 0;
	if (f->width == -1)
	{
		count = write(1, core, ft_strlen(core));
		return (count);
	}
	if (f->flag_minus)
	{
		count = write_padded_right(core, f->width);
		return (count);
	}
	count = write_padded_left(core, f->width);
	return (count);
}

static int	handle_hex_zero_mode(t_format *f, unsigned int n,
				char *digits, int upper)
{
	int	count;

	count = 0;
	if (!f->flag_minus && f->flag_zero
		&& f->precision == -1 && f->width > 0)
	{
		if (f->flag_hash && n != 0)
			count = write_zero_left(get_hex_prefix(upper),
					digits, f->width);
		else
			count = write_zero_left("", digits, f->width);
		free(digits);
		return (count);
	}
	return (-1);
}

int	print_hex_bonus(t_format *f, unsigned int n, int upper)
{
	char	*digits;
	char	*core;
	int		count;

	digits = build_unsigned_core(f, (unsigned long)n, 16, upper);
	if (!digits)
		return (0);
	count = handle_hex_zero_mode(f, n, digits, upper);
	if (count != -1)
		return (count);
	core = digits;
	if (f->flag_hash && !is_zero_str(digits) && n != 0)
	{
		core = join2(get_hex_prefix(upper), digits);
		free(digits);
		if (!core)
			return (0);
	}
	count = write_hex(f, core);
	free(core);
	return (count);
}
