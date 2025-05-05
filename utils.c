/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconde-s <mconde-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 13:06:09 by mconde-s          #+#    #+#             */
/*   Updated: 2025/05/03 16:17:34 by mconde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_with_free(t_game *game, char *str, int i, int fd)
{
	int	j;

	get_next_line(0, 1);
	if (game && game->map)
	{
		j = -1;
		while (game->map[++j])
			free(game->map[j]);
		free(game->map);
	}
	if (game && game->dup_map)
	{
		j = -1;
		while (game->dup_map[++j])
			free(game->dup_map[j]);
		free(game->dup_map);
	}
	if (fd > 2)
		close(fd);
	ft_printf("%s\n", str);
	free(game->len_line);
	free(game->graphics);
	free(game);
	exit(i);
}

void	check_characters(t_game *game)
{
	if (game->player != 1 || game->exit != 1 || game->wall == 0
		|| game->num_coin == 0)
		ft_error_with_free(game, "Error\n Invalid characters\n", 1, 0);
}
