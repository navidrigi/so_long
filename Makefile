CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
SRC_FILES	=	main.c registering_escape.c \
				cleanup.c utils.c read_map.c get_next_line.c \
				get_next_line_utils.c move_player.c map_checking.c \
				checkings.c ft_itoa.c valid_path.c errors.c
OBJ_FILES 	=	$(SRC_FILES:.c=.o)
NAME		=	so_long

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

.PHONY: all clean fclean re

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
