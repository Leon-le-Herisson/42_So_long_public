/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamagere <bamagere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:36:01 by bamagere          #+#    #+#             */
/*   Updated: 2026/01/14 22:07:51 by bamagere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* Frees a table (array of pointers or strings) */

void	ft_free_tab(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!tab)
		return ;
	while (tab[j])
		j++;
	while (i < j)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
