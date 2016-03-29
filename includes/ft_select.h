#ifndef FT_SELECT_H
# define FT_SELECT_H
# include <curses.h>
# include <term.h>
# include <termios.h>
# include <sys/ioctl.h>
# include <fcntl.h>
# include <signal.h>
# include "libft.h"
# include "key.h"
# define MAX_KEY_LENGTH 5
# define CLEAR_SCREEN	ft_putstr(tgetstr("cl", NULL))
# define GO_HOME		ft_putstr(tgetstr("ho", NULL))
# define GO_UP			ft_putstr(tgetstr("up", NULL))
# define GO_DOWN		ft_putstr(tgetstr("do", NULL))
# define UNDERLINE		ft_putstr(tgetstr("us", NULL))
# define ENDUNDER		ft_putstr(tgetstr("ue", NULL))
# define TURNOFFALL		ft_putstr(tgetstr("me", NULL))
# define REVERSEVIDEO	ft_putstr(tgetstr("mr", NULL))

typedef	struct	s_opt
{
	int		selected;
	int		over;
	int		visible;
}				t_opt;

typedef struct	s_entry
{
	char			*line;
	t_opt			*flags;
	struct s_entry	*next;
	struct s_entry	*prev;
}				t_entry;

void	init_term_data();
void	interrogate_term(void);
void	getargs(char **av, int ac, t_list **list);
void	init_raw_mode(void);
void	reset_default_mode(void);
void	lstprint(t_entry **list);
void	init_flags(t_opt *flags);
void	entry_destroylist(t_entry *list);
void	filllist(int ac, char **av, t_entry **list);
void	addentry(t_entry **list, t_entry *new);
t_entry	*newentry(char *str);
void	key_react(t_key *key, t_entry *list);

#endif
