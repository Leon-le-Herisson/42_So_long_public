/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:23:24 by bamagere          #+#    #+#             */
/*   Updated: 2026/05/05 12:35:52 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
/* ************************************************************************** */
/*                                  INCLUDES                                  */
/* ************************************************************************** */

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
# include <sys/time.h>

/* ************************************************************************** */
/*                                   MACROS                                   */
/* ************************************************************************** */

# define TILE 64
# define H_FRAME 4
# define M_FRAME 4
# define POWER_FRAME 7

# define MAX_WIN_W 1920
# define MAX_WIN_H 1080
# define VICTORY_WIN_W 1448
# define VICTORY_WIN_H 1086
# define LOSE_WIN_W 1444
# define LOSE_WIN_H 1089

# define HERO_DELAY 120
# define MONSTER_DELAY 150
# define CAST_DELAY 100
# define POWER_DELAY 80
# define END_DELAY 4000

# define BLA "\033[1;30m"
# define RED "\033[0;31m"
# define GRE "\033[0;32m"
# define YEL "\033[0;33m"
# define BLU "\033[0;34m"
# define MAG "\033[0;35m"
# define CYA "\033[0;36m"
# define NC "\033[0m"
# define B_R "\033[1;31m"
# define B_G "\033[1;32m"
# define B_Y "\033[1;33m"
# define B_M "\033[1;35m"
# define F_Y "\033[5;33m"
# define F_M "\033[5;35m"
# define F_C "\033[5;36m"

/* ************************************************************************** */
/*                                  STRUCTURES                                */
/* ************************************************************************** */

typedef struct s_m_pos
{
	int	sleep;
	int	x;
	int	y;
}	t_m_pos;

typedef struct s_step
{
	int	x;
	int	y;
}	t_step;

typedef struct s_bfs
{
	int		*dist;
	t_step	*queue;
	int		head;
	int		tail;
	int		size;
	int		next_dist;
}	t_bfs;

typedef struct s_best
{
	int	ox;
	int	oy;
	int	dx;
	int	dy;
	int	dist;
}	t_best;

typedef struct s_hud
{
	void	*digits[10];
}	t_hud;

typedef struct s_hero
{
	int		hero_posx;
	int		hero_posy;
	int		hero_dir_x;
	int		hero_dir_y;
	void	*hero_up[4];
	void	*hero_r[4];
	void	*hero_l[4];
	void	*hero_d[4];
	void	*power[7];
	void	*power_u[7];
	void	*power_l[7];
	void	*power_d[7];
	void	*power_r[7];
}	t_hero;

typedef struct s_monster
{
	void	*m_up[4];
}	t_monster;

typedef struct s_object
{
	void	*wall;
	void	*floor;
	void	*collectible;
	void	*exit_close;
	void	*exit_open;
	void	*frame;
	void	*victory;
	void	*lose;
}	t_object;

typedef struct s_power
{
	int		active;
	int		pending;
	int		x;
	int		y;
	int		dir_x;
	int		dir_y;
	int		frame;
	int		stop;
	int		next_active;
	int		next_x;
	int		next_y;
	int		next_frame;
}	t_power;

typedef struct s_game
{
	t_m_pos	*monster;
	t_power	power;
	char	*str_map;
	char	**map;
	char	**copy;
	int		width;
	int		height;
	int		moves;
	int		flag;
	int		nb_exit;
	int		nb_hero;
	int		nb_monster;
	int		nb_collectible;
	int		exit_posx;
	int		exit_posy;
}	t_game;

typedef struct s_mlx_data
{
	t_game		*game;
	t_hud		hud;
	t_hero		hero;
	t_monster	monster;
	t_object	object;
	int			hero_frame;
	int			monster_frame;
	int			hero_casting;
	int			hero_cast_frame;
	long		last_hero_time;
	long		last_monster_time;
	long		last_cast_time;
	long		last_power_time;
	int			end_screen;
	char		end_result;
	long		end_start;
	void		*mlx_ptr;
	void		*win_ptr;
	int			win_w;
	int			win_h;
	int			cam_x;
	int			cam_y;
	int			view_x0;
	int			view_y0;
	int			view_x1;
	int			view_y1;
	int			view_w;
	int			view_h;
}	t_mlx_data;

/* ************************************************************************** */
/*                              PARSING / CHECKING                            */
/* ************************************************************************** */

/* utils/game_control_bonus.c */
void	xpm_checker(void);
void	map_checker(char *extension);
void	map_lines(t_game *game);
void	map_error(t_mlx_data *data);
void	free_maps(t_game *game);

/* utils/checker_1_bonus.c */
void	map_surroundings(t_mlx_data *data);
void	read_file(char *map_ber, t_game *game);
void	map_numbers(t_mlx_data *data);
bool	map_good_char(char *str, t_mlx_data *data);
void	runnable(t_mlx_data *data);

/* utils/checker_2_bonus.c */
void	get_dimensions(t_mlx_data *data);
void	wall_x(t_mlx_data *data);
void	wall_y(t_mlx_data *data);
void	map_completable(t_mlx_data *data);

/* utils/checker_3_bonus.c */
void	xpm_checker_1(void);
void	xpm_checker_2(void);

/* utils/flood_fill_bonus.c */
void	flood_fill(t_mlx_data *data);
bool	call_flood_fill(int *p, t_mlx_data *data);
void	find_the_door(t_mlx_data *data);
void	find_the_monster(t_mlx_data *data);

/* images/images_loader_4_bonus.c */
void	image_load_error(t_mlx_data *data, char *msg);
void	check_image_tab(t_mlx_data *data, void **tab, int size, char *msg);

/* ************************************************************************** */
/*                                GAME RULES                                  */
/* ************************************************************************** */

/* utils/game_rules_bonus.c */
bool	monster_win(t_mlx_data *data);
bool	game_completion(t_mlx_data *data);
void	game_won(t_game *game, t_mlx_data *data, char answer);
void	destroy_images(t_mlx_data *data);

/* utils/handle_input_bonus.c */
int		handle_input(int keysym, void *param);
int		handle_close(void *param);

/* ************************************************************************** */
/*                              IMAGE DESTROYERS                              */
/* ************************************************************************** */

/* images/images_destroy_1_bonus.c */
void	safe_destroy_image(t_mlx_data *data, void **img);
void	destroy_hud(t_mlx_data *data);
void	destroy_hero(t_mlx_data *data);
void	destroy_monster(t_mlx_data *data);
void	destroy_objects(t_mlx_data *data);

/* images/images_destroy_2_bonus.c */
void	destroy_powers(t_mlx_data *data);

/* ************************************************************************** */
/*                               IMAGE LOADERS                                */
/* ************************************************************************** */

/* images/images_loader_1_bonus.c */
void	download_images(t_mlx_data *data);
void	*load_image(t_mlx_data *data, char *path);
void	load_hud(t_mlx_data *data);
void	load_monster(t_mlx_data *data);
void	load_objects(t_mlx_data *data);

/* images/images_loader_2_bonus.c */
void	load_power(t_mlx_data *data);
void	load_power_u(t_mlx_data *data);
void	load_power_l(t_mlx_data *data);
void	load_power_d(t_mlx_data *data);
void	load_power_r(t_mlx_data *data);

/* images/images_loader_3_bonus.c */
void	load_hero(t_mlx_data *data);

/* images/images_loader_4_bonus.c */
void	load_end_images(t_mlx_data *data);

/* ************************************************************************** */
/*                                  MOVES                                     */
/* ************************************************************************** */

/* moves/moves_basic_bonus.c */
void	move_up(t_mlx_data *data);
void	move_down(t_mlx_data *data);
void	move_left(t_mlx_data *data);
void	move_right(t_mlx_data *data);

/* moves/moves_power_1_bonus.c */
void	love_power(t_mlx_data *data);

/* moves/moves_power_2_bonus.c */
void	idle_anim_hero(t_mlx_data *data);
int		is_wall_tile(t_mlx_data *data, int x, int y);
int		is_monster_tile(t_mlx_data *data, int x, int y);
void	decrement_monster_sleep(t_mlx_data *data);
void	sleep_beauty(t_mlx_data *data, int x, int y);
void	idle_animation_power(t_mlx_data *data);

/* moves/moves_monsters_1_bonus.c */
int		bfs_index(t_mlx_data *data, int x, int y);
int		monster_on_tile(t_mlx_data *data, int x, int y, int self);
int		monster_tile_blocked(t_mlx_data *data, int x, int y, int self);
int		init_bfs(t_mlx_data *data, t_bfs *bfs);

/* moves/moves_monsters_2_bonus.c */
void	clear_bfs(t_bfs *bfs);
void	fill_bfs(t_mlx_data *data, t_bfs *bfs);
t_step	get_bfs_step(t_mlx_data *data, t_bfs *bfs, int x, int y);

/* moves/moves_monsters_3_bonus.c */
void	move_monsters(t_mlx_data *data);

/* moves/moves_monsters_4_bonus.c */
t_step	get_patrol_step(t_mlx_data *data, int i);

/* ************************************************************************** */
/*                                  WINDOW                                    */
/* ************************************************************************** */

/* window/window_1_init_bonus.c */
void	draw_all(t_mlx_data *data);
void	get_image(t_mlx_data *data);

/* window/window_2_update_bonus.c */
void	update_camera(t_mlx_data *data);

/* window/window_3_utils_bonus.c */
int		clamp_window_size(int map_size, int screen_size, int max_size);
void	set_window_size(t_mlx_data *data);
void	free_before_mlx_exit(t_mlx_data *data);

/* window/window_4_end_bonus.c */
void	start_end_screen(t_mlx_data *data, char result);
void	draw_end_screen(t_mlx_data *data);
void	end_game_after_delay(t_mlx_data *data);

/* ************************************************************************** */
/*                                  DRAWING                                   */
/* ************************************************************************** */

/* window/windraw_1_features_1_bonus.c */
void	draw_tile(t_mlx_data *data, int x, int y);
void	draw_monsters(t_mlx_data *data);
void	draw_hero(t_mlx_data *data);
void	draw_world(t_mlx_data *data);
void	draw_exit(t_mlx_data *data);

/* window/windraw_1_features_2_bonus.c */
void	draw_power(t_mlx_data *data);

/* window/windraw_2_border_bonus.c */
void	draw_border(t_mlx_data *data);

/* window/windraw_3_hud_bonus.c */
void	draw_hud(t_mlx_data *data);

/* ************************************************************************** */
/*                                ANIMATIONS                                  */
/* ************************************************************************** */

/* utils/animation_1_bonus.c */
int		idle_anim_hook(void *param);
void	what_monster_image(t_mlx_data *data, int x, int y, int sleep);
void	what_hero_image(t_mlx_data *data, int x, int y);

/* utils/time_utils_bonus.c */
long	get_time_ms(void);

/* utils/animation_2_bonus.c */
int		update_hero_anim(t_mlx_data *data, long now);
int		update_monster_anim(t_mlx_data *data, long now);
void	start_pending_power(t_mlx_data *data);
int		update_cast_anim(t_mlx_data *data, long now);
int		update_power_anim(t_mlx_data *data, long now);

#endif