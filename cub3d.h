/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 20:22:28 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/13 11:44:06 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mlx.h>
#include <fcntl.h>
#include "./Get_next_line/get_next_line.h"

#define UP 126
#define DOWN 125
#define LEFT 123
#define RIGHT 124
#define CLOSE_WIN 17
#define ESC 53
#define W 13
#define A 0
#define S 1
#define D 2
#define KEY_PRESS 2

typedef struct s_player
{
    int			x;
    int			y;
    int			rad;
    double		m_speed;
    int			t_dir;
    int			w_dir;
    double		r_angle;
    double		r_speed;
}	t_player;

typedef struct s_img
{
    char	*addr;
    void	*mlx_img;
    int		line_len;
    int		endian;
    int		bpp;
}	t_img;

typedef struct s_data
{
    int			width_size;
    int			height_size;
    
    void		*mlx_ptr;
    void		*win_ptr;
    int			x_start;
    int			y_start;
    int			cup;

    char		**map;
    int			map_size;

    t_player	player;
    t_img		img;
} t_data;

char	**fill_array(int *map_s);//temporaire
void    draw_map(t_data *data, int flag);
void    draw_square(t_data *data, int color, int cup);
void	put_img(int x, int y, unsigned int color, t_data *data);
int     map_size();//temporaire

int		ft_strcmp(const char *s1, const char *s2);
void    init_data(t_data  *data);
void    redraw(t_data *data, int flag);
void    draw_line(t_data *data);
int 	key_events(int btr, t_data *data);
int		destroy_window(t_data *data);

#endif