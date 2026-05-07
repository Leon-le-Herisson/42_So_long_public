/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:20:24 by bamagere          #+#    #+#             */
/*   Updated: 2026/04/23 13:14:44 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	init_monster(t_mlx_data *data)
{
	data->game->monster = NULL;
	if (data->game->nb_monster <= 0)
		return ;
	data->game->monster = malloc(sizeof(t_m_pos)
			* data->game->nb_monster);
	if (!data->game->monster)
	{
		ft_puts("Error\nMalloc failed at init_monster");
		free_maps(data->game);
		exit(EXIT_FAILURE);
	}
	ft_bzero(data->game->monster,
		sizeof(t_m_pos) * data->game->nb_monster);
	find_the_monster(data);
}

static void	init_struct(t_mlx_data *data, t_game *game)
{
	ft_bzero(game, sizeof(t_game));
	data->game = game;
}

static void	init_hero_direction(t_mlx_data *data)
{
	data->game->flag = 3;
	data->hero.hero_dir_x = 0;
	data->hero.hero_dir_y = 1;
}

int	main(int ac, char **av)
{
	t_game		game;
	t_mlx_data	data;

	if (ac != 2)
	{
		ft_puts("Error\nSomething's wrong with the argument(s).");
		exit(EXIT_FAILURE);
	}
	ft_bzero(&data, sizeof(t_mlx_data));
	init_struct(&data, &game);
	xpm_checker();
	map_checker(av[1]);
	read_file(av[1], &game);
	runnable(&data);
	init_monster(&data);
	init_hero_direction(&data);
	ft_printf("%sScore : %s%d\n", YEL, NC, data.game->moves);
	get_image(&data);
	return (0);
}
