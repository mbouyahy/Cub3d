/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_logs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaazouz <jlaazouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:24:42 by jlaazouz          #+#    #+#             */
/*   Updated: 2023/10/12 20:55:33 by jlaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	ft_error_file(int type)
{
	if (type == EXTENTION_ERROR)
		ft_putstr_fd("MAKE SURE YOU ENTERED THE RIGHT EXTENTION : (.cub)\n", 2);
	else if (type == FILE_PERMESIONS)
		ft_putstr_fd("ERROR : WRONG MAP (NAME / PATH) OR PERMISSION ERROR", 2);
	else if (type == UNVALID_FILE)
		ft_putstr_fd("ERROR :\n\tMAKE SURE YOU ENTERED A VALID FILE\n", 2);
	else if (type == BAD_ARG)
		ft_putstr_fd("ERROR : THE NUMBER OF ARGUMENTS SHOULD BE 2\n", 2);
}

void	ft_error_visual_data(int type)
{
	if (type == VISUAL_DATA_ERR)
		ft_putstr_fd("ERROR : PLEASE MAKE SURE TO HAVE 6 UNIQUE COMPONENT [ NO , \
				SO , WE , EA , F , C ]\n", 2);
	else if (type == TEXTURES_SPACING)
		ft_putstr_fd("ERROR : PLEASE MAKE SURE TO LEAVE ONE OR MORE SPACES AFTER\
					THE TEXTURES DIRECTION OR CEILING AND FLOOR COLOR\n", 2);
	else if (type == BAD_TEXTURES_OR_COLORS_INFO)
		ft_putstr_fd("ERROR : PLEASE MAKE SURE TO ENTER A VALID TEXTURE [ NO , \
				SO , WE , EA , F , C ]\n AND DON'T FORGET TO LEAVE A SPACE AFTER\
				 EACH COMPONENT\n", 2);
	else if (type == COLOR_FORMAT)
		ft_putstr_fd("ERROR : ENTER A VALID COLOR FORMAT \"R,G,B colors in range \
				[0,255]: 0, 255, 255\"\n", 2);
	else if (type == COLOR_ALL_DIGITS)
		ft_putstr_fd("ERROR : ENTER A VALID COLOR FORMAT \"THE COLOR SHOULD \
				CONTAIN NUMBERS ONLY\"\n", 2);
}

void	ft_error_map_player(int type)
{
	if (type == STRANGE_CHAR_IN_MAP)
		ft_putstr_fd("ERROR : MAP [ 1 , 0 , N , W , W , S , \\t ,\
				' '] ARE THE ONLY ALLOWED CHARACTERS\n", 2);
	else if (type == PLAYER_OCCURENCE)
		ft_putstr_fd("ERROR : IT SHOULD BE ONLY ONE PLAYER ON THE MAP\n", 2);
	else if (type == EMPTY_LINE_ON_MAP)
		ft_putstr_fd("ERROR : EMPTY LINE IN THE MAP\n", 2);
	else if (type == TOP_MAP_ERR)
		ft_putstr_fd("ERROR : THE TOP OF THE MAP SHOULD BE CLOSED BY WALLS\
			 [ 1 ]\n", 2);
	else if (type == BUTTOM_MAP_ERR)
		ft_putstr_fd("ERROR : THE BUTTOM OF THE MAP SHOULD BE CLOSED BY \
		WALLS [ 1 ]\n", 2);
	else if (type == SIDES_MAP_ERR)
		ft_putstr_fd("ERROR : THE SIDES OF THE MAP SHOULD BE CLOSED BY \
		WALLS [ 1 ]\n", 2);
	else if (type == EMPTY_LINE_IN_MAP_GRID)
		ft_putstr_fd("ERROR : EMPTY LINE IN THE MAP GRID\n", 2);
	else if (type == PLAYER_BAD_POS)
		ft_putstr_fd("ERROR : PLAYER POS ERROR\n", 2);
	else if (type == CLIFF_FOUND)
		ft_putstr_fd("ERROR : CLIFF FOUND\n", 2);
}

int	ft_error(int type)
{
	if (type >= EXTENTION_ERROR && type <= BAD_ARG)
		ft_error_file(type);
	else if (type >= VISUAL_DATA_ERR && type <= COLOR_ALL_DIGITS)
		ft_error_visual_data(type);
	else if (type >= STRANGE_CHAR_IN_MAP && type <= CLIFF_FOUND)
		ft_error_map_player(type);
	return (EXIT_FAILURE);
}
