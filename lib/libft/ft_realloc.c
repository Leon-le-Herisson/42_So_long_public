/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:17:48 by linux-babas       #+#    #+#             */
/*   Updated: 2025/11/12 02:45:19 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Reallocates memory: grows/shrinks buffer to new size.
 * @param ptr Pointer to previous allocation.
 * @param size New size.
 */
void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;
	size_t	src_size;

	if (size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(size);
	if (!new_ptr)
		return (NULL);
	if (!ptr)
		return (new_ptr);
	src_size = ft_strlen(ptr);
	if (src_size < size)
		ft_memcpy(new_ptr, ptr, src_size);
	else
		ft_memcpy(new_ptr, ptr, size);
	free(ptr);
	return (new_ptr);
}
