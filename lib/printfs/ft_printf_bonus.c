/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 00:01:17 by linux-babas       #+#    #+#             */
/*   Updated: 2025/11/17 10:21:44 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_printfs.h"

static void	init_struct(t_format *f)
{
	f->form = '\0';
	f->flag_minus = 0;
	f->flag_plus = 0;
	f->flag_zero = 0;
	f->flag_space = 0;
	f->flag_hash = 0;
	f->width = -1;
	f->precision = -1;
}

static int	dispatch_bonus(t_format *f, va_list args)
{
	int	i;

	i = 0;
	if (f->form == 'c')
		i = print_char_bonus(f, va_arg(args, int));
	if (f->form == 's')
		i = print_str_bonus(f, va_arg(args, const char *));
	if (f->form == 'p')
		i = print_ptr_bonus(f, (unsigned long)va_arg(args, void *));
	if (f->form == 'd' || f->form == 'i')
		i = print_int_bonus(f, va_arg(args, int));
	if (f->form == 'X')
		i = print_hex_bonus(f, va_arg(args, unsigned int), 1);
	if (f->form == 'x')
		i = print_hex_bonus(f, va_arg(args, unsigned int), 0);
	if (f->form == 'u')
		i = print_uint_bonus(f, va_arg(args, unsigned int));
	if (f->form == '%')
		i = print_percent_bonus(f);
	return (i);
}

static void	apply_flag_priority(t_format *f)
{
	if (f->flag_minus == 1)
		f->flag_zero = 0;
	if (f->flag_plus == 1)
		f->flag_space = 0;
	if (f->precision != -1)
		f->flag_zero = 0;
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	t_format	f;
	int			i;
	int			count;

	if (!format)
		return (-1);
	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			init_struct(&f);
			i = parse_bonus(format, i + 1, &f, args);
			apply_flag_priority(&f);
			count += dispatch_bonus(&f, args);
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
