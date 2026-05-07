/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:22:11 by bamagere          #+#    #+#             */
/*   Updated: 2025/11/12 02:43:40 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_len(char const *s, unsigned int start, size_t len)
{
	size_t	count;

	count = 0;
	while (s[start++] && count < len)
		count++;
	return (count);
}

/**
 * @brief Returns a substring from index start of length len (allocated).
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_s;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		new_s = malloc(sizeof(char) * 1);
		if (!new_s)
			return (NULL);
		new_s[0] = 0;
		return (new_s);
	}
	new_s = malloc(sizeof(char) * (get_len(s, start, len) + 1));
	if (!new_s)
		return (NULL);
	i = 0;
	while (s[start] && i < len)
		new_s[i++] = s[start++];
	new_s[i] = '\0';
	return (new_s);
}
