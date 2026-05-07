/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts_rainbow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamagere <bamagere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:29:29 by bamagere          #+#    #+#             */
/*   Updated: 2026/01/06 12:43:05 by bamagere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putchar_color(char *color, char c)
{
	if (!color)
		return ;
	write(1, color, ft_strlen(color));
	write(1, &c, 1);
	write(1, "\033[0m", 4);
}

void	ft_puts_rainbow(char *phrase)
{
	char	*colors[6];
	int		i;

	if (!phrase || !phrase[0])
		return ;
	colors[0] = "\033[1;32m";
	colors[1] = "\033[1;33m";
	colors[2] = "\033[1;31m";
	colors[3] = "\033[1;35m";
	colors[4] = "\033[1;34m";
	colors[5] = "\033[1;36m";
	i = 0;
	while (*phrase)
	{
		ft_putchar_color(colors[i], *phrase);
		if (*phrase == ' ')
			i--;
		i++;
		if (i == 6)
			i = 0;
		phrase++;
	}
	write(1, "\033[0m\n", 5);
}
