/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 00:00:33 by linux-babas       #+#    #+#             */
/*   Updated: 2025/12/05 17:27:48 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_printfs.h"
/* Implementation of the printf */

int	fd_print_char(int fd, int arg, int i)
{
	write(fd, &arg, 1);
	i++;
	return (i);
}

int	fd_print_nb(int fd, int arg, int i)
{
	if (arg == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (i + 11);
	}
	if (arg == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	if (arg < 0)
	{
		i = fd_print_char(fd, '-', i);
		i = fd_print_nb(fd, (-1 * arg), i);
	}
	if (0 <= arg && arg <= 9)
		i = fd_print_char(fd, (arg + '0'), i);
	if (arg > 9)
	{
		i = fd_print_nb(fd, arg / 10, i);
		i = fd_print_char(fd, ((arg % 10) + '0'), i);
	}
	return (i);
}

static int	fd_print_str(int fd, char *arg, int i)
{
	int	j;

	j = 0;
	if (!arg)
		i = fd_print_str(fd, "(null)", i);
	else
	{
		while (arg[j])
		{
			write(fd, &(arg[j]), 1);
			j++;
			i++;
		}
	}
	return (i);
}

static int	fd_print_analyser(int fd, char c, va_list args)
{
	int	i;

	i = 0;
	if (c == 'c')
		i += fd_print_char(fd, va_arg(args, int), i);
	if (c == 's')
		i += fd_print_str(fd, va_arg(args, char *), i);
	if (c == 'p')
		i += fd_print_p(fd, va_arg(args, size_t), i);
	if (c == 'd' || c == 'i')
		i += fd_print_nb(fd, va_arg(args, int), i);
	if (c == 'X')
		i += fd_print_nb_base_bigx(fd, va_arg(args, size_t), i);
	if (c == 'x')
		i += fd_print_nb_base_x(fd, va_arg(args, size_t), i);
	if (c == 'u')
		i += fd_print_nb_u(fd, va_arg(args, unsigned int), i);
	if (c == '%')
		i += fd_print_char(fd, '%', i);
	return (i);
}

int	ft_fd_printf(int fd, const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	if (!format)
		return (-1);
	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			count += fd_print_analyser(fd, format[++i], args);
		else
			count += write(fd, &format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
