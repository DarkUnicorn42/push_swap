NAME = push_swap.a

SOURCES = push_swap.c  src/ft_strlen.c \

OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rcs $(NAME) $(OBJECTS)

clean:
	@rm -f $(OBJECTS)
	
fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
