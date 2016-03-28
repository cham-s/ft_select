#ifndef KEY_H
# define KEY_H
# include "ft_select.h" 
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

void	key_destroy(t_key *key);
//void	key_react(t_key *key, int *index, char **av);
void	key_react(t_key *key, int *index,int ac, char **av);
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
#endif
