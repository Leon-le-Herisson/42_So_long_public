/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamagere <bamagere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:19:25 by bamagere          #+#    #+#             */
/*   Updated: 2025/11/05 17:19:26 by bamagere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*temposrc;
	char	*tempodest;
	size_t	i;

	temposrc = (char *)src;
	tempodest = (char *)dest;
	i = 0;
	if (!dest && !src && n > 0)
		return (NULL);
	while (i < n)
	{
		tempodest[i] = temposrc[i];
		i++;
	}
	return (dest);
}
