/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cup3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 20:22:28 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/10 16:52:59 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUP3D_H
#define CUP3D_H

#include <stdio.h>
#include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
#include "./Get_next_line/get_next_line.h"

typedef struct t_data
{
    void	*mlx_ptr;
    void	*win_ptr;
    int		x_start;
    int		y_start;
    int		color;
    int		cup;
} s_data;

char	**fill_stock(int *map_s);
char	*ft_strtrim(char const *s1, char const *set);
// void    draw_map(void *win_ptr, void *mlx_ptr);
void    draw_map(s_data *data);
void draw_sq(s_data *data, int color, int cup);

#endif