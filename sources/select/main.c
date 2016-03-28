#include "ft_select.h"

t_entry	newentry(int ac, char **av)
{
	t_entry *new;

	new = (t_entry)ft_memalloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->av = av;
	new->ac = av;
	new->selected = 0;
	new->visible = 0;
	new->over = 0;
}

void	lstprint(int ac, char **av)
{
	int i = 1;
	while (ac-- > 1)
	{
		ft_putendl(av[i]);
		i++;
	}
}

int	ft_putc(int c)
{
	ft_putchar(c);
	return (0);
}

int	launcher(int ac, char **av)
{
	char buf[3];
	int index;

	index = 1;
	ft_putstr(tgetstr("cl", NULL));
	ft_putstr(tgetstr("ho", NULL));
	lstprint(ac, av);
	ft_putstr(tgetstr("ho", NULL));
	while (1)
	{
		t_key *key;
		read(0, buf, KEY_BUFF_SIZE);
		key = getkey(buf);
		key_react(key, &index, ac, av);
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
//int	main(void)
{
	//use directly the av
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
