/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconde-s <mconde-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:58:45 by mconde-s          #+#    #+#             */
/*   Updated: 2025/05/03 16:36:51 by mconde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include "./ft_printf/ft_printf.h"
# include "./get_next_line/get_next_line.h"
# include "./minilibx-linux/mlx.h"
# include "./minilibx-linux/mlx_int.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/stat.h>
# include <unistd.h>

# define TITLE_SIZE 64

typedef struct s_graphics
{
	int			x;
	int			y;
	int			x_2;
	int			y_2;
	void		*mlx_game;
	int			move;
	int			is_exit;
	void		*window;
	void		*img_player;
	void		*img_wall;
	void		*img_coin;
	void		*img_floor;
	void		*img_exit;
	void		*img_exit2;
	char		current_tile;
	char		*current_tile2;
	void		*current_img2;
	void		*current_img;
}				t_graphics;

typedef struct s_game
{
	int			fd;
	int			flag;
	int			flag_exit;
	char		*read_line;
	char		*len_line;
	int			x;
	int			y;
	int			player;
	int			exit;
	int			wall;
	int			i;
	int			*count_coins;
	int			way;
	int			num_coin;
	int			win;
	int			len_cols;
	int			cols;
	int			rows;
	int			hola;
	int			player_x;
	int			player_y;
	char		**map;
	char		**dup_map;
	t_graphics	*graphics;
}				t_game;

int				check_ber(char *argv);
void			read_map(t_game *game, char *map);
void			is_rectangle(t_game *game, char *map, int fd);
void			ft_error_with_free(t_game *game, char *str, int i, int fd);
void			flood_fill(t_game *game);
void			fill(t_game *game, char **map, int x, int y);
int				check_sides(t_game *game);
void			valid_caracteres(t_game *game);
void			is_player(t_game *game);
void			check_characters(t_game *game);
char			**dup_map(t_game *game);

// graphics

void			window(t_graphics *graphics, t_game *game);
void			img(t_graphics *graphics);
void			draw_map(void *mlx, void *window, t_game *game,
					t_graphics *graphics);
void			check_textures(t_graphics *graphics, t_game *game);
void			check_open_textures(t_game *game);
void			ft_clear_img(t_graphics *graphics);

// events

int				ft_events(int key, t_game *game);
int				ft_win(t_game *game);
int				close_game(t_game *game);

// keys

void			key_right(t_game *game);
void			key_left(t_game *game);
void			key_up(t_game *game);
void			key_down(t_game *game);

#endif