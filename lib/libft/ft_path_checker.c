/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 16:10:51 by bamagere          #+#    #+#             */
/*   Updated: 2026/04/21 12:54:24 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Validates that a given path is usable (format, characters, etc.).
 * @param str Path string to check.
 * @note if open fail, then exit with failure status.
 */
void	ft_path_checker(char *str)
{
	int	fd_path;

	fd_path = open(str, O_RDONLY);
	if (fd_path <= 0)
	{
		ft_puts("Error\nA path format has gone wrong or doesn't exist.");
		close(fd_path);
		exit(EXIT_FAILURE);
	}
	close(fd_path);
}
