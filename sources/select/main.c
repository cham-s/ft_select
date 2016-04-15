#include "ft_select.h"

int	tab_len(char **tabl)
{
	int i;

	i = 0;
	while (tabl[i])
		i++;
	return (i);
}

void	tab_free(char **tabl)
{
	int i;

	i = 0;
	while (tabl[i])
	{
		free(tabl[i]);
		i++;
	}
	free(tabl);
}

char	**tabdup(char **str)
{
	char	**new;
	size_t	len;
	int		i;

	len = ft_tablen(str);
	new = (char **)malloc(sizeof(char *) * len + 1);
	if (!new)
		return NULL;
	i = 0;
	while (len--)
	{
		new[i] = ft_strdup(str[i]);
		i++;
	}
	new[i] = NULL;
	return (new);
}

void	init_flags(t_opt *flags)
{
	flags->selected = 0;
	flags->visible = 0;
	flags->over = 0;
}

int	ft_putc(int c)
{
	ft_putchar(c);
	return (0);
}

int	launcher(t_ent *e)
{
	char		buf[MAX_KEY_LENGTH];

	int i = 0;
	//CLEAR_SCREEN;
	ft_putstr(tgetstr("us", NULL));
	ft_putstr(e->args[i++]);
	ft_putstr(tgetstr("ue", NULL));
	ft_putstr(tgetstr("do", NULL));
	//GO_HOME;
	while (i < e->tablen)
	{
		ft_putendl(e->args[i]);
		i++;
	}
	GO_HOME;
	while (1)
	{
		t_key *key;
		read(0, buf, MAX_KEY_LENGTH);
		key = getkey(buf);
		key_react(key, e);
		key_destroy(key);
	}
	return (0);
}


void winsig(int sig)
{
	struct winsize w;

	ioctl(0, TIOCGWINSZ, &w);
	if (sig == SIGWINCH)
	{
		ft_putnbr(w.ws_row);
		ft_putendl("");
		ft_putnbr(w.ws_col);
		ft_putendl("");
	}
}

int	main(int ac, char **av)
{
	t_ent e;
	if (!(ac > 1))
	{
		ft_putendl_fd("usage: ./ft_select args[...]", 2);
		exit(EXIT_FAILURE);
	}
	//signal(SIGWINCH, winsig);
	init_term_data();
	init_raw_mode();
	ft_putstr(tgetstr("ti", NULL));
	e.pos = 0;
	av++;
	e.args = tabdup(av);
	e.tablen = tab_len(e.args);
	launcher(&e);
	tab_free(e.args);
	reset_default_mode();
	ft_putstr(tgetstr("te", NULL));
	return (0);
}
