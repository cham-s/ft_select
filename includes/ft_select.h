#ifndef FT_SELECT_H
# define FT_SELECT_H
# include <curses.h>
# include <term.h>
# include <termios.h>
# include "libft.h"

void	init_terminal_data(char **term_buffer);
void	interrogate_terminal(void);

#endif
