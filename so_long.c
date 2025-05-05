/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconde-s <mconde-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 21:15:57 by mconde-s          #+#    #+#             */
/*   Updated: 2025/05/03 16:09:16 by mconde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_ber(char *argv)
{
	int	len_argv;

	len_argv = ft_strlen(argv);
	if (argv[len_argv - 4] != '.' || argv[len_argv - 3] != 'b'
		|| argv[len_argv - 2] != 'e' || argv[len_argv - 1] != 'r')
		return (ft_printf("Error\n you need .ber\n"), 0);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_game		*game;
	t_graphics	*graphics;

	if (argc != 2)
		return (ft_printf("Error\n invalid number of arguments\n"), 0);
	if (!check_ber(argv[1]))
		return (0);
	game = malloc(sizeof(t_game));
	if (!game)
		return (0);
	graphics = malloc(sizeof(t_graphics));
	if (!graphics)
		return (0);
	*graphics = (t_graphics){0};
	*game = (t_game){0};
	game->graphics = graphics;
	check_open_textures(game);
	read_map(game, argv[1]);
	window(graphics, game);
	draw_map(graphics->mlx_game, game->graphics->window, game, graphics);
	mlx_hook(game->graphics->window, 17, 0, close_game, game);
	mlx_key_hook(game->graphics->window, ft_events, game);
	mlx_loop(graphics->mlx_game);
	return (0);
}
