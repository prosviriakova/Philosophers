NAME    = philo

SRCDIR  = src/
OBJDIR  = obj/
INCDIR  = include/

SRC     = src/main.c
OBJ     = $(SRC:$(SRCDIR)%.c=$(OBJDIR)%.o)

CC      = cc
CFLAGS  = -Wall -Wextra -Werror -pthread

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -I $(INCDIR) -o $(NAME) $(OBJ) 

$(OBJDIR)%.o: $(SRCDIR)%.c $(INCDIR)philo.h
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
