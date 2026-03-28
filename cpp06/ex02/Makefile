NAME = identify
CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp Base.cpp Functions.cpp

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CPPFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
