SRCS =	main.c ./drawing/check_map.c ./Get_next_line/get_next_line.c \
			./Get_next_line/get_next_line_utils.c ./drawing/draw_img.c\
			./drawing/utiles.c ./setup/init_data.c ./events/key_event.c

OBJS =	${SRCS:.c=.o}

NAME =	Cub3d

RM =	rm -f

CC =	cc

FLAGS =	-Wall -Wextra -Werror -fsanitize=address

MFLAGS	= -lmlx -framework OpenGL -framework AppKit

%.o: %.c
	${CC} ${FLAGS} -c $< -o $@

${NAME}: ${OBJS}
		 ${CC} -o ${NAME} ${OBJS} ${FLAGS} ${MFLAGS}

all: ${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re