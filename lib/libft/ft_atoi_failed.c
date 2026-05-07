/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_failed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamagere <bamagere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 19:05:26 by bamagere          #+#    #+#             */
/*   Updated: 2026/01/14 22:07:51 by bamagere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief A variant of ft_atoi that handles conversion failures.
 * @brief Converts a string to an int while checking for conversion errors.
 * @param s The string to convert.
 * @param nb The resulting value after conversion.
 * @return bool true if conversion failed, false otherwise.
 */
bool	ft_atoi_failed(const char *s, int nb)
{
	int	i;

	i = 0;
	if (nb)
		return (false);
	while ((9 <= s[i] && s[i] <= 13) || s[i] == ' ')
		i++;
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (!s[i])
		return (true);
	while (s[i] == '0')
		i++;
	if (s[i])
		return (true);
	return (false);
}
