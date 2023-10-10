/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cup3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 20:22:28 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/10 19:01:29 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUP3D_H
#define CUP3D_H

#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include <fcntl.h>
#include "./Get_next_line/get_next_line.h"

#define WIN_WIDTH 800
#define WIN_HEIGHT 400

typedef struct s_data
{
    void	*mlx_ptr;
    void	*win_ptr;
    int		x_start;
    int		y_start;
    int		color;
    int		cup;

    //img attr
    char    *addr;
    void    *mlx_img;
    int     line_len;
    int     endian;
    int     bpp;
} t_data;

char	**fill_stock(int *map_s);
char	*ft_strtrim(char const *s1, char const *set);
void    draw_map(t_data *data);
void    draw_sq(t_data *data, int color, int cup);
void	put_img(int x, int y, unsigned int color, t_data *data);

#endif