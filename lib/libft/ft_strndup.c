/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamagere <bamagere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 20:38:05 by bamagere          #+#    #+#             */
/*   Updated: 2026/01/14 22:07:51 by bamagere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Allocates and returns the first n characters of a string.
 */
char	*ft_strndup(const char *s, size_t n)
{
	size_t	size;
	char	*new_s;

	size = ft_strlen(s);
	if (size > n)
		size = n;
	new_s = malloc(sizeof(char) * (size + 1));
	if (!new_s)
		return (NULL);
	ft_strncpy(new_s, s, size);
	new_s[size] = '\0';
	return (new_s);
}
