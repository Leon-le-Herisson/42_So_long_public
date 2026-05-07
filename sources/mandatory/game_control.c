/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:31:54 by bamagere          #+#    #+#             */
/*   Updated: 2026/05/01 10:47:02 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	xpm_checker(void)
{
	ft_path_checker("./textures/manda/wall.xpm");
	ft_path_checker("./textures/manda/floor.xpm");
	ft_path_checker("./textures/manda/door_closed.xpm");
	ft_path_checker("./textures/manda/door_opened.xpm");
	ft_path_checker("./textures/manda/collectible.xpm");
	ft_path_checker("./textures/manda/hero_l.xpm");
	ft_path_checker("./textures/manda/hero_r.xpm");
	ft_path_checker("./textures/manda/hero_u.xpm");
}

void	map_checker(char *map_ber)
{
	int	fd;
	int	len;

	fd = open(map_ber, O_RDONLY);
	if (fd == -1)
	{
		ft_puts("Error\nCan't open map...");
		exit(EXIT_FAILURE);
	}
	close(fd);
	len = ft_strlen(map_ber);
	if (len < 4)
		exit(EXIT_FAILURE);
	if (map_ber[len - 4] != '.' || map_ber[len - 3] != 'b'
		|| map_ber[len - 2] != 'e' || map_ber[len - 1] != 'r')
	{
		ft_puts("Error\nWrong extension for the map.");
		exit(EXIT_FAILURE);
	}
}

void	map_lines(t_game *game)
{
	int	i;

	i = 0;
	while (game->str_map[i])
	{
		if (game->str_map[i] == '\n' && game->str_map[i + 1] == '\n')
		{
			free(game->str_map);
			ft_puts("Error\nSomething's wrong with the map.");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	map_error(t_game *game)
{
	map_surroundings(game);
	map_numbers(game);
	map_completable(game);
}

void	free_maps(t_game *game)
{
	if (game->map)
		ft_free_tab(game->map);
	if (game->copy)
		ft_free_tab(game->copy);
}
