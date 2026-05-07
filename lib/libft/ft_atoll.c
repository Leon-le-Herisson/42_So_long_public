/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 03:15:59 by linux-babas       #+#    #+#             */
/*   Updated: 2025/11/08 00:27:12 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Converts a string to a long long integer.
 * @param nptr The string to convert.
 * @return (long long) converted value. Undefined behavior if overflow occurs.
 */
long long	ft_atoll(const char *nptr)
{
	int			sign;
	long long	stock;
	int			i;

	i = 0;
	stock = 0;
	sign = 1;
	while ((9 <= nptr[i] && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		stock = stock * 10 + (nptr[i] - '0');
		if ((stock * sign) < LLONG_MIN || (stock * sign) > LLONG_MAX)
			return (0);
		i++;
	}
	return (stock * sign);
}
