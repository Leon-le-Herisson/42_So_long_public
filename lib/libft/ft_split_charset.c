/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_charset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:39:09 by linux-babas       #+#    #+#             */
/*   Updated: 2025/11/12 02:45:00 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_charset(char c, const char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

/**
 * @brief Splits a string using a whole charset instead of a single delimiter.
 */
char	**ft_split_charset(char *str, const char *charset)
{
	char	**res;
	int		i;
	int		j;
	int		start;

	res = malloc(sizeof(char *) * (ft_strlen(str) + 1));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && is_charset(str[i], charset))
			i++;
		start = i;
		while (str[i] && !is_charset(str[i], charset))
			i++;
		if (i > start)
			res[j++] = ft_substr(str, start, i - start);
	}
	res[j] = NULL;
	return (res);
}
