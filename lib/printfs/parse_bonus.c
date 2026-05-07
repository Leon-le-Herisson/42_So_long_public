/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:59:13 by linux-babas       #+#    #+#             */
/*   Updated: 2025/12/05 17:31:54 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_printfs.h"

static int	is_flag(int c)
{
	if (c == '-' || c == '0' || c == '#' || c == ' ' || c == '+')
		return (1);
	return (0);
}

static int	atoi_form(const char *s, int i, int *width)
{
	int	n;

	n = 0;
	while ('0' <= s[i] && s[i] <= '9')
	{
		n = n * 10 + (s[i] - '0');
		i++;
	}
	*width = n;
	return (i);
}

static int	parse_precision(const char *s, int i, t_format *f, va_list args)
{
	int	p;
	int	count;

	count = 0;
	if (s[i] != '.')
		return (i);
	i++;
	f->precision = 0;
	if (s[i] == '*')
	{
		p = va_arg(args, int);
		if (p < 0)
			f->precision = -1;
		else
			f->precision = p;
		return (i + 1);
	}
	if ('0' <= s[i] && s[i] <= '9')
	{
		count = atoi_form(s, i, &f->precision);
		return (count);
	}
	return (i);
}

static int	parse_width(const char *s, int i, t_format *f, va_list args)
{
	int	width;
	int	count;

	if (s[i] == '*')
	{
		width = va_arg(args, int);
		if (width < 0)
		{
			f->flag_minus = 1;
			width = -width;
		}
		f->width = width;
		return (i + 1);
	}
	if ('0' <= s[i] && s[i] <= '9')
	{
		count = atoi_form(s, i, &f->width);
		return (count);
	}
	return (i);
}

int	parse_bonus(const char *s, int i, t_format *f, va_list args)
{
	while (is_flag(s[i]))
	{
		if (s[i] == '-')
			f->flag_minus = 1;
		else if (s[i] == '0')
			f->flag_zero = 1;
		else if (s[i] == '#')
			f->flag_hash = 1;
		else if (s[i] == ' ')
			f->flag_space = 1;
		else if (s[i] == '+')
			f->flag_plus = 1;
		i++;
	}
	i = parse_width(s, i, f, args);
	i = parse_precision(s, i, f, args);
	f->form = s[i];
	return (i);
}
