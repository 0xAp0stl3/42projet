/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 21:25:13 by mrocher           #+#    #+#             */
/*   Updated: 2024/01/22 19:38:46 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_img
{
	void	*xpm;
	int		x;
	int		y;
}	t_img;

typedef struct s_map
{
	t_pos	player;
	int		players;
	int		exit;
	int		coins;
	int		rows;
	int		col;
	char	**full;
}	t_map;

typedef struct s_game
{
	void	*win;
	void	*mlx;
	int		mov;
	int		player_s;
	t_map	map;
	t_bool	map_alloc;
	t_img	wall;
	t_img	coins;
	t_img	nw;
	t_img	sprite;
	t_img	open;
	t_img	close;
}	t_game;

typedef struct s_info
{
	int	x;
	int	y;
	int	coins_found;
	int	exit_found;
}	t_info;

# define IMG_HEI	32
# define IMG_WID	32

# define NW			'0'
# define WALL		'1'
# define COINS		'C'
# define PLAYER		'P'
# define EXIT		'E'

# define ONLY		1

# define WALL_S		"sprite/wall.xpm"
# define PLAYER_S	"sprite/player/bowser.xpm"
# define NW_S		"sprite/nw.xpm"
# define COIN_S 	"sprite/coin.xpm"
# define EXIT_S		"sprite/exit.xpm"
# define CLOSE_S	"sprite/close.xpm"

# define W	119
# define S	115
# define A	97
# define D	100

# define ESC	65307
# define CLICK	113

# define UP		65362
# define DOWN	65364
# define LEFT	65361
# define RIGHT	65363

void	ft_error(char *msg, t_game *game);
char	*ft_append(char **s1, const char *s2);
void	ft_init(t_game *game);
void	ft_init_mlx(t_game *game);
t_img	ft_create_sprite(void *mlx, char *path, t_game *game);
void	ft_define_sprite(t_game *game);
void	check_map(t_game *game);
void	ft_map_free(t_game *game);
void	ft_destroy_img(t_game *game);
void	free_alloc(t_game *game);
void	ft_mov(t_game *game, int x, int y, int player);
int		ft_close(t_game *game);
int		ft_key_hook(int key, t_game *game);
void	ft_check(int ac, char **av, t_game *game);
void	ft_check_line(char *map, t_game *game);
void	ft_map(t_game *game, char *av);
int		ft_render_map(t_game *game);
void	ft_print_mov(t_game *game);
void	ft_check_line_lenght(t_game *game);
void	ft_free_ressources(char **map_cpy);
int		is_map_solvable(t_game *game);

#endif
