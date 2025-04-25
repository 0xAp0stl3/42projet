/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:45:13 by mrocher           #+#    #+#             */
/*   Updated: 2024/01/22 19:31:11 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	ft_check(ac, av, game);
	ft_map(game, av[1]);
	ft_init(game);
	check_map(game);
	ft_init_mlx(game);
	ft_define_sprite(game);
	ft_render_map(game);
	mlx_hook(game->win, KeyPress, KeyPressMask, ft_key_hook, game);
	mlx_hook(game->win, DestroyNotify, \
	ButtonPressMask, ft_close, game);
	mlx_hook(game->win, Expose, ExposureMask, ft_render_map, game);
	mlx_loop(game->mlx);
	free_alloc(game);
}
