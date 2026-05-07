/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_whitespace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamagere <bamagere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:18:03 by bamagere          #+#    #+#             */
/*   Updated: 2026/01/14 22:07:51 by bamagere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Checks if a character is whitespace (spaces, tabs, etc.)
 *  or control char.
 * @param c The character to check.
 * @return bool true if whitespace, otherwise false.
 */
bool	ft_is_whitespace(char c)
{
	if (c == 32 || (9 <= c && c <= 13))
		return (true);
	return (false);
}
