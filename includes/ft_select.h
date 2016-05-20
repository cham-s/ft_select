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

# define KEY_UP		4283163
# define KEY_DOWN	4348699
# define KEY_LEFT	4479771
# define KEY_RIGHT	4414235
# define KEY_ESC	4414235
# define KEY_ENT	4325386
# define KEY_TAB	4325385
# define KEY_DEL	2117294875	
# define KEY_BKSPC	2117294875	
# define KEY_SPACE	2117271584	

// typedef	struct	s_opt
// {
// 	int		selected;
// 	int		over;
// 	int		visible;
// }				t_opt;

typedef struct	s_entry
{
	char			*line;
	int				hl;
	int				us;
	struct s_entry	*next;
	struct s_entry	*prev;
}				t_entry;

// typedef struct t_ent
// {
// 	int		pos;
// 	t_list	*list;
// 	int		*banned;
// 	char	**args;
// 	int		tablen;
// }				t_ent;

typedef	struct	s_entlist
{
	t_entry	*head;
	t_entry *tail;
	t_entry	*list;
	t_entry	*current;
	int		fd;
	int		wc;
	int		wl;
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

void	key_react(t_key *key, t_entlist *l);
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
void	init_raw_mode(void);
void	reset_default_mode(void);
void	lstprint(t_entlist *l);
// void	init_flags(t_opt *flags);
void	entry_destroy(t_entry *list);
void	getargs(int ac, char **av, t_entlist *l);
void	addentry(t_entlist *list, t_entry *new);
void	init_entlist(t_entlist *l, char **av, int ac);
t_entry	*newentry(char *str);
// void	init_ent(t_ent *e, char ** av);
int		launcher(t_entlist *l);

#endif
