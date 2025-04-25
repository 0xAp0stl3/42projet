/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:59:46 by mrocher           #+#    #+#             */
/*   Updated: 2024/01/22 19:30:46 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check(int ac, char **av, t_game *game)
{
	int	map;

	game->map_alloc = false;
	if (ac > 2)
		ft_error("Much argv", game);
	if (ac < 2)
		ft_error("Map misssing", game);
	map = ft_strlen(av[1]);
	if (!ft_strnstr(&av[1][map - 4], ".ber", 4))
		ft_error("Map must be in .ber", game);
}

void	ft_check_line(char *map, t_game *game)
{
	int	i;

	i = 0;
	if (map[0] == '\n')
	{
		free(map);
		ft_error("The map have empty line", game);
	}
	else if (map[ft_strlen(map) - 1] == '\n')
	{
		free(map);
		ft_error("The map have empty line in the end", game);
	}
	while (map[i + 1])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			free(map);
			ft_error("The map have empty line in mid", game);
		}
		i++;
	}
}

void	ft_check_line_lenght(t_game *game)
{
	size_t	len;
	int		i;

	len = ft_strlen(game->map.full[0]);
	i = 1;
	while (i < game->map.rows)
	{
		if (ft_strlen(game->map.full[i]) != len)
		{
			ft_error("This map is not valid", game);
			return ;
		}
		i++;
	}
}

void	ft_map(t_game *game, char *av)
{
	char	*map_tmp;
	char	*line_tmp;
	int		map_fd;

	map_fd = open(av, O_RDONLY);
	if (map_fd == -1)
		ft_error("Map not opened", game);
	map_tmp = ft_strdup("");
	game->map.rows = 0;
	while (true)
	{
		line_tmp = get_next_line(map_fd);
		if (line_tmp == NULL)
			break ;
		map_tmp = ft_append(&map_tmp, line_tmp);
		free(line_tmp);
		game->map.rows++;
	}
	close(map_fd);
	ft_check_line(map_tmp, game);
	game->map.full = ft_split(map_tmp, '\n');
	game->map_alloc = true;
	free(map_tmp);
}
