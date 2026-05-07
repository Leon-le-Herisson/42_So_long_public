/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_printf_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 09:37:21 by linux-babas       #+#    #+#             */
/*   Updated: 2025/12/05 17:27:40 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_printfs.h"

void	fd_printf_lst(int fd, t_list *lst)
{
	t_list	*it;

	it = lst;
	while (it)
	{
		fd_printf(fd, "lst = %s\n", (char *)it->content);
		it = it->next;
	}
}
