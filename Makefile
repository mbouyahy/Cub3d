SRCS =	main.c ./drawing_functions/check_map.c ./Get_next_line/get_next_line.c \
			./Get_next_line/get_next_line_utils.c ./drawing_functions/draw_img.c

OBJS =	${SRCS:.c=.o}

NAME =	Cup3d

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