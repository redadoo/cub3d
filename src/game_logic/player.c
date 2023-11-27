/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 22:51:07 by edoardo           #+#    #+#             */
/*   Updated: 2023/11/26 13:10:07 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	init_player(t_player *player, char **map)
{
	t_vector2_int	i;

	i.x = 0;
	i.y = 0;
	player->dir.x = 0;
	player->dir.y = 0;
	while (map[i.x])
	{
		while (map[i.x][i.y])
		{
/*  			if (map[i.x][i.y] == 'N')
				set_vector2(&player->dir, 0, 1); */
/*			if (map[i.x][i.y] == 'S')
					player->dir = set_vector2(0, -1);
			if (map[i.x][i.y] == 'E')
					player->dir = set_vector2(1, 0);
			if (map[i.x][i.y] == 'W')
					player->dir = set_vector2(-1, 0); */
			i.y++;
		}
		i.y = 0;
		i.x++;
	}
}
