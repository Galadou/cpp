NAME = BraiiiiiiinnnzzzZ

SRCS = 	main.cpp\
		newZombie.cpp\
		randomChump.cpp\
		Zombie.cpp

OBJS=$(SRCS:.cpp=.o)

RM =rm -f

COMP = c++

CFLAGS= -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME) : $(OBJS)
	$(COMP) $(CFLAGS) $(OBJS) -o $@
	@if [ $$? -eq 0 ]; then \
		echo "\033[32;1mCompilation successful!\033[0m"; \
	fi

%.o: %.cpp
	$(COMP) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re