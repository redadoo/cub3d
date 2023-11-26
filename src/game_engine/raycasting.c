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
 	double			delta_dist_x;
  	double			delta_dist_y;
	double			perpWallDist;
	t_vector2_int	step;

	x = 0;
	while (x < game->window.size.x)
	{
		game->camera.pos.x = 2 * x / game->window.size.x - 1;
		ray.ray_dir.x = game->player.dir.x + game->camera.camera_plane.x * game->camera.pos.x;
		ray.ray_dir.y = game->player.dir.y + game->camera.camera_plane.y * game->camera.pos.y;

    	delta_dist_x = (ray.ray_dir.x == 0) ? 1e30 : fabs(1 / ray.ray_dir.x);
      	delta_dist_y = (ray.ray_dir.y == 0) ? 1e30 : fabs(1 / ray.ray_dir.y);

		if (ray.ray_dir.x < 0)
		{
			step.x = -1;
			delta_dist_x = (game->player.pos.x - mapX) * delta_dist_x;
		}
		x++;
	}
}
