/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:29:00 by evocatur          #+#    #+#             */
/*   Updated: 2023/11/26 17:03:43 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	renderer(t_game *game)
{
	int				x;
	int				hit;
	int				side;
	t_ray			ray;
	t_vector2		side_dist;
 	double			delta_dist_x;
  	double			delta_dist_y;
	double			perpWallDist;
	t_vector2_int	step;

	x = 0;
	/* while (x < game->window.size.x)
	{
		game->camera.pos.x = 2 * x / game->window.size.x - 1;
		ray.ray_dir.x = game->player.dir.x + game->camera.camera_plane.x * game->camera.pos.x;
		ray.ray_dir.y = game->player.dir.y + game->camera.camera_plane.y * game->camera.pos.y;

    	delta_dist_x = (ray.ray_dir.x == 0) ? 1e30 : fabs(1 / ray.ray_dir.x);
      	delta_dist_y = (ray.ray_dir.y == 0) ? 1e30 : fabs(1 / ray.ray_dir.y);

		if (ray.ray_dir.x < 0)
		{
			step.x = -1;
			side_dist.x = (game->player.pos.x - game->player.map_pos.x) * delta_dist_x;
		}
		else
		{
			step.x = 1;
			side_dist.x = (game->player.map_pos.x * 1.0 - game->player.pos.x) * delta_dist_x;
		}
		if (ray.ray_dir.y < 0)
		{
			step.y = -1;
			side_dist.y = (game->player.pos.y - game->player.map_pos.y) * delta_dist_y;
		}
		else
		{
			step.y = 1;
			side_dist.y = (game->player.map_pos.y + 1.0 - game->player.pos.y) * delta_dist_y;
		}
		while(hit == 0)
		{
			if (side_dist.x < side_dist.y)
			{
				side_dist.x += side_dist.y;
				game->player.map_pos.x += step.x;
				side = 0;
			}
			else
			{
				side_dist.y += side_dist.x;
				game->player.map_pos.y = step.y;
				side = 1;
			}
			if (game->map.map[game->player.map_pos.x][game->player.map_pos.y] > 0)
				hit = 1;
		}
		if (side == 0)
			perpWallDist = (side_dist.x - delta_dist_x);
		else
			perpWallDist = (side_dist.y - delta_dist_y);
		ray.ray_height = (int)(game->window.size.y / perpWallDist);
		x++;
	} */
}
