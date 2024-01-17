CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
SRC_FILES	=	main.c registering_escape.c \
				cleanup.c utils.c read_map.c get_next_line.c \
				get_next_line_utils.c move_player.c map_checking.c \
				checkings.c ft_itoa.c valid_path.c errors.c
OBJ_DIR     =   obj
OBJ_FILES 	=	$(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))
NAME		=	so_long

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -Lmlx -lmlx -lX11 -lXext -o $(NAME)

.PHONY: all clean fclean re

clean:
	rm -f $(OBJ_FILES)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
