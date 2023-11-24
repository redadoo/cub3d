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

#define NORTHFACE "path"
#define SOUTHFACE "path"
#define	EASTFACE  "path"
#define OVESTFACE "path"

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
	t_vector3	floor_color;
}				t_map;

typedef struct	s_game
{
	void		*reference;
	void		*mlx;
	t_map		map;
	t_window	window;
	t_player	player;
}				t_game;

/* GAME ENGINE */
void		renderer(t_game *game);

/* UTILS */
int			check_extension(char *file);

/* GAME LOGIC */
int			main_loop(void *param);

/* UTILS */
int			close_game(t_game *game);
void		free_matrix(char **map);
void		print_matrix(char **matrix);
/* WINDOW */
t_window	ft_new_window(t_game game, int widht, int height, char *name);

/* MAP READ */
t_map		readmap(char *file);
void		init_map(t_map *map);

/* KEY */
int			key_hook(int keycode, void *param);

#endif