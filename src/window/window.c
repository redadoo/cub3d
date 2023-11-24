#include "../../cub3d.h"

t_window	ft_new_window(t_game game, int widht, int height, char *name)
{
	t_window	window;

	window.reference = mlx_new_window(game.mlx, widht, height + 50, name);
	window.size.x = widht;
	window.size.y = height;
	return (window);
}