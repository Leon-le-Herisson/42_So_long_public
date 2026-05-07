/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamagere <bamagere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:21:31 by bamagere          #+#    #+#             */
/*   Updated: 2025/11/05 17:21:31 by bamagere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	lendst;
	size_t	lenmax;

	i = 0;
	if (size == 0 && !dst)
		return (ft_strlen(src));
	lendst = ft_strlen(dst);
	if (lendst >= size)
		return (ft_strlen(src) + size);
	lenmax = ft_strlen(src) + ft_strlen(dst);
	while (i + lendst < size - 1 && src[i] != '\0')
	{
		dst[i + lendst] = src[i];
		i++;
	}
	dst[i + lendst] = '\0';
	return (lenmax);
}
