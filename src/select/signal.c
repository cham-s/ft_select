#include "ft_select.h"

void		signal_handler(int sig)
{
	t_entlist		*l;
	struct winsize	w;

	l = ret_entlist();
	if (sig == SIGINT)
		quit(l);
	else if (sig == SIGWINCH)
	{
		ioctl(l->fd, TIOCGWINSZ, &w);
		l->row = w.ws_row;
		l->col = w.ws_col;
		draw(l);
	}
}

void		sig_handle(void)
{
	int i;

	i = 1;
	while (i < 32)
		signal(i++, signal_handler);
}

