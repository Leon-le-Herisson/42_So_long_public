/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:21:35 by bamagere          #+#    #+#             */
/*   Updated: 2025/11/12 02:17:45 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Copies up to size - 1 characters from src to dest and null-terminates.
 * @param dest Destination buffer.
 * @param src Source string.
 * @param size Size of the destination buffer.
 * @return size_t Length of src.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	int		lensrc;

	lensrc = ft_strlen(src);
	i = 0;
	if (!dst || !src)
		return (0);
	if (size == 0)
		return (lensrc);
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (lensrc);
}
