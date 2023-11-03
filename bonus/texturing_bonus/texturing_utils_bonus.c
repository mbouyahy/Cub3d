/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturing_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaazouz <jlaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:13:04 by jlaazouz          #+#    #+#             */
/*   Updated: 2023/11/01 20:25:16 by jlaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_bonus.h"

int32_t	get_color_texture(mlx_texture_t *txt, int x, int y)
{
	int		color;
	int32_t	r;
	int32_t	g;
	int32_t	b;
	int32_t	a;

	color = ((y * txt->bytes_per_pixel) * txt->width + (x
				* txt->bytes_per_pixel));
	r = txt->pixels[color];
	g = txt->pixels[color + 1];
	b = txt->pixels[color + 2];
	a = txt->pixels[color + 3];
	return (create_rgba(r, g, b, a));
}
