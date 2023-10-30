# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 16:54:22 by jlaazouz          #+#    #+#              #
#    Updated: 2023/10/29 19:57:18 by mbouyahy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_M = main.c

OBJS_M = ${ALL_SRCS:.c=.o}

PARSING_M =	${addprefix parsing/,check_colors_textures.c check_colors_textures_1.c\
						check_map.c checks_player.c error_logs.c fill_data.c parsing.c\
						parsing_utils_1.c parsing_utils_2.c parsing_utils_3.c read_map.c ft_check_textures.c}

SETUP_M =	${addprefix setup/,init_data.c}

DRAWING_M =	${addprefix drawing/,ray_casting.c minimap_utiles.c ray_casting_utiles.c draw_rays.c draw_utiles.c draw_walls.c minimap.c}

TEXTURING_M = ${addprefix texturing/,wall_texturing.c texturing_utils.c}

EVENTS_M =	${addprefix events/,key_events.c events_utiles.c keys.c mouse_events.c}

PARSING_O = ${PARSING_M:.c=.o}

SETUP_O = ${SETUP_M:.c=.o}

DRAWING_O = ${DRAWING_M:.c=.o}

TEXTURING_O = ${TEXTURING_M:.c=.o}

EVENTS_O = ${EVENTS_M:.c=.o}

ALL_SRCS = ${SRCS_M} ${PARSING_M} ${SETUP_M} ${DRAWING_M} ${TEXTURING_M} ${EVENTS_M} 

NAME = cub3D

LIBFT = libft/libft.a

CC = cc 

CFLAGS = -Wall -Wextra -Werror -ffast-math

RM = rm -rf

all : ${NAME}

${NAME} : ${OBJS_M} ${PARSING_O} ${SETUP_O} ${DRAWING_O} ${TEXTURING_O} ${EVENTS_O}
	@make -C libft
	${CC} ${CFLAGS} ${ALL_SRCS}  -lmlx -framework OpenGL -framework AppKit ${LIBFT} -o ${NAME}
clean:
	${RM} ${OBJS_M} 
	${MAKE} -C libft clean

fclean: clean
	${RM} ${NAME}
	${MAKE} -C libft fclean

re: fclean all

.PHONY: all bonus clean fclean re ${LIBFT}
