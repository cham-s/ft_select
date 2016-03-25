#ifndef FT_SELECT_H
# define FT_SELECT_H
# include <curses.h>
# include <term.h>
# include <termios.h>
# include <sys/ioctl.h>
# include <signal.h>
# include "libft.h"
# include "key.h"
# define KEY_BUFF_SIZE 3

void	init_term_data(char **term_buffer);
void	interrogate_term(void);
void	getargs(char **av, int ac, t_list **list);
void	init_raw_mode(void);
void	reset_default_mode(void);

#endif
