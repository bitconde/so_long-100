/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconde-s <mconde-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 21:21:52 by mconde-s          #+#    #+#             */
/*   Updated: 2025/05/03 15:56:27 by mconde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_game(t_game *game)
{
	mlx_destroy_window(game->graphics->mlx_game, game->graphics->window);
	ft_clear_img(game->graphics);
	mlx_destroy_display(game->graphics->mlx_game);
	free(game->graphics->mlx_game);
	if (game->flag == 0)
		ft_error_with_free(game, "\nYou close the game\n", 1, 0);
	return (0);
}

int	ft_win(t_game *game)
{
	if (game->map[game->player_y][game->player_x] == 'E')
		return (1);
	return (0);
}

int	ft_events(int key, t_game *game)
{
	if (key == 65363 || key == 100)
		key_right(game);
	if (key == 65361 || key == 97)
		key_left(game);
	if (key == 65364 || key == 115)
		key_down(game);
	if (key == 65362 || key == 119)
		key_up(game);
	if (key == 65307)
		close_game(game);
	draw_map(game->graphics->mlx_game, game->graphics->window, game,
		game->graphics);
	if (game->num_coin == 0)
	{
		game->flag_exit = 1;
		if (game->win == 1)
		{
			game->flag = 1;
			close_game(game);
			ft_error_with_free(game, "\n!!!!YOU WIN!!!!\n", 0, 0);
		}
	}
	return (key);
}
