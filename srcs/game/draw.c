/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgueon <jgueon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 18:31:08 by jgueon            #+#    #+#             */
/*   Updated: 2025/07/25 19:02:34 by jgueon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_tile(t_game *g, mlx_image_t *img, int x, int y)
{
	mlx_image_to_window(g->mlx, img, x * 64, y * 64);
}

void	draw_map(t_game *g)
{
	int	x;
	int	y;

	y = -1;
	while (++y < (int)g->map.h)
	{
		x = -1;
		while( ++x < (int)g->map.w)
		{
			if (g->map.grid[y][x] == '1')
				draw_tile(g, g->img[0], x, y);
			else if (g->map.grid[y][x] == 'C')
				draw_tile(g, g->img[1], x, y);
			else if (g->map.grid[y][x] == 'E')
				draw_tile(g, g->img[3], x, y);
			else if (g->map.grid[y][x] == 'P')
				draw_tile(g, g->img[2], x, y);
		}
	}
}
