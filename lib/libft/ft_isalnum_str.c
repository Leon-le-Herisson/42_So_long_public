/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:09:05 by linux-babas       #+#    #+#             */
/*   Updated: 2025/11/12 02:11:04 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Checks if every character of a string is alphanumeric.
 * @param s String to check.
 * @return int 1 if all characters are alphanumeric, 0 otherwise.
 */
int	ft_isalnum_str(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (('A' <= s[i] && s[i] <= 'Z') || ('a' <= s[i] && s[i] <= 'z')
			|| ('0' <= s[i] && s[i] <= '9'))
			i++;
		else
			return (0);
	}
	return (1);
}
