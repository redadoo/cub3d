#ifndef CUB3D_H
#define CUB3D_H

#ifdef __linux__
	# include "./mlx_linux/mlx.h"
	#define UP 119
	#define LEFT 97
	#define DOWN 115
	#define RIGHT 100
	#define EXIT 65307
#elif __APPLE__
	# include "mlx.h"
	#define UP 13
	#define LEFT 0
	#define DOWN 1
	#define RIGHT 2
	#define EXIT 53
#endif

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "lib/vector/vector.h"
#include "lib/collider/collider.h"
#include <math.h>
#include <fcntl.h>
#include "lib/ft_libft/libft.h"

typedef struct	s_window
{
	t_vector2	size;
	void		*reference;
}				t_window;

typedef struct	s_player
{
	t_vector3 			pos;
	t_vector3 			rotation;
	t_3dbox_collider	collider;
}				t_player;

typedef struct	s_map
{
	char		**map;
	t_vector3	size;

}				t_map;

typedef struct	s_game
{
	void		*reference;
	void		*mlx;
	t_map		map;
	t_window	window;
}				t_game;

int			check_extension(char *file);
int			main_loop(void *param);
t_window	ft_new_window(t_game game, int widht, int height, char *name);
int			close_game(t_game *game);
int			key_hook(int keycode, void *param);

#endif