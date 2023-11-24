/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:50:16 by evocatur          #+#    #+#             */
/*   Updated: 2023/11/24 20:22:03 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int map_height(char *file)
{
	char	c;	
	int		fd;	
	int		linecount;
	int		readcount;
	int		is_map;

	fd = open(file, O_RDONLY);
	if (!fd)
		return (-1);
	linecount = 1;
	is_map = 0;
	while (true)
	{
		readcount = read(fd, &c, 1);
		if (readcount == 0)
			break ;
		if (readcount < 0)
			return (-1);
		if (c == '1')
			is_map = 1;
		if (is_map && c == '\n')
		{
			is_map = 0; 
			linecount++;
		}
	}
	close(fd);
	return (linecount);	
}

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
t_map	readmap(char *file)
{
	int				i;
	int				j;
	int				fd;
	char			*str;
	char			**map;
	t_map			game_map;

	map = ft_calloc((sizeof(char *)), map_height(file) + 1);
 	if (map == NULL)
		return (game_map);
	fd = open(file, O_RDONLY);
	i = 0;
	j = 0;
	while (i < file_linecount(file))
	{
		str = get_next_line(fd);
 		if (str[0] == '1')
		{
			map[j] = ft_strdup(str);
			j++;
		}
		i++;
	}
	game_map.map = map;
 	close(fd);
	init_map(&game_map);
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
