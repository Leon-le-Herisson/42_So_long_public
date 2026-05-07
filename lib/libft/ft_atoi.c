/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:17:02 by bamagere          #+#    #+#             */
/*   Updated: 2025/11/08 00:26:58 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Converts a string to an integer.
 * @param nptr The string to convert.
 * @return (int) the converted integer. Undefined behavior if overflow occurs.
 */
int	ft_atoi(const char *nptr)
{
	int		sign;
	long	stock;
	int		i;

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
		if (!(INT_MIN <= (stock * sign) && (stock * sign) <= INT_MAX))
			return (0);
		i++;
	}
	return (stock * sign);
}
