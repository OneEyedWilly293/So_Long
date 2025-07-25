/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgueon <jgueon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 19:20:09 by jgueon            #+#    #+#             */
/*   Updated: 2025/07/25 19:21:31 by jgueon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_exit(t_game *g, char *msg)
{
	if (msg)
		ft_printf("%s", msg);
	if (g)
	{
		if (g->mlx)
			mlx_terminate(g->mlx);
		if (g->map.grid)
			ft_free_split(g->map.grid);
	}
	exit(0);
}
