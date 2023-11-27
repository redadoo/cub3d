/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 21:47:45 by edoardo           #+#    #+#             */
/*   Updated: 2023/11/26 16:47:33 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifdef __APPLE__
#  include "mlx.h"
#  define UP 13
#  define LEFT 0
#  define DOWN 1
#  define RIGHT 2
#  define EXIT  53
# endif
# ifdef __linux__
#  include "./mlx_linux/mlx.h"
#  define UP 119
#  define LEFT 97
#  define DOWN 115
#  define RIGHT 100
#  define EXIT  65307
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "lib/vector/vector.h"
# include "lib/collider/collider.h"
# include <math.h>
# include <fcntl.h>
# include "lib/ft_libft/libft.h"

typedef struct s_window
{
	t_vector2	size;
	void		*reference;
}				t_window;

typedef struct s_player
{
	t_vector2_int		map_pos;
	t_vector3			pos;
	t_vector2			dir;
	t_3dbox_collider	collider;
}				t_player;

typedef struct s_wall
{
	int		img_width;
	int		img_height;
	char	*path;
	void	*img;
}				t_wall;

typedef struct s_map
{
	char		**map;
	t_vector3	floor_color;
	t_vector3	celin_color;
	t_wall		north_wall;
	t_wall		south_wall;
	t_wall		ovest_wall;
	t_wall		east_wall;
}				t_map;

typedef struct s_camera
{
	t_vector2	camera_plane;
	t_vector3	pos;
}				t_camera;

typedef struct s_ray
{
	int			ray_height;
	t_vector2	ray_dir;
	t_vector3	ray_lenght;
}				t_ray;

typedef struct s_game
{
	void		*reference;
	void		*mlx;
	t_map		map;
	t_window	window;
	t_player	player;
	t_camera	camera;
	float		time;
	float		old_time;
}				t_game;

/* GAME ENGINE */
void		renderer(t_game *game);
/* UTILS */
int			check_extension(char *file);
int			check_dir(char ch);
/* GAME LOGIC */
int			main_loop(void *param);
void		init_player(t_player *player, char **map);
void		init_camera(t_camera *camera);
/* UTILS */
int			close_game(t_game *game);
void		free_matrix(char **map);
void		print_matrix(char **matrix);
t_vector3	string_to_vector(char *str);
void		print_vector3(t_vector3 v);
t_vector3	set_vector3(float x, float y, float z);
void		set_vector2(t_vector2 *v, float x, float y);

/* WINDOW */
t_window	ft_new_window(void *mlx, int widht, int height, char *name);

/* MAP READ */
t_map		readmap(char *file);
void		extract_info(t_map *map, char *str);

/* KEY */
int			key_hook(int keycode, void *param);

#endif