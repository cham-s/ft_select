NAME = ft_select 
CC = clang
OBJDIR = obj
LIB = libft/libft.a 
FLAGS = -g -Wall -Werror -Wextra
INCLUDES = -I includes -I libft/includes
OBJS = $(OBJDIR)/main.o\
	   $(OBJDIR)/init_term.o\
	   $(OBJDIR)/parser.o\
	   $(OBJDIR)/attr.o\
	   $(OBJDIR)/nor_key.o\
	   $(OBJDIR)/dir_key.o\
	   $(OBJDIR)/init_key.o\
	   $(OBJDIR)/init_entry.o\
	   $(OBJDIR)/launcher.o \

.PHONY: all clean fclean re

VPATH = sources/term:sources/select:sources/key

all: $(NAME)

$(NAME): $(LIB) $(OBJS) 
	$(CC) $(FLAGS) $(INCLUDES) $(OBJS) $(LIB) -o $(NAME) -ltermcap

$(LIB):
	make -C libft/

$(OBJDIR)/%.o : %.c 
	@mkdir -p $(OBJDIR)
	$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@ 

clean:
	rm -rf $(OBJDIR)

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)
	rm -rf $(NAME).dsym

re: fclean all
