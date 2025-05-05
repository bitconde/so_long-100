/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconde-s <mconde-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:38:32 by mconde-s          #+#    #+#             */
/*   Updated: 2025/05/03 16:22:45 by mconde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_open_textures(t_game *game)
{
	int	fd;

	fd = open("./textures/player1.xpm", O_RDONLY);
	if (fd < 0)
		ft_error_with_free(game, "Error\n loading textures\n", 1, fd);
	fd = open("./textures/coin1.xpm", O_RDONLY);
	if (fd < 0)
		ft_error_with_free(game, "Error\n loading textures\n", 1, fd);
	fd = open("./textures/wall1.xpm", O_RDONLY);
	if (fd < 0)
		ft_error_with_free(game, "Error\n loading textures\n", 1, fd);
	fd = open("./textures/exit1.xpm", O_RDONLY);
	if (fd < 0)
		ft_error_with_free(game, "Error\n loading textures\n", 1, fd);
	fd = open("./textures/horcajo1.xpm", O_RDONLY);
	if (fd < 0)
		ft_error_with_free(game, "Error\n loading textures\n", 1, fd);
	fd = open("./textures/floor1.xpm", O_RDONLY);
	if (fd < 0)
		ft_error_with_free(game, "Error\n loading textures\n", 1, fd);
	fd = open("textures", O_RDONLY);
	if (fd < 0)
		ft_error_with_free(game, "Error\n loading textures\n", 1, fd);
	close(fd);
}

void	check_textures(t_graphics *graphics, t_game *game)
{
	if (!graphics->img_coin)
		ft_error_with_free(game, "Error\n loading textures\n", 1, -1);
	if (!graphics->img_player)
		ft_error_with_free(game, "Error\n loading textures\n", 1, -1);
	if (!graphics->img_wall)
		ft_error_with_free(game, "Error\n loading textures\n", 1, -1);
	if (!graphics->img_exit)
		ft_error_with_free(game, "Error\n loading textures\n", 1, -1);
	if (!graphics->img_exit2)
		ft_error_with_free(game, "Error\n loading textures\n", 1, -1);
	if (!graphics->img_floor)
		ft_error_with_free(game, "Error\n loading textures\n", 1, -1);
}

void	ft_clear_img(t_graphics *graphics)
{
	mlx_destroy_image(graphics->mlx_game, graphics->img_player);
	mlx_destroy_image(graphics->mlx_game, graphics->img_coin);
	mlx_destroy_image(graphics->mlx_game, graphics->img_wall);
	mlx_destroy_image(graphics->mlx_game, graphics->img_exit);
	mlx_destroy_image(graphics->mlx_game, graphics->img_exit2);
	mlx_destroy_image(graphics->mlx_game, graphics->img_floor);
}
