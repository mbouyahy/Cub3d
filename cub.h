/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:22:29 by jlaazouz          #+#    #+#             */
/*   Updated: 2023/10/16 10:55:35 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "libft/libft.h"
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

//added by mbouyahy (BEGIN)
#include <math.h>
#include <mlx.h>
#include <fcntl.h>
//added by mbouyahy (END)


# define MAP_SET "10NEWS "
# define MAP_DIRECTIONS "NEWS"//added by mbouyahy
# define MAP_SET_NEW "10NEWS\t\n "
# define WHITE_SPACES "\n "

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
	int				x;
	int				y;
	int				facing_direction;
	char        	p_direction;//temp
	int				rad;
	double			m_speed;
	int				t_dir;//remove this
	int				w_dir;
	double			r_angle;
	double			r_speed;
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

//added by mbouyahy (BEGIN)

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
    int		x;
    int		y;
    int		c;
    int		i;
	int		x_end;
    int		y_end;
    double	angle;
    double	angle_inc;
} t_var;


typedef struct s_distance
{
    int         next_x;//convert it to double for check if its work perfectly than integer
	int         next_y;//convert it to double for check if its work perfectly than integer
	double      y_step;
	double      x_step;
	int         grid_x;
	int         grid_y;
	int         v_dist;
	int         h_dist;
}               t_distance;

//added by mbouyahy (END)

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

	//added by mbouyahy
	int				width_size;
    int				height_size;
    
    void			*mlx_ptr;
    void			*win_ptr;
    int				x_start;
    int				y_start;
    int				cub;
    double			fov;
    int				ray_length;

    char			**map;
    int				map_size;

    t_img		img;
	t_distance  dist;

}					t_data;


//added by mbouyahy (BEGIN)

/*---------------------------<Setup Functions>---------------------------*/

void				init_data(t_data  *data);

/*---------------------------<Events Functions>---------------------------*/

int					key_events(int btr, t_data *data);
int					destroy_window(t_data *data);
float				deg_to_rad(int deg);

/*---------------------------<Drawing Functions>---------------------------*/

void				draw_map(t_data *data, int flag);
void				draw_square(t_data *data, int color, int cub);
void				redraw(t_data *data, int flag);
void				setup_angle(t_data *data);
void				put_img(int x, int y, unsigned int color, t_data *data);
void				draw_line(t_data *data);
int					horizontal_intersection(t_data *data);
int					vertical_intersection(t_data *data);
int					find_coordinate(t_data *data, int next_point, double *step);

//added by mbouyahy (END)

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