/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconde-s <mconde-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:47:43 by mconde-s          #+#    #+#             */
/*   Updated: 2025/05/03 16:19:56 by mconde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_player(t_game *game)
{
	int	rows;
	int	cols;

	rows = 0;
	cols = 0;
	while (game->map[rows])
	{
		cols = 0;
		while (game->map[rows][cols])
		{
			if (game->map[rows][cols] == 'P')
			{
				game->player_y = rows;
				game->player_x = cols;
				return ;
			}
			cols++;
		}
		rows++;
	}
}

int	check_sides(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->rows)
	{
		if (i == 0 || i == game->rows - 1)
		{
			j = 0;
			while (j < game->cols)
			{
				if (game->map[i][j] != '1')
					return (0);
				j++;
			}
		}
		else
		{
			if (game->map[i][0] != '1' || game->map[i][game->cols - 1] != '1')
				return (0);
		}
		i++;
	}
	return (1);
}

void	valid_caracteres(t_game *game)
{
	int	j;

	game->i = -1;
	while (game->map[++game->i])
	{
		j = -1;
		while (game->map[game->i][++j])
		{
			if (game->map[game->i][j] == 'P')
				game->player++;
			if (game->map[game->i][j] == 'E')
				game->exit++;
			if (game->map[game->i][j] == '1')
				game->wall++;
			if (game->map[game->i][j] == 'C')
				game->num_coin++;
			if (game->map[game->i][j] == '0')
				game->way++;
			if (game->map[game->i][j] != '\n' && game->map[game->i][j] != 'P'
				&& game->map[game->i][j] != 'E' && game->map[game->i][j] != '1'
				&& game->map[game->i][j] != 'C' && game->map[game->i][j] != '0')
				ft_error_with_free(game, "Error\n Invalid characters\n", 1, -1);
		}
	}
	check_characters(game);
}

char	**dup_map(t_game *game)
{
	int		i;

	i = 0;
	game->dup_map = malloc((game->rows + 1) * sizeof(char *));
	if (!game->dup_map)
		ft_error_with_free(game, "Error\n Memory allocation failed\n", 1, -1);
	while (i < game->rows)
	{
		game->dup_map[i] = ft_strdup(game->map[i]);
		i++;
	}
	game->dup_map[i] = NULL;
	return (game->dup_map);
}
