/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:50:16 by evocatur          #+#    #+#             */
/*   Updated: 2023/11/24 17:53:00 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	file_linecount(char *file)
{
	char	c;	
	int		fd;	
	int		linecount;
	int		readcount;

	fd = open(file, O_RDONLY);
	if (!fd)
		return (-1);
	linecount = 1;
	while (true)
	{
		readcount = read(fd, &c, 1);
		if (readcount == 0)
			break ;
		if (readcount < 0)
			return (-1);
		if (c == '\n')
			linecount++;
	}
	close(fd);
	return (linecount);
}

/* read a file and return the map inside it*/
t_map	readmap(void *param, char *file)
{
	int				i;
	int				fd;
	char			**map;
	t_map			game_map;

	map = ft_calloc((sizeof(char *)), file_linecount(file) + 1);
	if (map == NULL)
		return (game_map);
	fd = open(file, O_RDONLY);
	i = 0;
	while (i < file_linecount(file))
	{
		map[i] = get_next_line(fd);
		if (map[i] == NULL)
		{
			free_matrix(map);
		}
		i++;
	}
	game_map.size.z = file_linecount(file);
	game_map.size.x = ft_strlen(map[0]);
	game_map.map = map;
	close(fd);
	return (game_map);
}

void	free_matrix(char **map)
{
	int		i;
	char	*line;

	i = 0;
	while (map[i])
	{
		line = map[i];
		if (line)
			free(line);
		i++;
	}
	free(map);
}
