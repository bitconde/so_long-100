/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconde-s <mconde-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 21:16:02 by mconde-s          #+#    #+#             */
/*   Updated: 2025/05/03 16:15:12 by mconde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(t_game *game, char *map)
{
	is_rectangle(game, map, game->fd);
	game->fd = open(map, O_RDONLY);
	if (game->fd < 0)
		ft_error_with_free(game, "Error\n Opening map\n", 1, game->fd);
	game->map = malloc((game->rows + 1) * sizeof(char *));
	game->read_line = get_next_line(game->fd, 0);
	if (!game->map)
		ft_error_with_free(game, "Error\n Memory allocation failed\n", 1,
			game->fd);
	while (game->read_line)
	{
		game->map[game->y] = game->read_line;
		game->y++;
		game->read_line = get_next_line(game->fd, 0);
	}
	game->map[game->y] = NULL;
	if (!game->map)
		ft_error_with_free(game, "Error\n Memory allocation failed\n", 1,
			game->fd);
	if (!check_sides(game))
		ft_error_with_free(game, "Error\n Invalid map\n", 1, game->fd);
	close(game->fd);
	valid_caracteres(game);
	is_player(game);
	flood_fill(game);
}

void	is_rectangle(t_game *game, char *map, int fd)
{
	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_error_with_free(game, "Error\n Opening map\n", 1, fd);
	game->len_line = get_next_line(fd, 0);
	if (!game->len_line)
		ft_error_with_free(game, "Error\n It is not rectangular\n", 1, fd);
	game->cols = ft_strlen(game->len_line);
	if (game->cols > 0 && game->len_line[game->cols - 1] == '\n')
		game->len_line[--game->cols] = '\0';
	game->rows = 1;
	free(game->len_line);
	while (1)
	{
		game->len_line = get_next_line(fd, 0);
		if (!game->len_line)
			break ;
		game->len_cols = ft_strlen(game->len_line);
		if (game->len_cols > 0 && game->len_line[game->len_cols - 1] == '\n')
			game->len_line[--game->len_cols] = '\0';
		if (game->cols != game->len_cols)
			ft_error_with_free(game, "Error\n It is not rectangular\n", 1, fd);
		free(game->len_line);
		game->rows++;
	}
	close(fd);
}

void	fill(t_game *game, char **map, int x, int y)
{
	if (x < 0 || x >= game->cols || y < 0 || y >= game->rows)
		ft_error_with_free(game, "Error\n Out of limits\n", 1, 0);
	if (map[y][x] == 'E')
		map[y][x] = 'e';
	if (map[y][x] == 'F' || map[y][x] == '1' || map[y][x] == 'e')
		return ;
	map[y][x] = 'F';
	fill(game, map, x + 1, y);
	fill(game, map, x - 1, y);
	fill(game, map, x, y + 1);
	fill(game, map, x, y - 1);
}

void	flood_fill(t_game *game)
{
	char	**map;
	int		i;
	int		j;

	j = -1;
	i = 0;
	map = dup_map(game);
	if (map[game->player_y][game->player_x] == 'F')
		return ;
	fill(game, map, game->player_x, game->player_y);
	while (map[i])
	{
		if (ft_strchr(map[i], 'C') || ft_strchr(map[i], 'E'))
			ft_error_with_free(game, "Error\n Not playable\n", 1, -1);
		i++;
	}
}
