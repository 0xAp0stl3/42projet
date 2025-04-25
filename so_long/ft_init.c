/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 21:25:10 by mrocher           #+#    #+#             */
/*   Updated: 2024/01/22 19:37:33 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count_rows(char **array)
{
	int	count;

	count = 0;
	while (array && array[count])
		count++;
	return (count);
}

void	ft_init(t_game *game)
{
	game->map.coins = 0;
	game->map.exit = 0;
	game->mov = 0;
	game->map.players = 0;
	if (game->map.full && game->map.full[0])
	{
		game->map.rows = ft_count_rows(game->map.full);
		game->map.col = ft_strlen(game->map.full[0]);
	}
	else
		ft_error("Map data is not initialized properly", game);
	game->player_s = ONLY;
}

void	ft_init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
	{
		free(game->mlx);
		ft_error("Error in starting", game);
	}
	game->win = mlx_new_window(game->mlx, game->map.col * IMG_WID, \
		game->map.rows * IMG_HEI, "so_long");
	if (game->win == NULL)
	{
		free(game->mlx);
		ft_error("Error on create the window", game);
	}
}

t_img	ft_create_sprite(void *mlx, char *path, t_game *game)
{
	t_img	sprite;

	sprite.xpm = mlx_xpm_file_to_image(mlx, path, &sprite.x, &sprite.y);
	if (sprite.xpm == NULL)
		ft_error("Error create sprite", game);
	return (sprite);
}

void	ft_define_sprite(t_game *game)
{
	void	*mlx;

	mlx = game->mlx;
	game->wall = ft_create_sprite(mlx, WALL_S, game);
	game->sprite = ft_create_sprite(mlx, PLAYER_S, game);
	game->nw = ft_create_sprite(mlx, NW_S, game);
	game->coins = ft_create_sprite(mlx, COIN_S, game);
	game->open = ft_create_sprite(mlx, EXIT_S, game);
	game->close = ft_create_sprite(mlx, CLOSE_S, game);
}
