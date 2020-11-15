NAME = ft_traceroute

SRC = main.c

CC = gcc

SRCDIR = src

OBJDIR = obj

OBJ = $(addprefix ${OBJDIR}/, $(SRC:.c=.o))

DEP = $(addprefix ${OBJDIR}/, $(SRC:.c=.d))

CFLAGS = -Wall -Wextra -Werror -g

LDFLAGS = -lm -L./lib/ft_net -lftnet

INCLUDES = -I./lib/ft_net/includes -Iincludes/ 

all: ${NAME}

ft_net:
	make -C ./lib/ft_net

${NAME}: ft_net ${OBJ}
	@${CC} ${CFLAGS} ${LDFLAGS} ${INCLUDES} -o $@ ${OBJ}

${OBJDIR}/%.o: ${SRCDIR}/%.c
	/bin/mkdir -p ${OBJDIR}
	${CC} ${CFLAGS} ${INCLUDES} -c -o $@ $<

clean:
	make -C ./lib/ft_net clean
	@/bin/rm -Rf ${OBJDIR}

fclean: clean
	make -C ./lib/ft_net fclean
	@/bin/rm -f ${NAME}
	@/bin/rm -Rf ${NAME}.dSYM

test:
	@${CC} -g ${INCLUDES} -I. -o ${NAME} $(addprefix src/, ${SRC})

re: fclean all
