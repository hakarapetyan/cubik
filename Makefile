NAME = cub3D

RM = rm -f

CFLAGS = -Wall -Wextra  -g3 #-fsanitize=address

SRCS = main.c\
		open_read.c\
		ft_split.c\
		./get_next_line/get_next_line.c\
		./get_next_line/get_next_line_utils.c\
		utils.c\
		utils2.c\
		utils3.c\
		init_struct.c\
		texture_validation.c\
		map_validation.c\
		during_validation.c\
		start_validation.c\
		walls.c


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) cub.h
	cc $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re