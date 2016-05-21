NAME		= ft_select 
CC 			= clang
OBJDIR		= obj
LIB			= libft/libft.a 
FLAGS		= -Wall -Werror -Wextra
INCLUDES	= -I includes -I libft/includes
INC			=
OBJS 		=	$(OBJDIR)/main.o\
			   	$(OBJDIR)/init_term.o\
			   	$(OBJDIR)/parser.o\
			   	$(OBJDIR)/attr.o\
			   	$(OBJDIR)/init_entry.o\
			   	$(OBJDIR)/launcher.o \

.PHONY: all clean fclean re

VPATH = src/select:src/term

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
