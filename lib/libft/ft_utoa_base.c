/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamagere <bamagere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 12:55:17 by bamagere          #+#    #+#             */
/*   Updated: 2026/01/06 12:55:53 by bamagere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_utoa_base(unsigned long n, int base, int upper)
{
	char	buf[65];
	char	*tab;
	char	*tmp;
	int		i;

	tab = "0123456789abcdef";
	if (upper)
		tab = "0123456789ABCDEF";
	i = 64;
	buf[i] = '\0';
	if (n == 0)
	{
		buf[--i] = '0';
		tmp = ft_strdup(&buf[i]);
		return (tmp);
	}
	while (n != 0)
	{
		buf[--i] = tab[n % (unsigned long)base];
		n = n / (unsigned long)base;
	}
	tmp = ft_strdup(&buf[i]);
	return (tmp);
}
