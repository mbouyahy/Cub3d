/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:22:29 by jlaazouz          #+#    #+#             */
/*   Updated: 2023/10/25 20:11:32 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "libft/libft.h"
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <math.h>
#include <mlx.h>
#include <fcntl.h>

/*---------------------------<Parsing Macro's>---------------------------*/

# define MAP_SET "10NEWS "
# define MAP_DIRECTIONS "NEWS"
# define MAP_SET_NEW "10NEWS\t\n "
# define WHITE_SPACES "\n "

/*---------------------------<Special Macro's>---------------------------*/

# define WINDOW_HEIGHT 1080
# define WINDOW_WIDTH 1920
# define HORIZONTAL	0
# define VERTICAL 1
# define CUB_SIZE 40
# define TRUE 1
# define FALSE 0
# define MAX_I 2147483647

/*---------------------------<Views Keys>---------------------------*/

#define LEFT 123
#define RIGHT 124

/*---------------------------<Events Keys>---------------------------*/

#define CLOSE_WIN 17
#define ESC 53

/*------------------------<Movements Functions>-----------------------*/

#define W 13
#define A 0
#define S 1
#define D 2

/*------------------------<Movements Functions>------------------------*/

#define KEY_PRESS 2

enum				e_error
{
	EXTENTION_ERROR,
	FILE_PERMESIONS,
	UNVALID_FILE,
	BAD_ARG,
	VISUAL_DATA_ERR,
	TEXTURES_SPACING,
	BAD_TEXTURES_OR_COLORS_INFO,
	COLOR_FORMAT,
	COLOR_ALL_DIGITS,
	STRANGE_CHAR_IN_MAP,
	PLAYER_OCCURENCE,
	EMPTY_LINE_ON_MAP,
	TOP_MAP_ERR,
	BUTTOM_MAP_ERR,
	SIDES_MAP_ERR,
	EMPTY_LINE_IN_MAP_GRID,
	PLAYER_BAD_POS,
	CLIFF_FOUND,
};

enum				e_component_error
{
	NO,
	SO,
	EA,
	WE,
	F,
	C,
};

typedef struct s_border
{
	size_t			top;
	size_t			buttom;
	size_t			right;
	size_t			left;
}					t_border;

typedef struct s_player
{
	int				facing_direction;
	float			r_angle;
	float			x;
	float			y;
}					t_player;

typedef struct s_visuals
{
	char			*no_texture;
	char			*so_texture;
	char			*we_texture;
	char			*ea_texture;
	unsigned int	ceiling_color;
	unsigned int	floor_color;
	char			*ceiling_str;
	char			*floor_str;
}					t_visuals;

typedef struct s_img
{
    char	*addr;
    void	*mlx_img;
    int		line_len;
    int		endian;
    int		bpp;
}	t_img;

typedef struct s_var
{
    float		x;
    float		y;
    // float		minimap_x;
    // float		minimap_y;
    int			c;
    int			i;
	float  		move_x;
	float  		move_y;
	int			x_end;
    int			y_end;
    float		angle;
    float		angle_inc;
}			t_var;


typedef struct s_distance
{
	float      	temporary_y;
	float      	temporary_x;
	float      	y_step;
	float      	x_step;
    float	   	_x;
	float      	_y;
	int         grid_x;
	int         grid_y;
}               t_distance;

typedef struct s_point
{
	float	   	x;
	float      	y;
	int      	iswall;
} t_point;

typedef struct s_data
{
	char			**file;
	size_t			file_len;
	char			**visual_data;
	char			**map_grid;
	size_t			map_start;
	size_t			map_collums;
	size_t			map_rows;
	size_t			visuals_len;
	t_visuals		*visuals;
	t_player		player;
	t_var			var;

	int				width_size;
    int				height_size;
    void			*mlx_ptr;
    void			*win_ptr;
    int				x_start;
    int				y_start;
    int				cub;
    float			fov;
    int				ray_length;
    int				inside;

    char			**map;
    int				map_size;

    t_img			img;
	t_distance  	dist;
	t_point			Vert;
	t_point			Horiz;
	float 			distance;
	int         	ray_up;
	int         	ray_down;
	int         	ray_left;
	int         	ray_right;

	//testing
	int				collums;
	int				rows;

	int				type;//temp
}					t_data;

/*---------------------------<Setup Functions>---------------------------*/

void				init_data(t_data  *data);
void				ft_init(t_data *cub);
void				create_image(t_data *data);

/*---------------------------<Events Functions>---------------------------*/

int					key_events(int btr, t_data *data);
int					destroy_window(t_data *data);

/*---------------------------<Ray Casting Functions>---------------------------*/

int     			is_inside_wall(t_data *data, float x, float y);
void				find_coordinate(t_data *data, int value);
void				horizontal_intersection(t_data *data);
void				vertical_intersection(t_data *data);
void				horizontal_next_step(t_data *data);
void				vertical_next_step(t_data *data);
float				remainder_angle(float angle);
void    			find_distance(t_data *data);

/*---------------------------<Drawing Functions>---------------------------*/

void				put_img(int x, int y, unsigned int color, t_data *data);
void				draw_special_line(t_data *data, int wallTP, int wallBP);
void 				dda(int x1, int y1, int x2, int y2, t_data *data);//for testing REMOVE IT 🚨
void				draw_square(t_data *data, int color, int cub);
void				draw_map(t_data *data, int flag);
void				drawing_wall(t_data *data);
void				setup_angle(t_data *data);
void				draw_line(t_data *data);
int 				ft_render(t_data *data);
float				abs_angle(t_data *data);
float				deg_to_rad(float deg);

////////////////////////////////------ PARSING ------////////////////////////////////

int					ft_map_checks(t_data *cub, int ac, char *map_name);
int					ft_read_map(t_data *cub, char *map_name);
int					fill_visual_data(t_data *cub);
int					fill_map_data(t_data *cub);

int					check_spacing_and_valid_components(t_data *cub);
int					check_double(t_data *cub);
void				ft_fill_doubles_array(int *arr, t_data *cub);
int					extract_path(t_data *cub);
int					extract_color_code(t_data *cub);
int					check_rgb_range(int r, int g, int b);
int					get_color(char *color_str, unsigned int *color);
int					create_trgb(int t, int r, int g, int b);
int					get_floor_ceiling_color(t_data *cub);

int					ft_more_than_one_player(t_data *cub);
int					check_player_surrounding(t_data *cub);

int					ft_check_valid_map(t_data *cub);
int					check_top_buttom_map(char **map, int row, int collom,
						int err);
int					check_map_left_sides(char **map, int err);
int					check_map_cliffs(t_data *cub);

int					ft_strlen_double_ptr(char **c);
int					str_isdigit(char *str);
int					is_whitespace(char *str);
int					ft_strlen_double_ptr(char **c);
void				free_double_array(char **str);
char				**ft_join_ptr_to_double_ptr(char **arr1, char *str);
int					reached_set(char *str, char *set);
int					ft_occurence_time(char *str, char c);
int					ft_occurence_index(char *str, char c);
void				double_print(char **str);

int					ft_error(int type);

////////////////////////////////------ RAY_CASTING (TMP) ------////////////////////////////////

#endif