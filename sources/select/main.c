#include "ft_select.h"

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

int	launcher(int ac, char **av)
{
	char		buf[MAX_KEY_LENGTH];
	t_entlist	l;

	init_entlist(&l);
	filllist(ac, av, &l.list);
	l.head = l.list;
	CLEAR_SCREEN;
	GO_HOME;
	lstprint(&l.list);
	GO_HOME;
	while (1)
	{
		t_key *key;
		read(0, buf, MAX_KEY_LENGTH);
		key = getkey(buf);
		key_react(key, &l);
		key_destroy(key);
	}
	entry_destroylist(l.list);
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
	if (!(ac > 1))
	{
		ft_putendl_fd("usage: ./ft_select args[...]", 2);
		exit(EXIT_FAILURE);
	}
	signal(SIGWINCH, winsig);
	init_term_data();
	init_raw_mode();
	launcher(ac, av);
	reset_default_mode();
	return (0);
}
