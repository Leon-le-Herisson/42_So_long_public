/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamagere <bamagere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:29:29 by bamagere          #+#    #+#             */
/*   Updated: 2026/01/06 11:44:30 by bamagere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../printfs/my_printfs.h"

void	ft_puts_color(char *color, char *phrase)
{
	if (!color || !color[0])
		ft_puts(phrase);
	else if (!phrase || !phrase[0])
		return ;
	else
		ft_printf("%s%s\n", color, phrase);
}
