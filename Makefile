NAME		= ft_select 
CC 			= clang
OBJDIR		= obj
LIB			= libft/libft.a 
FLAGS		= -Wall -Werror -Wextra
INCLUDES	= -I include -I libft/includes
INC			= include/ft_select.h
OBJS 		=	$(OBJDIR)/main.o\
			   	$(OBJDIR)/init_term.o\
			   	$(OBJDIR)/parser.o\
			   	$(OBJDIR)/attr.o\
			   	$(OBJDIR)/draw.o\
			   	$(OBJDIR)/init_entry.o\
			   	$(OBJDIR)/launcher.o \
			   	$(OBJDIR)/signal.o \

.PHONY: all clean fclean re

VPATH = src/select:src/term

all: $(NAME)

$(NAME): $(LIB) $(OBJS) 
	$(CC) $(FLAGS) $(INCLUDES) $(OBJS) $(LIB) -o $(NAME) -ltermcap

$(LIB):
	make -C libft/

$(OBJDIR)/%.o : %.c $(INC)
	@mkdir -p $(OBJDIR)
	$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@ 

clean:
	rm -rf $(OBJDIR)

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)
	rm -rf $(NAME).dsym

re: fclean all
