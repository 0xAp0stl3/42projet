/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:03:31 by mrocher           #+#    #+#             */
/*   Updated: 2024/01/22 19:33:17 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(t_game *game)
{
	ft_printf("Movements totaux: %d\n", game->mov);
	free_alloc(game);
	ft_printf("FINISH\n");
	exit (EXIT_FAILURE);
}

int	ft_win(t_game *game)
{
	ft_printf("Movements totaux: %d\n", ++game->mov);
	free_alloc(game);
	ft_printf("You win !\n");
	exit (EXIT_FAILURE);
}

void	print_mov_shell(t_game *game)
{
	char	*mov;

	mov = ft_itoa(game->mov);
	if (mov != NULL)
	{
		ft_printf("Movement : %s\n", mov);
		free(mov);
	}
}

void	ft_mov(t_game *game, int x, int y, int player)
{
	int		lx;
	int		ly;

	game->player_s = player;
	lx = game->map.player.x;
	ly = game->map.player.y;
	if (game->map.full[y][x] == EXIT && game->map.coins == 0)
		ft_win(game);
	else if ((game->map.full[y][x] == NW) || (game->map.full[y][x] == COINS))
	{
		game->map.full[ly][lx] = NW;
		if (game->map.full[y][x] == COINS)
			game->map.coins--;
		game->map.player.x = x;
		game->map.player.y = y;
		game->map.full[y][x] = PLAYER;
		game->mov++;
		print_mov_shell(game);
		ft_render_map(game);
	}
}

int	ft_key_hook(int key, t_game *game)
{
	if (key == UP || key == W)
		ft_mov(game, game->map.player.x, game->map.player.y - 1, ONLY);
	if (key == DOWN || key == S)
		ft_mov(game, game->map.player.x, game->map.player.y + 1, ONLY);
	if (key == LEFT || key == A)
		ft_mov(game, game->map.player.x - 1, game->map.player.y, ONLY);
	if (key == RIGHT || key == D)
		ft_mov(game, game->map.player.x + 1, game->map.player.y, ONLY);
	if (key == ESC || key == CLICK)
		ft_close(game);
	return (0);
}
