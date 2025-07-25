/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgueon <jgueon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 18:22:08 by jgueon            #+#    #+#             */
/*   Updated: 2025/07/25 19:29:05 by jgueon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	is_rectangular(t_map *m)
{

	size_t	i;

	i = 0;
	while(m->grid[i])
	{
		if (ft_strlen(m->grid[i] != m->w))
			return (false);
		i++;
	}
	return (true);
}

static bool	count_chars(t_map *m, int *exit, int *player)
{
	int	x;
	int	y;

	*exit = 0;
	*player = 0;
	m->collects = 0;
	y = -1;
	while (++y < (int)m->h)
	{
		x = -1;
		while (++x < (int)m->w)
		{
			if (m->grid[y][x] == 'E')
				(*exit)++;
			else if (m->grid[y][x] == 'P')
			{
				(*player)++;
				g->px = x;
				g->py = y;
			}
			else if (m->grid[y][x] == 'C')
				m->collects++;
			else if (!ft_strchr("01", m->grid[y][x]))
				return (false);
		}
	}
	return (*exit == 1 && *player == 1 && m->collects >= 1);
}

static bool	walled(t_map *m)
{
	int x;
	int y;


	y = -1;
	while (++y < (int)m->h)
	{
		x = -1;
		while (++x < (int)m->w)
		{
			if ((y == 0 || y == (int)m->h - 1 || x == 0 || x == (int)m->w - 1)
				&& m->grid[y][x] != '1')
				return (false);
		}
	}
	return (true);
}

bool	validate_map(t_game *g)
{
	int exit;
	int player;

	if (!is_rectangular(g) || !walled(g))
		return (false);
	if (!count_chars(m, &exit, &player))
		return (false);
	return (true);
}
