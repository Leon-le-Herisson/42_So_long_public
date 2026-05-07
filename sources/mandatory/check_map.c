/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:17:23 by bamagere          #+#    #+#             */
/*   Updated: 2026/05/01 15:33:34 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_surroundings(t_game *game)
{
	get_dimensions(game);
	wall_x(game);
	wall_y(game);
}

void	read_file(char *map_ber, t_game *game)
{
	int		fd_read;
	char	*buf;

	fd_read = open(map_ber, O_RDONLY);
	buf = get_next_line(fd_read);
	if (!buf)
	{
		ft_puts("Error\nThe current map is empty...");
		close(fd_read);
		exit(EXIT_FAILURE);
	}
	game->str_map = ft_calloc(sizeof(char), 1);
	if (!game->str_map)
	{
		close(fd_read);
		exit(EXIT_FAILURE);
	}
	while (buf)
	{
		game->str_map = ft_strjoin_free(game->str_map, buf, 1, 1);
		buf = get_next_line(fd_read);
	}
	close(fd_read);
	map_lines(game);
}

void	map_numbers(t_game *game)
{
	if (game->nb_hero != 1 || game->nb_exit != 1
		|| game->nb_collectible <= 0)
	{
		ft_puts("Error\nSomething's wrong with the Map's characters");
		free_maps(game);
		exit(EXIT_FAILURE);
	}
	find_the_door(game);
}

bool	map_good_char(char *str, t_game *game)
{
	int	i;

	i = 0;
	reset_counters(game);
	while (str[i])
	{
		if (str[i] == 'E')
			game->nb_exit++;
		else if (str[i] == 'C')
			game->nb_collectible++;
		else if (str[i] == 'P')
			game->nb_hero++;
		else if (str[i] != '\n' && str[i] != '1' && str[i] != '0')
			return (false);
		i++;
	}
	while (i && str[--i] == '\n')
		str[i] = '\0';
	return (true);
}

void	runnable(t_game *game)
{
	bool	works;

	works = map_good_char(game->str_map, game);
	if (works == false)
	{
		ft_puts("Error\nThe map hasn't the good characters.");
		free(game->str_map);
		exit(EXIT_FAILURE);
	}
	game->map = ft_split(game->str_map, '\n');
	game->copy = ft_split(game->str_map, '\n');
	if (game->map == NULL || game->copy == NULL)
	{
		free(game->map);
		free(game->copy);
		free(game->str_map);
		exit(EXIT_FAILURE);
	}
	free(game->str_map);
	map_error(game);
}
