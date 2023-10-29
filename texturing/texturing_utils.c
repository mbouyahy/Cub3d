/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturing_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaazouz <jlaazouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:13:04 by jlaazouz          #+#    #+#             */
/*   Updated: 2023/10/29 15:25:50 by jlaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void get_color_texture(t_tex *texture, int x, int y, unsigned int *color)
{
    char *dst;

    dst = texture->addr + (y * texture->line_len + x * (texture->bpp / 8));
    unsigned char red   = dst[2];
    unsigned char green = dst[1];
    unsigned char blue  = dst[0];
    *color = create_trgb(0, (int)red, (int)green, (int)blue);
}