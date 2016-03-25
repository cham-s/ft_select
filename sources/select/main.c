#include "ft_select.h"

int	ft_putc(int c)
{
	ft_putchar((char)c);
	return (0);
}

int	voir_touche(char **buffaddr, t_list **list)
{
	char buf[3];
	char	*cstr;
	char	*clstr;

	cstr = tgetstr("cm", buffaddr);
	clstr = tgetstr("cl", buffaddr);
	tputs(clstr, 1, ft_putc);
	ft_lstprint(list);
	while (1)
	{
		t_key *key;
		read(0, buf, KEY_BUFF_SIZE);
		key = getkey(buf);
		key_react(key);
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
	char			term_buffer[2048];
	char			*buffaddr;
	t_list			*list;


	signal(SIGWINCH, winsig);
	list = NULL;
	getargs(av, ac, &list);
	buffaddr = &term_buffer[0];
	init_term_data(&buffaddr);
	init_raw_mode();
	voir_touche(&buffaddr, &list);
	reset_default_mode();
	return (0);
}
