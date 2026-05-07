/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:19:41 by linux-babas       #+#    #+#             */
/*   Updated: 2025/12/05 17:27:52 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_printfs.h"
/* Takes a char **tab and print it on std output */

void	ft_print_tab(char **src)
{
	size_t	i;

	i = 0;
	if (!src)
		return ;
	fd_printf(1, "\033[1;34m""Start of tab\n""\033[0m");
	while (i < ft_tabsize(src))
	{
		fd_printf(1, "line[%d] =\t\t~|%s|~\n", i, src[i]);
		i++;
	}
	fd_printf(1, "\033[1;34m""End of tab""\033[0m");
	fd_printf(1, "\033[1;36m"" <--> Size of tab is %d\n\n""\033[0m",
		ft_tabsize(src));
}
