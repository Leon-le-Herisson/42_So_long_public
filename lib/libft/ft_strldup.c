/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strldup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamagere <bamagere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:39:58 by bamagere          #+#    #+#             */
/*   Updated: 2026/01/14 22:07:51 by bamagere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Allocates and returns a substring between indexes start and end.
 */
char	*ft_strldup(const char *s, unsigned int start, unsigned int end)
{
	char	*new_s;
	int		i;
	int		size;

	if (!s || end <= start)
		return (NULL);
	size = end - start + 1;
	new_s = malloc(sizeof(char) * (size));
	if (!new_s)
		return (NULL);
	i = 0;
	while (start < end && s[start])
	{
		new_s[i] = (char)s[start];
		i++;
		start++;
	}
	new_s[i] = '\0';
	return (new_s);
}
