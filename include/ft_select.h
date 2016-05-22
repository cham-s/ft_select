#ifndef FT_SELECT_H
# define FT_SELECT_H
# include <curses.h>
# include <term.h>
# include <termios.h>
# include <sys/ioctl.h>
# include <fcntl.h>
# include <signal.h>
# include "libft.h"
# define MAX_KEY_LENGTH 5
# define CL				tgetstr("cl", NULL)
# define HO				tgetstr("ho", NULL)
# define UP				tgetstr("up", NULL)
# define DO				tgetstr("do", NULL)
# define US				tgetstr("us", NULL)
# define UE				tgetstr("ue", NULL)
# define ME				tgetstr("me", NULL)
# define MR				tgetstr("mr", NULL)
# define VI				tgetstr("vi", NULL)
# define VE				tgetstr("ve", NULL)
# define CD				tgetstr("cd", NULL)
# define CE				tgetstr("ce", NULL)
# define CM				tgetstr("cm", NULL)
# define TI				tgetstr("cm", NULL)
# define TE				tgetstr("te", NULL)
# define GOTO(c, l)		tgoto(CM, c, l)

# define K_UP		4283163
# define K_DOWN		4348699
# define K_LEFT		4479771
# define K_RIGHT	4414235
# define K_ESC		27
# define K_ENT		10
# define K_TAB		9
# define K_DEL		2117294875
# define K_BKSPC	127
# define K_SPACE	32

typedef struct	s_entry
{
	char			*line;
	int				hl;
	int				us;
	struct s_entry	*next;
	struct s_entry	*prev;
}				t_entry;

typedef	struct	s_entlist
{
	t_entry	*head;
	t_entry *tail;
	t_entry	*list;
	t_entry	*current;
	int		fd;
	int		wc;
	int		wl;
	int		ac;
}				t_entlist;

void	init_raw_mode(t_entlist *l, struct termios *old);
void	reset_default_mode(t_entlist *l, struct termios *old);
void	init_term_data(t_entlist *l);
void	entry_destroy(t_entry *list);
void	getargs(int ac, char **av, t_entlist *l);
void	addentry(t_entlist *list, t_entry *new);
void	init_entlist(t_entlist *l, char **av, int ac);
t_entry	*newentry(char *str);
int		launcher(t_entlist *l);
void	draw(t_entlist *l);
void	set_draw(t_entlist *l);
void	printf_selected(t_entlist *l);

#endif
