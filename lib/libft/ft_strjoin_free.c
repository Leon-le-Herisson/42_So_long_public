/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:18:43 by linux-babas       #+#    #+#             */
/*   Updated: 2025/11/12 02:44:04 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Joins s1 and s2 into a newly allocated string, 
 * optionally freeing inputs.
 * @param free_s1 If 1, frees s1.
 * @param free_s2 If 1, frees s2.
 */
char	*ft_strjoin_free(char *s1, char *s2, int free_s1, int free_s2)
{
	char	*new_s;
	size_t	len_new_s;

	if (!s1 && !s2)
		return (NULL);
	len_new_s = ft_strlen(s1) + ft_strlen(s2);
	new_s = malloc(len_new_s + 1);
	if (!new_s)
		return (NULL);
	if (s1)
		ft_strlcpy(new_s, s1, ft_strlen(s1) + 1);
	if (s2)
		ft_strlcat(new_s, s2, len_new_s + 1);
	if (free_s1 == 1)
		free(s1);
	if (free_s2 == 1)
		free(s2);
	return (new_s);
}
