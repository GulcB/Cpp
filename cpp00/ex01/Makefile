NAME = phonebook
CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = phonebook.cpp

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CPPFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re