NAME = fdf

FLAGS = -Wall -Wextra -Werror

FRAMES = -framework OpenGL -framework AppKit

SRC = main.c map_reading.c drawing.c

INCLUDES = libft/libft.a minilibx_macos/libmlx.a

all:
	@make -C libft/ all
	@make -C minilibx_macos/ all
	gcc $(SRC) -o $(NAME) $(FLAGS) $(INCLUDES) $(FRAMES)

clean:
	@make -C libft/ clean
	@make -C minilibx_macos/ clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re