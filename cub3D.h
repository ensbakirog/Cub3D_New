#ifndef     CUB3D_H
# define    CUB3D_H

#define	W_WIDTH	800
#define	W_HEIGHT 600
#define TEXTURE_COUNT 4

#define ERR_MALLOC "malloc()"
#define ERR_CLOSE "close()"
#define ERR_OPEN "open()"
#define ERR_GNL "get_next_line()"
#define ERR_MLX_INIT "mlx_init()"
#define ERR_MLX_WIN "mlx_new_window()"
#define ERR_EXTENSION "File extension have to be <.cub>"
#define ERR_ARG "Arguments have to be: ./cub3D <map_name.cub>"
#define ERR_BORDER "Map have to be bordered by '1'"

#define ERR_TEXTURE "Texture syntax in the map must be:\n\
NO ./path_to_the_north_texture\n\
SO ./path_to_the_south_texture\n\
WE ./path_to_the_west_texture\n\
EA ./path_to_the_east_texture"

#define ERR_COLOR "Color syntax in the map must be:\n\
F r,g,b  <r, g, b: 0-255> (Floor color)\n\
C r,g,b  <r, g, b: 0-255> (Ceiling color)"

#define ERR_COLOR_VALUE "Color values must be between 0 and 255"


#include <stdio.h> // delete it when push
#include <unistd.h> // delete it when push

typedef struct s_data
{
	char	**texture;
	char 	**map;
	int		rgb[2][3];
	char	*map_name;
	void	*mlx;
	void 	*window;
	int		fd;
	int		deneme;
	int		pp[2];
	int		map_h;
} t_data;


// utils

void	free_all(t_data *data);
void	error(t_data *data, char *str);
void	check(t_data *data, char *str);


// main

void	map_scan(t_data *data, int count, char *str);

#endif