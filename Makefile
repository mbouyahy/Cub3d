NAME = cub3D
NAME_B = cub3D_bonus
LIBFT = libft/libft.a
MLX = -Wunreachable-code -O3
M = ./mandatory/
B = bonus/

PARSING_M =	${addprefix ${M}parsing/,check_colors_textures.c check_colors_textures_1.c\
						check_map.c checks_player.c error_logs.c fill_data.c parsing.c\
						parsing_utils_1.c parsing_utils_2.c parsing_utils_3.c read_map.c ft_check_textures.c}
SETUP_M =	${addprefix ${M}setup/,init_data.c}
DRAWING_M =	${addprefix ${M}drawing/,ray_casting.c ray_casting_init.c ray_casting_utiles.c draw_rays.c draw_utiles.c draw_walls.c}
TEXTURING_M = ${addprefix ${M}texturing/,wall_texturing.c texturing_utils.c}
EVENTS_M =	${addprefix ${M}events/,key_events.c events_utiles.c keys.c mouse_events.c}

PARSING_O = ${PARSING_M:.c=.o}
SETUP_O = ${SETUP_M:.c=.o}
DRAWING_O = ${DRAWING_M:.c=.o}
TEXTURING_O = ${TEXTURING_M:.c=.o}
EVENTS_O = ${EVENTS_M:.c=.o}
ALL_SRCS_M = ${M}main.c ${PARSING_M} ${SETUP_M} ${DRAWING_M} ${TEXTURING_M} ${EVENTS_M} 
ALL_OBJ_M = ${M}main.o ${PARSING_O} ${SETUP_O} ${DRAWING_O} ${TEXTURING_O} ${EVENTS_O}


PARSING_B =	${addprefix ${B}parsing_bonus/,check_colors_textures_bonus.c check_colors_textures_1_bonus.c\
						check_map_bonus.c checks_player_bonus.c error_logs_bonus.c fill_data_bonus.c parsing_bonus.c\
						parsing_utils_1_bonus.c parsing_utils_2_bonus.c parsing_utils_3_bonus.c read_map_bonus.c ft_check_textures_bonus.c}
SETUP_B =	${addprefix ${B}setup_bonus/,init_data_bonus.c}
DRAWING_B =	${addprefix ${B}drawing_bonus/,ray_casting_bonus.c minimap_utiles_bonus.c ray_casting_init_bonus.c\
						ray_casting_utiles_bonus.c draw_rays_bonus.c draw_utiles_bonus.c draw_walls_bonus.c minimap_bonus.c}
TEXTURING_B = ${addprefix ${B}texturing_bonus/,wall_texturing_bonus.c texturing_utils_bonus.c}
EVENTS_B =	${addprefix ${B}events_bonus/,key_events_bonus.c events_utiles_bonus.c keys_bonus.c mouse_events_bonus.c}
PARSING_O_B = ${PARSING_B:.c=.o}
SETUP_O_B = ${SETUP_B:.c=.o}
DRAWING_O_B = ${DRAWING_B:.c=.o}
TEXTURING_O_B = ${TEXTURING_B:.c=.o}
EVENTS_O_B = ${EVENTS_B:.c=.o}
ALL_SRCS_B = ${B}main_bonus.c ${PARSING_B} ${SETUP_B} ${DRAWING_B} ${TEXTURING_B} ${EVENTS_B}
ALL_OBJ_B = ${B}main_bonus.o ${PARSING_O_B} ${SETUP_O_B} ${DRAWING_O_B} ${TEXTURING_O_B} ${EVENTS_O_B}

CFLAGS = -Wall -Wextra -Werror -ffast-math -O3 #-fsanitize=address -g

all : $(NAME)

bonus : ${NAME_B}

$(NAME) : ${M}main.o ${PARSING_O} ${SETUP_O} ${DRAWING_O} ${TEXTURING_O} ${EVENTS_O} ${M}cub.h
	@make -C libft
	@$(CC) $(CFLAGS) $(ALL_SRCS_M) /Users/${USER}/Desktop/MLX42/build/libmlx42.a -Iinclude -lglfw -L"/Users/${USER}/homebrew/Cellar/glfw/3.3.8/lib" ${LIBFT} -o $(NAME)


$(NAME_B) : ${B}main_bonus.o ${PARSING_O_B} ${SETUP_O_B} ${DRAWING_O_B} ${TEXTURING_O_B} ${EVENTS_O_B} ${B}cub_bonus.h
	@make -C libft
	@$(CC) $(CFLAGS) $(ALL_SRCS_B) /Users/${USER}/Desktop/MLX42/build/libmlx42.a -Iinclude -lglfw -L"/Users/${USER}/homebrew/Cellar/glfw/3.3.8/lib" ${LIBFT} -o $(NAME_B)


clean:
	${RM} ${ALL_OBJ_M} ${ALL_OBJ_B}
	${MAKE} -C libft clean

fclean: clean
	${RM} ${NAME} ${NAME_B} 
	${MAKE} -C libft fclean

re: fclean all

re_bonus: fclean bonus

.PHONY: all bonus clean fclean re re_bonus ${LIBFT}
