#include "../../cub3d.h"


int main_loop(void *param)
{
    t_game *game;

    game  = (t_game *)param;
    renderer(game);
    return (0);
}