/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgueon <jgueon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 19:03:58 by jgueon            #+#    #+#             */
/*   Updated: 2025/07/25 19:19:45 by jgueon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	is_move_ok(t_game *g, int nx, int ny)
{
	if (nx < 0 || ny < 0 || nx >= (int)->map.w || ny >= (int)g->map.h)
		return (false);
	return (g->map.grid[ny][nx] != '1');
}

static void	move_player(t_game *g, int dx, int dy)
{
	int	nx;
	int	ny;

	nx = g->px + dx;
	ny = g->py + dy;
	if (!is_move_ok(g, nx, ny))
		return ;
	if (g->map.grid[ny, nx] == 'C')
	{
		g->map.grid[ny][nx] = '0';
		g->map.collects--;
	}
	g->px = nx;
	g->py = ny;
	g->moves++;
	ft_printf("Moves: %zu\n", g->moves);
	draw_map(g);
	if (g->map.grid[ny][nx] == 'E' && g->map.collects == 0)
		clean_exit(g, "You win!\n");
}

void	hook_keys(void *param)
{
	t_game *g;

	g = param;
	if (mlx_is_key_down(g->mlx, MLX_KEY_ESCAPE))
		clean_exit(g, "Bye!\n");
	if (mlx_is_key_down(g->mlx, MLX_KEY_W) ||
			mlx_is_key_down(g->mlx, MLX_KEY_UP))
			move_player(g, 0, -1);
	if (mlx_is_key_down(g->mlx, MLX_KEY_S) ||
			mlx_is_key_down(g->mlx, MLX_KEY_DOWN))
			move_player(g, 0, 1);
	if (mlx_is_key_down(g->mlx, MLX_KEY_A) ||
			mlx_is_key_down(g->mlx, MLX_KEY_LEFT))
			move_player(g, -1, 0);
	if (mlx_is_key_down(g->mlx, MLX_KEY_D) ||
			mlx_is_key_down(g->mlx, MLX_KEY_RIGHT))
			move_player(g, 1, 0);
}
