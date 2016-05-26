#include "ft_select.h"
void	ctrl_z(int sig, t_entlist *l)
{
	char	ctrl_z[2];

	ctrl_z[0] = 032;
	ctrl_z[1] = '\0';
	if (sig == SIGTSTP && isatty(1))
	{
		signal(SIGTSTP, SIG_DFL);
		ft_putstr_fd(tgetstr("ve", NULL), l->fd);
		ft_putstr_fd(tgetstr("te", NULL), l->fd);
		ft_putstr_fd(tgetstr("cl", NULL), l->fd);
		reset_default_mode(&l->old_term);
		ioctl(0, TIOCSTI, ctrl_z);
	}
	else if (sig == SIGCONT)
	{
		signal(SIGTSTP, sig_handler);
		init_raw_mode(&l->old_term);
		draw(l);
	}
}

void		sig_handler(int sig)
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
	else if (sig == SIGTSTP || sig == SIGCONT)
		ctrl_z(sig, l);
	else
		quit(l);
}


void		signals(void)
{
	int i;

	i = 1;
	while (i < MAX_SIGNAL)
	{
		signal(i, sig_handler);
		i++;
	}
}

