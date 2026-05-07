/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strindex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 20:14:59 by linux-babas       #+#    #+#             */
/*   Updated: 2025/07/10 16:32:14 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* Finds the first occurrence of a substring in a string,
   returns the index of the beginning of the substring or -1 if not found */

int	ft_strindex(const char *haystack, const char *needle)
{
	char	*found;

	if (!haystack || !needle)
		return (-1);
	found = ft_strnstr((char *)haystack, needle, ft_strlen(haystack));
	if (!found)
		return (-1);
	return ((int)(found - haystack));
}
