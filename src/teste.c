#include "../includes/mlx.h"


int create_floor(void *mlx, void *window, int gameWidth, int gameHeight, int color_floor)
{
    int x;
    int y;
    y = gameHeight / 2;
    x = 0;

    while (y < gameHeight)
    {
        x = 0;
        while (x < gameWidth)
        {
            mlx_pixel_put(mlx, window, x, y, color_floor);
            x++;
        }
        y++;
    }

    return (0);
}

int create_ceiling(void *mlx, void *window, int gameWidth, int gameHeight, int color_ceiling)
{
    int x;
    int y;
    y = 0;
    x = 0;

    while (y < gameHeight / 2)
    {
        x = 0;
        while (x < gameWidth)
        {
            mlx_pixel_put(mlx, window, x, y, color_ceiling);
            x++;
        }
        y++;
    }

    return (0);
}

int create_background(void *mlx, void *window, int gameWidth, int gameHeight, int color_floor, int color_ceiling)
{
    create_floor(mlx, window, gameWidth, gameHeight, color_floor);
    create_ceiling(mlx, window, gameWidth, gameHeight, color_ceiling);
    mlx_loop(mlx);
    return (0);
}


//Multiplicador = 2 * (x/width) -1
int rayscasting()
{
    void *mlx;
    void *window;

    char map[10][10] = 
    {
        {'1', '1', '1', '1', '1', '1', '1', '1', '1'},
        {'1', '0', '0', '0', '0', '0', '0', '0', '1'},
        {'1', '0', '1', '1', '1', '1', '1', '0', '1'},
        {'1', '0', '1', '0', '0', '0', '1', '0', '1'},
        {'1', '0', '1', '0', '1', '0', '1', '0', '1'},
        {'1', '0', '1', '0', '0', '0', '1', '0', '1'},
        {'1', '0', '1', '0', '1', '0', '1', '0', '1'},
        {'1', '0', '0', '0', '1', '0', '0', '0', '1'},
        {'1', '0', '0', '0', '0', '0', '0', '0', '1'},
        {'1', '1', '1', '1', '1', '1', '1', '1', '1'}
    };
    int pos_x = 5;
    int pos_y = 5;
    int dir_x = 0;
    int dir_y = -1;
    int plane_x = 0.66;
    int plane_y = 0;

    int gameWidth = 320;
    int gameHeight = 200;
    mlx = mlx_init();
    window = mlx_new_window(mlx, gameWidth, gameHeight, "Cub3D");
    int color_floor = 0x5ED41D;
    int color_ceiling = 0x5ED4E1;
    create_background(mlx, window, gameWidth, gameHeight, color_floor, color_ceiling);
    return (0);
}

int main()
{
    rayscasting();
    return (0);
}