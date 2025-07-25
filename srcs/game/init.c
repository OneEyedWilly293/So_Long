/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgueon <jgueon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 16:10:47 by jgueon            #+#    #+#             */
/*   Updated: 2025/07/25 18:24:29 by jgueon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static mlx_image_t *load_tex(mlx_t *mlx, const char *path)
{
	mlx_texture_t	*tex;
	mlx_image_t		*img;

	tex = mlx_load_png(path);
	if (!tex)
		return (NULL);
	img = mlx_texture_to_image(mlx, tex);
	mlx_delete_texture(tex);
	return (img);
}

bool	game_init(t_game *g)
{
	g->mlx = mlx_init(g->map.w * 64, g->map.h * 64, "So Long", false);
	if (!g->mlx)
		return (false);
	g->img[0] = load_tex(g->mlx, "textures/wall.png");
	g->img[1] = load_tex(g->mlx, "textures/collectable.png");
	g->img[2] = load_tex(g->mlx, "textures/player.png");
	g->img[3] = load_tex(g->mlx, "textures/exit.png");
	g->moves = 0;
	return (true);
}

