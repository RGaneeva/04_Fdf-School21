NAME = libft.a

FLAGS = -Wall -Wextra -Werror

SRC = ft_atoi.c ft_maximum.c ft_module.c ft_numb_count.c \
		ft_putchar.c ft_putstr.c ft_split.c get_next_line.c \
		ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_strnew.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o:%.c
	@gcc $(FLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re:	fclean all

.PHONY: all, clean, fclean, re