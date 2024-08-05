#include "cub3D.h"
#include <stddef.h>
#include "minilibx_MacOS/mlx.h"
#include <stdlib.h>

void color_control(t_data *data, int i, int j)
{
	int count;

	while (data->texture[++i])
	{
		count = 0;
		while (data->texture[i][++j])
		{
			
			if (data->texture[i][j] == ',')
				++count;
		}
		if (count != 3)
			error(data, ERR_COLOR);
	}
}

void check_color_texture(t_data *data)
{
	int i;

	if (data->texture[0][0] != 'N' || data->texture[0][1] != 'O')
		error(data, ERR_TEXTURE);
	if (data->texture[1][0] != 'S' || data->texture[1][1] != 'O')
		error(data, ERR_TEXTURE);
	if (data->texture[2][0] != 'W' || data->texture[2][1] != 'E')
		error(data, ERR_TEXTURE);
	if (data->texture[3][0] != 'E' || data->texture[3][1] != 'A')
		error(data, ERR_TEXTURE);
	if (data->texture[4][0] != 'F' || data->texture[4][1] != ' ')
		error(data, ERR_COLOR);
	if (data->texture[5][0] != 'C' || data->texture[5][1] != ' ')
		error(data, ERR_COLOR);
	i = -1;
	while (++i < TEXTURE_COUNT)
	{
		if(data->texture[i][2] != ' '|| data->texture[i][3] != '.'
			|| data->texture[i][4] != '/')
			error(data, ERR_TEXTURE);
	}
	color_control(data, 3, -1);
}
int rgb(int red, int green, int blue)
{
	return ((red * 256 * 256) + (green * 256) + blue); 
}

void enes(t_data *data)
{
	int	i;
	int	j;

	data->mlx = mlx_init();
	if (!data->mlx)
		error(data, ERR_MLX_INIT);
	data->window = mlx_new_window(data->mlx, W_WIDTH, W_HEIGHT, "Cub3D");
	if (!data->window)
		error(data, ERR_MLX_WIN);
	i = -1;
	while (++i < W_HEIGHT)
	{
		j = -1;
		while (++j < W_WIDTH)
		{			if (i < W_HEIGHT / 2)
				mlx_pixel_put(data->mlx, data->window, j, i,
					rgb(data->rgb[0][0], data->rgb[0][1], data->rgb[0][2]));
			else
				mlx_pixel_put(data->mlx, data->window, j, i,
					rgb(data->rgb[1][0], data->rgb[1][1], data->rgb[1][2]));
		}
	}
}

void	starter(t_data *data, char *name)
{
	data->map = NULL;
	data->texture = NULL;
	data->fd = -2;
	data->map_name = name;
	data->mlx = NULL;
	data->window = NULL;
	data->map_h = 0;
}

int	main(int argc, char *argv[])
{
	t_data	data;

	starter(&data, argv[1]);
	if (argc != 2)
		error(&data, ERR_ARG);
    check(&data, argv[1]);
	map_scan(&data, 0, NULL);
	// texture_control(&data);
	enes(&data);
	mlx_loop(&data.mlx);
    return (free_all(&data), 0);
}
