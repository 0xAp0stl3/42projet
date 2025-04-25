/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:50:50 by mrocher           #+#    #+#             */
/*   Updated: 2024/01/22 19:32:50 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_free(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.rows)
		free(game->map.full[i++]);
	free(game->map.full);
}

void	ft_destroy_img(t_game *game)
{
	mlx_destroy_image(game->mlx, game->wall.xpm);
	mlx_destroy_image(game->mlx, game->nw.xpm);
	mlx_destroy_image(game->mlx, game->coins.xpm);
	mlx_destroy_image(game->mlx, game->sprite.xpm);
	mlx_destroy_image(game->mlx, game->close.xpm);
	mlx_destroy_image(game->mlx, game->open.xpm);
}

void	ft_free_ressources(char **map_cpy)
{
	int	i;

	i = 0;
	while (map_cpy[i] != NULL)
	{
		free(map_cpy[i]);
		i++;
	}
	free(map_cpy);
}

void	free_alloc(t_game *game)
{
	ft_destroy_img(game);
	ft_map_free(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game);
}
