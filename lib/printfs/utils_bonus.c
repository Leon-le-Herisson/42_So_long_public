/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamagere <bamagere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 00:01:55 by linux-babas       #+#    #+#             */
/*   Updated: 2026/01/06 12:58:03 by bamagere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_printfs.h"

char	*join2(const char *a, const char *b)
{
	size_t	len_a;
	size_t	len_b;
	char	*s;

	len_a = ft_strlen(a);
	len_b = ft_strlen(b);
	s = (char *)ft_calloc(len_a + len_b + 1, 1);
	if (!s)
		return (NULL);
	ft_memcpy(s, a, len_a);
	ft_memcpy(s + len_a, b, len_b);
	return (s);
}

static char	*apply_precision_num(const char *digits, int precision)
{
	size_t	len;
	int		need;
	char	*pad;
	char	*res;

	if (precision == -1)
		return (ft_strdup(digits));
	if (precision == 0 && digits[0] == '0' && digits[1] == '\0')
		return (ft_strdup(""));
	len = ft_strlen(digits);
	if ((int)len >= precision)
		return (ft_strdup(digits));
	need = precision - (int)len;
	pad = (char *)ft_calloc(need + 1, sizeof(char));
	if (pad == NULL)
		return (NULL);
	while (need > 0)
	{
		pad[need - 1] = '0';
		need--;
	}
	res = join2(pad, digits);
	free(pad);
	return (res);
}

char	*deal_res(long n, char *padded, t_format *f)
{
	char	*res;

	res = NULL;
	if (n < 0)
		res = join2("-", padded);
	else if (f->flag_plus)
		res = join2("+", padded);
	else if (f->flag_space)
		res = join2(" ", padded);
	else
		res = ft_strdup(padded);
	return (res);
}

char	*build_signed_core(t_format *f, long n)
{
	unsigned long	un;
	char			*digits;
	char			*padded;
	char			*res;

	if (n < 0)
		un = (unsigned long)(-n);
	else
		un = (unsigned long)n;
	digits = ft_utoa_base(un, 10, 0);
	if (digits == NULL)
		return (NULL);
	padded = apply_precision_num(digits, f->precision);
	free(digits);
	if (padded == NULL)
		return (NULL);
	res = NULL;
	res = deal_res(n, padded, f);
	free(padded);
	return (res);
}

char	*build_unsigned_core(t_format *f, unsigned long n, int base, int upper)
{
	char	*digits;
	char	*padded;

	digits = ft_utoa_base(n, base, upper);
	if (digits == NULL)
		return (NULL);
	padded = apply_precision_num(digits, f->precision);
	free(digits);
	if (padded == NULL)
		return (NULL);
	return (padded);
}
