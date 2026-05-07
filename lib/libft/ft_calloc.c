/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:17:39 by bamagere          #+#    #+#             */
/*   Updated: 2025/11/12 02:16:45 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Allocates memory for nmemb elements of size bytes, initialized to zero.
 * @param nmemb (size_t) number of elements.
 * @param size (size_t) size of the elements.
 * @return void* Pointer to allocated memory, or NULL if allocation fails.
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*s_calloc;

	if ((long int)(nmemb * size) < 0 || ((int)nmemb < 0 && (int)size < 0))
		return (NULL);
	s_calloc = malloc(nmemb * size);
	if (!s_calloc)
		return (NULL);
	ft_bzero(s_calloc, (nmemb * size));
	return (s_calloc);
}
