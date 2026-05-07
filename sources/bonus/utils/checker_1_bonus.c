/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_1_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:17:23 by bamagere          #+#    #+#             */
/*   Updated: 2026/05/01 15:33:10 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	map_surroundings(t_mlx_data *data)
{
	get_dimensions(data);
	wall_x(data);
	wall_y(data);
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

void	map_numbers(t_mlx_data *data)
{
	if (data->game->nb_hero != 1 || data->game->nb_exit != 1
		|| data->game->nb_collectible <= 0)
	{
		ft_puts("Error\nSomething's wrong with the Map's characters");
		free_maps(data->game);
		exit(EXIT_FAILURE);
	}
	find_the_door(data);
}

bool	map_good_char(char *str, t_mlx_data *data)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'E')
			data->game->nb_exit++;
		else if (str[i] == 'C')
			data->game->nb_collectible++;
		else if (str[i] == 'P')
			data->game->nb_hero++;
		else if (str[i] == 'M')
			data->game->nb_monster++;
		else if (str[i] != '\n' && str[i] != '1' && str[i] != '0')
			return (false);
		i++;
	}
	while (i && str[--i] == '\n')
		str[i] = '\0';
	return (true);
}

void	runnable(t_mlx_data *data)
{
	bool	works;

	works = map_good_char(data->game->str_map, data);
	if (works == false)
	{
		ft_puts("Error\nThe map hasn't the good characters.");
		free(data->game->str_map);
		exit(EXIT_FAILURE);
	}
	data->game->map = ft_split(data->game->str_map, '\n');
	data->game->copy = ft_split(data->game->str_map, '\n');
	if (data->game->map == NULL || data->game->copy == NULL)
	{
		if (data->game->map)
			ft_free_tab(data->game->map);
		if (data->game->copy)
			ft_free_tab(data->game->copy);
		free(data->game->str_map);
		exit(EXIT_FAILURE);
	}
	free(data->game->str_map);
	map_error(data);
}
