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
# define CLEAR_SCREEN	ft_putstr(tgetstr("cl", NULL))
# define GO_HOME		ft_putstr(tgetstr("ho", NULL))
# define GO_UP			ft_putstr(tgetstr("up", NULL))
# define GO_DOWN		ft_putstr(tgetstr("do", NULL))
# define UNDERLINE		ft_putstr(tgetstr("us", NULL))
# define ENDUNDER		ft_putstr(tgetstr("ue", NULL))
# define TURNOFFALL		ft_putstr(tgetstr("me", NULL))
# define REVERSEVIDEO	ft_putstr(tgetstr("mr", NULL))
# define KEY_C_CTRL_D			0
# define KEY_C_TAB				1
# define KEY_C_UP				2
# define KEY_C_DOWN				3
# define KEY_C_RIGHT			4
# define KEY_C_LEFT				5
# define KEY_C_SPACE			6
# define KEY_C_RETURN			7
# define KEY_C_ESCAPE			8
# define KEY_C_DELETE			9
# define KEY_C_BACKSPACE		10	
# define KEY_C_NONE				-1

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
	struct s_entry	*head;
	struct s_entry	*next;
	struct s_entry	*prev;
}				t_entry;

typedef	struct	s_entlist
{
	t_entry	*head;
	t_entry	*list;
}				t_entlist;

typedef	struct	s_key
{
	char	*str;
	int		type;
}				t_key;

typedef struct	s_functs_tab
{
	int		type;
	int		(*f)(const char *buffkey);
}				t_functs_tab;

void	key_react(t_key *key, t_entlist *list);
void	key_destroy(t_key *key);
t_key	*getkey(const char *keybuff);
t_key	*newkey(int keytype, const char *buffkey);
t_key	*getkey(const char *keybuff);
int		key_is_down_arrow(const char *buffkey);
int		key_is_up_arrow(const char *buffkey);
int		key_is_left_arrow(const char *buffkey);
int		key_is_right_arrow(const char *buffkey);
int		key_is_escape(const char *buffkey);
int		key_is_space(const char *buffkey);
int		key_is_return(const char *buffkey);
int		key_is_ctrl_d(const char *buffkey);
int		key_is_tab(const char *buffkey);
int		key_is_backspace(const char *buffkey);
int		key_is_delete(const char *buffkey);
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
void	init_entlist(t_entlist *l);
t_entry	*newentry(char *str);

#endif
