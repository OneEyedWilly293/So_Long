/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgueon <jgueon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:17:36 by jgueon            #+#    #+#             */
/*   Updated: 2025/07/24 15:33:04 by jgueon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
	t_game	g;

	if (ac != 2)
		clean_exit(NULL, "Usage: ./so_long map.ber\n");
	if (!read_map(av[1], &g.map))
		clean_exit(NULL, "Error\nInvalid map.\n");
	if (!validate_map(&g.map))
		clean_exit(NULL, "Error\nMap validation failed.\n");
	if (!game_init(&g))
		clean_exit(&g, "MLX failed to init.\n");
	draw_map(&g);
	mlx_key_hook(g.mlx, &hook_keys, &g);
	mlx_loop(g.mlx);
	clean_exit(&g, NULL);
	return (0);
}
