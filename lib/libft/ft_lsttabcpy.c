/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttabcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamagere <bamagere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:42:43 by bamagere          #+#    #+#             */
/*   Updated: 2026/01/14 22:07:51 by bamagere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* Copies the elements of an array into a linked list */

t_list	*ft_lsttabcpy(char **tab)
{
	t_list	*lst;
	size_t	i;
	size_t	tabsize;

	i = 1;
	tabsize = ft_tabsize(tab);
	lst = ft_lstnew(ft_strdup(tab[0]));
	while (i < tabsize)
		ft_lstadd_back(&lst, ft_lstnew(ft_strdup(tab[i++])));
	return (lst);
}
