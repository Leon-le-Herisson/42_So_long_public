/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 00:00:14 by linux-babas       #+#    #+#             */
/*   Updated: 2025/12/05 17:27:44 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_printfs.h"
/* Utility functions for ft_printf */

int	fd_print_p(int fd, size_t arg, int i)
{
	char	*hexabase;
	int		length;

	hexabase = "0123456789abcdef";
	length = 0;
	if (!arg)
	{
		write(fd, "(nil)", 5);
		i += 5;
		return (i);
	}
	if (arg >= 16)
		length += fd_print_p(fd, arg / 16, i);
	if (length == 0)
		length += write(fd, "0x", 2);
	i = fd_print_char(fd, hexabase[arg % 16], i);
	i += length;
	return (i);
}

int	fd_print_nb_base_x(int fd, size_t arg, int i)
{
	unsigned int	j;

	j = (unsigned int)arg;
	if (j == 0)
	{
		i = fd_print_char(fd, '0', i);
		return (i);
	}
	if (j >= 16)
	{
		i = fd_print_nb_base_x(fd, j / 16, i);
		i = fd_print_nb_base_x(fd, j % 16, i);
	}
	else
	{
		if (j <= 9)
			i = fd_print_char(fd, j + '0', i);
		else
			i = fd_print_char(fd, j + 'a' - 10, i);
	}
	return (i);
}

int	fd_print_nb_base_bigx(int fd, size_t arg, int i)
{
	unsigned int	j;

	j = (unsigned int)arg;
	if (j == 0)
	{
		i = fd_print_char(fd, '0', i);
		return (i);
	}
	if (j >= 16)
	{
		i = fd_print_nb_base_bigx(fd, j / 16, i);
		i = fd_print_nb_base_bigx(fd, j % 16, i);
	}
	else
	{
		if (j <= 9)
			i = fd_print_char(fd, j + '0', i);
		else
			i = fd_print_char(fd, j + 'A' - 10, i);
	}
	return (i);
}

int	fd_print_nb_u(int fd, unsigned int arg, int i)
{
	if (arg == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	if (0 < arg && arg <= 9)
		i = fd_print_char(fd, (arg + '0'), i);
	if (arg > 9)
	{
		i = fd_print_nb_u(fd, arg / 10, i);
		i = fd_print_char(fd, ((arg % 10) + '0'), i);
	}
	return (i);
}
