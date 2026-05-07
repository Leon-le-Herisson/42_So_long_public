/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:23:24 by bamagere          #+#    #+#             */
/*   Updated: 2026/05/05 12:35:52 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/libft/libft.h"
# include "../lib/gnl/get_next_line_bonus.h"
# include "../lib/printfs/my_printfs.h"
# include "../minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>

# define TILE 64

/* structures */
typedef struct s_game
{
	char	*str_map;
	char	**map;
	char	**copy;
	int		width;
	int		height;
	int		moves;
	int		nb_hero;
	int		nb_collectible;
	int		nb_exit;
	int		hero_posx;
	int		hero_posy;
	int		exit_posx;
	int		exit_posy;
	int		flag;
}	t_game;

typedef struct s_mlx_data
{
	t_game	*game;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*wall;
	void	*floor;
	void	*collectible;
	void	*exit_close;
	void	*exit_open;
	void	*hero_look_up;
	void	*hero_look_right;
	void	*hero_look_left;
}	t_mlx_data;

/* game_control.c */
void	xpm_checker(void);
void	map_checker(char *extension);
void	map_lines(t_game *game);
void	map_error(t_game *game);
void	free_maps(t_game *game);

/* check_map.c */
void	map_surroundings(t_game *game);
void	read_file(char *map_ber, t_game *game);
void	map_numbers(t_game *game);
bool	map_good_char(char *str, t_game *game);
void	runnable(t_game *game);

/* check_map_utils.c */
void	reset_counters(t_game *game);
void	get_dimensions(t_game *game);
void	wall_x(t_game *game);
void	wall_y(t_game *game);
void	map_completable(t_game *game);

/* check_map_utils_two.c */
void	flood_fill(t_game *game);
bool	call_flood_fill(int *p, t_game *game);
void	find_the_door(t_game *game);

/* window_draw.c */
void	draw_exit(t_game *game, t_mlx_data *data);
void	draw_line(t_game *game, t_mlx_data *data);
/* window_utils.c */
void	*load_image(t_mlx_data *data, char *path);
void	image_load_error(t_mlx_data *data);
void	select_image(t_mlx_data *data);
void	get_image(t_game *game, t_mlx_data *data);

/* game_utils.c */
bool	game_completion(t_game *game);
void	game_won(t_game *game, t_mlx_data *data, char answer);
void	destroy_images(t_mlx_data *data);
int		handle_input(int keysym, void *param);
int		handle_close(void *param);

/* moves.c */
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	what_hero_image(t_game *game, t_mlx_data *data, int x, int y);

#endif
