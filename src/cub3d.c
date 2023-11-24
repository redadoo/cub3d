/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:04:18 by evocatur          #+#    #+#             */
/*   Updated: 2023/11/24 17:46:14 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;
	
	if (argc != 2 || check_extension(argv[1]) == 1)
		close_game(&game);

	game.mlx = mlx_init();
	game.map.floor_color.x = 139;
	game.map.floor_color.y = 115;
	game.map.floor_color.z = 115;
	game.window = ft_new_window(game,1980, 1080, "cub3d");
	mlx_key_hook(game.window.reference, *key_hook, &game);
	mlx_loop_hook(game.mlx, main_loop, &game);
	mlx_hook(game.window.reference, 17, 0, *close_game, &game);
	mlx_loop(game.mlx);
}
