/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valided.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:38:41 by mrocher           #+#    #+#             */
/*   Updated: 2024/01/22 19:39:53 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_dup(t_game *game)
{
	char	**map;
	int		i;
	int		j;

	map = malloc(sizeof(char *) * (game->map.rows + 1));
	if (!map)
		return (NULL);
	i = -1;
	while (game->map.full[++i])
	{
		map[i] = malloc(sizeof(char) * (ft_strlen(game->map.full[i]) + 1));
		if (!map[i])
		{
			while (--i >= 0)
				free(map[i]);
			free(map);
			return (NULL);
		}
		j = -1;
		while (game->map.full[i][++j])
			map[i][j] = game->map.full[i][j];
		map[i][j] = '\0';
	}
	map[i] = NULL;
	return (map);
}

t_info	init_info(void)
{
	t_info	info;

	info.x = -1;
	info.y = -1;
	info.coins_found = 0;
	info.exit_found = 0;
	return (info);
}

t_info	find_map_info(char **map)
{
	int			x;
	int			y;
	t_info		info;

	info = init_info();
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				info.x = x;
				info.y = y;
			}
			else if (map[y][x] == 'C')
				info.coins_found++;
			else if (map[y][x] == 'E')
				info.exit_found = 1;
			x++;
		}
		y++;
	}
	return (info);
}

void	flood_fill(int x, int y, char **map, t_info *info)
{
	if (map[y][x] == 'E' && info->coins_found > 0)
		return ;
	if (x < 0 || y < 0 || map[y] == NULL
		|| map[y][x] == '1' || map[y][x] == 'V')
		return ;
	if (map[y][x] == 'C')
		info->coins_found--;
	if (map[y][x] == 'E')
		info->exit_found--;
	map[y][x] = 'V';
	flood_fill(x, y - 1, map, info);
	flood_fill(x, y + 1, map, info);
	flood_fill(x - 1, y, map, info);
	flood_fill(x + 1, y, map, info);
}

int	is_map_solvable(t_game *game)
{
	char	**map_cpy;
	t_info	info;
	int		sol;

	map_cpy = map_dup(game);
	info = find_map_info(map_cpy);
	flood_fill(info.x, info.y, map_cpy, &info);
	sol = (info.coins_found == 0 && info.exit_found == 0);
	ft_free_ressources(map_cpy);
	return (sol);
}
