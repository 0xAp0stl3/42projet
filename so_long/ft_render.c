/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 19:13:14 by mrocher           #+#    #+#             */
/*   Updated: 2024/01/22 19:35:15 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_render_sp(t_game *game, t_img play, int col, int rows)
{
	mlx_put_image_to_window(game->mlx, game->win, \
	play.xpm, col * play.x, rows * play.y);
}

void	ft_player(t_game *game, int x, int y)
{
	if (game->player_s == ONLY)
		ft_render_sp(game, game->sprite, x, y);
}

void	ft_sprite(t_game *game, int x, int y)
{
	char	sp;

	sp = game->map.full[y][x];
	if (sp == WALL)
		ft_render_sp(game, game->wall, x, y);
	else if (sp == NW)
		ft_render_sp(game, game->nw, x, y);
	else if (sp == COINS)
		ft_render_sp(game, game->coins, x, y);
	else if (sp == EXIT)
	{
		if (game->map.coins == 0)
			ft_render_sp(game, game->open, x, y);
		else
			ft_render_sp(game, game->close, x, y);
	}
	else if (sp == PLAYER)
		ft_player(game, x, y);
}

void	ft_print_mov(t_game *game)
{
	char	*mov;
	char	*ph;

	mov = ft_itoa(game->mov);
	ph = ft_strjoin("Movement : ", mov);
	mlx_string_put(game->mlx, game->win, 40, 20, 99999, ph);
	free(mov);
	free(ph);
}

int	ft_render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.col)
		{
			ft_sprite(game, x, y);
			x++;
		}
		y++;
	}
	ft_print_mov(game);
	return (0);
}
