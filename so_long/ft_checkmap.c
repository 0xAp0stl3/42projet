/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:29:18 by mrocher           #+#    #+#             */
/*   Updated: 2024/01/22 19:31:25 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_rows(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.rows)
	{
		if (game->map.full[i][0] != WALL)
			ft_error("Invalid map, wall not detected in first rows", game);
		if (game->map.full[i][game->map.col - 1] != WALL)
			ft_error("Invalid map, wall not detected in last rows", game);
		i++;
	}
}

void	check_col(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.col)
	{
		if (game->map.full[0][i] != WALL)
			ft_error("Invalid map, wall not detected in first col", game);
		else if (game->map.full[game->map.rows - 1][i] != WALL)
			ft_error("Invalid map, wall not detected in last col", game);
		i++;
	}
}

void	count_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.col)
		{
			if (!ft_strchr("CEP01", game->map.full[y][x]))
				ft_error("Invalid map", game);
			else if (game->map.full[y][x] == PLAYER)
			{
				game->map.players++;
				game->map.player.x = x;
				game->map.player.y = y;
			}
			else if (game->map.full[y][x] == COINS)
				game->map.coins++;
			else if (game->map.full[y][x] == EXIT)
				game->map.exit++;
			x++;
		}
		y++;
	}
}

void	verif_map(t_game *game)
{
	if (game->map.coins == 0)
		ft_error("There are no coin", game);
	else if (game->map.players != 1)
		ft_error("This game are only one player", game);
	else if (game->map.exit == 0)
		ft_error("This game has no exit", game);
	else if (is_map_solvable(game) == 0)
		ft_error("Error, not solvable", game);
}

void	check_map(t_game *game)
{
	check_rows(game);
	check_col(game);
	ft_check_line_lenght(game);
	count_map(game);
	verif_map(game);
}
