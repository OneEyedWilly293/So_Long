/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgueon <jgueon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:33:32 by jgueon            #+#    #+#             */
/*   Updated: 2025/07/24 18:10:34 by jgueon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	count_lines(int fd)
{
	size_t	lines;
	char	*line;

	lines = 0;
	while ((line = get_next_line(fd)))
	{
		lines++;
		free(line);
	}
	return (lines);
}

static bool	load_grid(int fd, t_map *m)
{
	char	*line;
	size_t	i;

	m->grid = malloc(sizeof(char *) * (m->h + 1));
	if (!m->grid)
		return (false);
	i = 0;
	while (i < m->h && (line = get_next_line(fd)))
	{
		m->grid[i] = ft_strtrim(line, "\n");
		free(line);
		if (ft_strlen(m->grid[i]) != m->w)
			return (false);
		i++;
	}
	m->grid[i] = NULL;
	return (true);
}

bool	read_map(const char *file, t_map *map)
{
	int		fd;
	char	*first;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (false);
	map->h = count_lines(fd);
	close(fd);
	fd = open(file, O_RDONLY);
	if (fd < 0 || map->h == 0)
		return (false);
	map->grid = NULL;
	map->w = 0;
	map->collects = 0;
	first = get_next_line(fd)
	if (!first)
		return (false);
	map->w = ft_strlen(first) - 1;
	free(first);
	if (!load_grid(fd, map))
		return (close(fd), false);
	close(fd);
	return (true);
}
