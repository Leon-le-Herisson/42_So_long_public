/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:21:27 by bamagere          #+#    #+#             */
/*   Updated: 2025/11/12 02:43:06 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Allocates and returns a new string that
 *  is the concatenation of s1 and s2.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_new_s;
	size_t	i;
	size_t	j;
	size_t	k;
	char	*new_s;

	if (!s1 || !s2)
		return (NULL);
	len_new_s = ft_strlen(s1) + ft_strlen(s2);
	new_s = malloc(sizeof(char) * (len_new_s + 1));
	if (!new_s)
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	while (k < len_new_s)
	{
		while (s1[i])
			new_s[k++] = s1[i++];
		while (s2[j])
			new_s[k++] = s2[j++];
	}
	new_s[k] = '\0';
	return (new_s);
}
