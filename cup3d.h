/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cup3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 20:22:28 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/11 20:48:16 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUP3D_H
#define CUP3D_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mlx.h>
#include <fcntl.h>
#include "./Get_next_line/get_next_line.h"

//verified this!!!
#define UP 124
#define DOWN 123
#define LEFT 125
#define RIGHT 126

typedef struct s_gamer
{
    int   pos_x;
    int   pos_y;
    int     rad;
    double  m_speed;
    int     t_dir;
    int     w_dir;
    double  r_angle;
    double   r_speed;
} t_gamer;

typedef struct s_data
{
    int     width_size;
    int     height_size;
    
    void	*mlx_ptr;
    void	*win_ptr;
    int		x_start;
    int		y_start;
    int		color;
    int		cup;

    char    **map;
    int     map_size;

    t_gamer     gamer;
    // int     pos_x;
    // int     pos_y;

    //img attr
    char    *addr;
    void    *mlx_img;
    int     line_len;
    int     endian;
    int     bpp;
} t_data;

char	**fill_array(int *map_s);
void    draw_map(t_data *data);
void    draw_sq(t_data *data, int color, int cup);
void	put_img(int x, int y, unsigned int color, t_data *data);
int     map_size();

#endif