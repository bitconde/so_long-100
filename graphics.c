/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconde-s <mconde-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 21:15:53 by mconde-s          #+#    #+#             */
/*   Updated: 2025/05/02 18:49:13 by mconde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img(t_graphics *graphics)
{
	int	img_width;
	int	img_height;

	graphics->img_player = mlx_xpm_file_to_image(graphics->mlx_game,
			"./textures/player1.xpm", &img_width, &img_height);
	graphics->img_coin = mlx_xpm_file_to_image(graphics->mlx_game,
			"./textures/coin1.xpm", &img_width, &img_height);
	graphics->img_wall = mlx_xpm_file_to_image(graphics->mlx_game,
			"./textures/wall1.xpm", &img_width, &img_height);
	graphics->img_exit = mlx_xpm_file_to_image(graphics->mlx_game,
			"./textures/horcajo1.xpm", &img_width, &img_height);
	graphics->img_exit2 = mlx_xpm_file_to_image(graphics->mlx_game,
			"./textures/exit1.xpm", &img_width, &img_height);
	graphics->img_floor = mlx_xpm_file_to_image(graphics->mlx_game,
			"./textures/floor1.xpm", &img_width, &img_height);
}

void	window(t_graphics *graphics, t_game *game)
{
	int		len_x;
	int		len_y;
	void	*window;

	graphics->mlx_game = NULL;
	window = NULL;
	graphics->mlx_game = mlx_init();
	len_x = TITLE_SIZE * game->cols;
	len_y = TITLE_SIZE * game->rows;
	window = mlx_new_window(graphics->mlx_game, len_x, len_y, "so_long");
	img(graphics);
	check_textures(graphics, game);
	graphics->window = window;
}

void	draw_map(void *mlx, void *window, t_game *game, t_graphics *graphics)
{
	graphics->y = -1;
	while (++graphics->y < game->rows)
	{
		graphics->x = -1;
		while (++graphics->x < game->cols)
		{
			graphics->current_tile = game->map[graphics->y][graphics->x];
			graphics->current_img = NULL;
			if (graphics->current_tile == '1')
				graphics->current_img = graphics->img_wall;
			else if (graphics->current_tile == 'P')
				graphics->current_img = graphics->img_player;
			else if (graphics->current_tile == 'E' && game->num_coin == 0)
				graphics->current_img = graphics->img_exit2;
			else if (graphics->current_tile == 'E')
				graphics->current_img = graphics->img_exit;
			else if (graphics->current_tile == 'C')
				graphics->current_img = graphics->img_coin;
			else if (graphics->current_tile == '0')
				graphics->current_img = graphics->img_floor;
			mlx_put_image_to_window(mlx, window, graphics->current_img,
				graphics->x * TITLE_SIZE, graphics->y * TITLE_SIZE);
		}
	}
}
