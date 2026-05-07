/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:21:15 by bamagere          #+#    #+#             */
/*   Updated: 2025/11/12 02:36:03 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Allocates and returns a duplicate of the given string.
 */
char	*ft_strdup(const char *s)
{
	char	*new_s;
	int		i;
	int		size;

	size = ft_strlen(s) + 1;
	i = 0;
	new_s = malloc(sizeof(char) * (size));
	if (!new_s)
		return (NULL);
	while (s[i])
	{
		new_s[i] = (char)s[i];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}
