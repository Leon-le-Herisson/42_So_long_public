/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:20:24 by bamagere          #+#    #+#             */
/*   Updated: 2026/05/01 12:27:08 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game		game;
	t_mlx_data	data;

	if (ac != 2)
	{
		ft_puts("Error\nSomething's wrong with the argument(s).");
		exit(EXIT_FAILURE);
	}
	ft_bzero(&game, sizeof(t_game));
	ft_bzero(&data, sizeof(t_mlx_data));
	xpm_checker();
	map_checker(av[1]);
	read_file(av[1], &game);
	runnable(&game);
	get_image(&game, &data);
	return (0);
}
