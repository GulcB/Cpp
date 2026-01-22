NAME = aAnimal
CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp AAnimal.cpp Brain.cpp Cat.cpp Dog.cpp WrongCat.cpp WrongAnimal.cpp

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CPPFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re