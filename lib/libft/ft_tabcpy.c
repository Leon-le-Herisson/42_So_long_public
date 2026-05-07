/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 01:27:06 by linux-babas       #+#    #+#             */
/*   Updated: 2024/11/14 20:14:20 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* Copies the elements of an array into an other */

char	**ft_tabcpy(char **tab)
{
	char	**dest;
	size_t	i;

	i = 0;
	dest = malloc(sizeof(char *) * (ft_tabsize(tab) + 1));
	if (!dest)
		return (NULL);
	while (i < ft_tabsize(tab))
	{
		dest[i] = ft_strdup(tab[i]);
		if (!dest[i])
		{
			ft_free_tab(dest);
			return (NULL);
		}
		i++;
	}
	dest[i] = NULL;
	return (dest);
}
