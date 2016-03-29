NAME = ft_select 
CC = clang
LIB = libft/libft.a -ltermcap
FLAGS = -g -Wall -Werror -Wextra
INCLUDES = -I includes -I libft/includes
OBJS = init_entry.o main.o init_term.o parser.o attr.o nor_key.o dir_key.o init_key.o
.PHONY: all clean fclean re

VPATH = sources/term:sources/select:sources/key

all: $(NAME)

$(NAME): $(OBJS) $(LIB)
	$(CC) $(FLAGS) $(INCLUDES) $(OBJS) $(LIB) -o $(NAME)

$(LIB):
	make -C libft/

%.o : %.c 
	$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@ 

clean:
	rm -f $(OBJS)

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)
	rm -rf $(NAME).dsym

re: fclean all
