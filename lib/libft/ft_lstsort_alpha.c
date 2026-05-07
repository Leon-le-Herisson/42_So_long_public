/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort_alpha.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:01:34 by mewormse          #+#    #+#             */
/*   Updated: 2024/10/28 17:08:31 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstsort_alpha(t_list *lst)
{
	t_list	*i;
	t_list	*j;
	char	*temp;

	if (!lst)
		return (NULL);
	i = lst;
	while (i->next)
	{
		j = i->next;
		while (j)
		{
			if (ft_strcmp((char *)i->content, (char *)j->content) > 0)
			{
				temp = i->content;
				i->content = j->content;
				j->content = temp;
			}
			j = j->next;
		}
		i = i->next;
	}
	return (lst);
}
