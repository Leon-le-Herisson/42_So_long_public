/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:18:16 by bamagere          #+#    #+#             */
/*   Updated: 2025/11/08 00:25:15 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size_s_itoa(int n)
{
	int	lenght;

	lenght = 0;
	while (n > 0)
	{
		n /= 10;
		lenght++;
	}
	return (lenght);
}

static char	*max_values(int n)
{
	char	*dst;

	if (n == -2147483648)
	{
		dst = ft_strdup("-2147483648");
		return (dst);
	}
	if (n == 0)
	{
		dst = ft_strdup("0");
		return (dst);
	}
	return (NULL);
}

/**
 * @brief Allocates and returns a string representing the integer given.
 * @param n The integer to convert.
 * @return char* Newly allocated numeric string, or NULL if allocation fails.
 */
char	*ft_itoa(int n)
{
	char	*s_itoa;
	int		sign;
	int		size;

	if (n == -2147483648 || n == 0)
		return (max_values(n));
	sign = 0;
	if (n < 0)
	{
		n *= -1;
		sign++;
	}
	size = size_s_itoa(n) + sign;
	s_itoa = malloc(sizeof(char) * (size + 1));
	if (!s_itoa)
		return (NULL);
	s_itoa[size--] = '\0';
	while (n > 0)
	{
		s_itoa[size--] = ((n % 10) + 48);
		n /= 10;
	}
	if (sign == 1)
		s_itoa[size] = '-';
	return (s_itoa);
}
