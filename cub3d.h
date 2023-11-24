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





#endif