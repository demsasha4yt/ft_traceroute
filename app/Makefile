NAME = ft_traceroute

SRC = main.c input.c errors.c socket.c packet.c probes.c utils.c
CC = gcc

SRCDIR = src

OBJDIR = obj

OBJ = $(addprefix ${OBJDIR}/, $(SRC:.c=.o))

DEP = $(addprefix ${OBJDIR}/, $(SRC:.c=.d))

CFLAGS = -Wall -Wextra -Werror -g

LDFLAGS = -lm -L./lib/ft_net -L./lib/libft

INCLUDES = -I./lib/ft_net/includes -I./lib/libft/includes -Iincludes/ 

all: ${NAME}

libs:
	@make -C ./lib/ft_net
	@make -C ./lib/libft

${NAME}: libs ${OBJ}
	@${CC} ${CFLAGS} ${LDFLAGS} ${INCLUDES} -o $@ ${OBJ} -lft -lftnet

${OBJDIR}/%.o: ${SRCDIR}/%.c
	@/bin/mkdir -p ${OBJDIR}
	${CC} ${CFLAGS} ${INCLUDES} -c -o $@ $<

clean:
	make -C ./lib/ft_net clean
	make -C ./lib/libft clean
	@/bin/rm -Rf ${OBJDIR}

fclean: clean
	make -C ./lib/ft_net fclean
	make -C ./lib/libft fclean
	@/bin/rm -f ${NAME}
	@/bin/rm -Rf ${NAME}.dSYM

test:
	@${CC} -g ${INCLUDES} -I. -o ${NAME} $(addprefix src/, ${SRC})

re: fclean all
