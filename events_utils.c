/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconde-s <mconde-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 12:14:01 by mconde-s          #+#    #+#             */
/*   Updated: 2025/05/03 15:55:31 by mconde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_right(t_game *game)
{
	if (game->map[game->player_y][game->player_x + 1] != '1')
	{
		if (game->map[game->player_y][game->player_x + 1] != 'E'
			|| game->flag_exit == 1)
		{
			game->map[game->player_y][game->player_x] = '0';
			if (game->map[game->player_y][game->player_x + 1] == 'C')
				game->num_coin--;
			game->player_x++;
			game->win = ft_win(game);
			game->map[game->player_y][game->player_x] = 'P';
			game->graphics->move++;
			ft_printf("Move: %d\n", game->graphics->move);
		}
	}
}

void	key_left(t_game *game)
{
	if (game->map[game->player_y][game->player_x - 1] != '1')
	{
		if (game->map[game->player_y][game->player_x - 1] != 'E'
			|| game->flag_exit == 1)
		{
			game->map[game->player_y][game->player_x] = '0';
			if (game->map[game->player_y][game->player_x - 1] == 'C')
				game->num_coin--;
			game->player_x--;
			game->win = ft_win(game);
			game->map[game->player_y][game->player_x] = 'P';
			game->graphics->move++;
			ft_printf("Move: %d\n", game->graphics->move);
		}
	}
}

void	key_down(t_game *game)
{
	if (game->map[game->player_y + 1][game->player_x] != '1')
	{
		if (game->map[game->player_y + 1][game->player_x] != 'E'
			|| game->flag_exit == 1)
		{
			game->map[game->player_y][game->player_x] = '0';
			if (game->map[game->player_y + 1][game->player_x] == 'C')
				game->num_coin--;
			game->player_y++;
			game->win = ft_win(game);
			game->map[game->player_y][game->player_x] = 'P';
			game->graphics->move++;
			ft_printf("Move: %d\n", game->graphics->move);
		}
	}
}

void	key_up(t_game *game)
{
	if (game->map[game->player_y - 1][game->player_x] != '1')
	{
		if (game->map[game->player_y - 1][game->player_x] != 'E'
			|| game->flag_exit == 1)
		{
			game->map[game->player_y][game->player_x] = '0';
			if (game->map[game->player_y - 1][game->player_x] == 'C')
				game->num_coin--;
			game->player_y--;
			game->win = ft_win(game);
			game->map[game->player_y][game->player_x] = 'P';
			game->graphics->move++;
			ft_printf("Move: %d\n", game->graphics->move);
		}
	}
}
