/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:04:18 by evocatur          #+#    #+#             */
/*   Updated: 2023/11/24 20:21:48 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;
	
	if (argc != 2 || check_extension(argv[1]) == 1)
		close_game(&game);

	game.map = readmap(argv[1]);
	game.mlx = mlx_init();
	print_matrix(game.map.map);
	game.window = ft_new_window(game,800, 600, "cub3d");
	mlx_key_hook(game.window.reference, *key_hook, &game);
	mlx_loop_hook(game.mlx, main_loop, &game);
	mlx_hook(game.window.reference, 17, 0, *close_game, &game);
	mlx_loop(game.mlx);
}
