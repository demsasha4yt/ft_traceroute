NAME = libftnet.a

INCLUDE_DIR = ./includes
FLAGS = -Wall -Wextra -Werror
CFLAGS = -I $(INCLUDE_DIR)
DEBUG_FLAGS = -g

SRCS =	src/gettime.c \
		src/print_by_byte.c \
		src/in_cksum.c \
		src/packet_create.c \
		src/packet_destroy_buffer.c \
		src/packet_destroy_message.c \
		src/packet_destroy.c \
		src/packet_hdr_icmp.c \
		src/packet_hdr_ip.c \
		src/packet_hdr_udp.c \
		src/packet_set_message.c \
		src/packet_get_hdr_len.c \
		src/packet_debug.c \
		src/packet_calc.c \
		src/packet_cksums.c \
		src/socket_close.c \
		src/socket_create.c \
		src/socket_send_row.c \
		src/socket_settimeout.c \
		
OBJS = $(patsubst %.c,%.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o: %.c
	gcc $(FLAGS) $(DEBUG_FLAGS) $(CFLAGS) -o $@ -c $< 

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

TEST_SRCS = test/main.c \
			test/testpacket_allocfree.c \
			test/testpacket_iphdr.c \

TEST_OBJS = $(patsubst %.c,%.o, $(TEST_SRCS))

test: re $(TEST_OBJS)
	gcc -g -o testmain $(TEST_OBJS) -I includes -L. -lftnet
	@echo "\n\n\n"
