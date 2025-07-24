/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgueon <jgueon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 14:07:31 by jgueon            #+#    #+#             */
/*   Updated: 2025/07/24 18:25:33 by jgueon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_map
{
	char	**grid;
	size_t	w;
	size_t	h;
	size_t	collects;
} t_map;

typedef struct s_game
{
	mlx_t		*mlx;
	mlx_image_t	*img[4]; /*0 Wall, 1 collect, 2 player, 3 exit*/
	t_map		map;
	size_t		moves;
	int			px;
	int 		py;
} t_game;

/* ------------- parse ------------- */
bool	read_map(const char	*file, t_map *map);
bool	validate_map(t_map *map);

/* ------------- game -------------- */
bool	game_init(t_game *g);
void	hook_keys(void *param);
void	draw_map(t_game *g);

/* ------------- utils ------------- */
void	clean_exit(t_game *g, char *msg);

#endif