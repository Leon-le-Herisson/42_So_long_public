/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_tabdup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 21:04:09 by linux-babas       #+#    #+#             */
/*   Updated: 2024/11/16 16:05:27 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* Copies the elements of a linked list into an array */

char	**ft_lst_tabdup(t_list *src)
{
	char	**dest;
	int		lstsize;
	int		i;

	i = 0;
	lstsize = ft_lstsize(src);
	dest = malloc(sizeof(char *) * (lstsize + 1));
	if (!dest)
		return (NULL);
	while (src)
	{
		dest[i] = ft_strdup((char *)src->content);
		if (!dest[i])
		{
			while (i-- > 0)
				free(dest[i]);
			free(dest);
			return (NULL);
		}
		src = src->next;
		i++;
	}
	dest[i] = NULL;
	return (dest);
}
