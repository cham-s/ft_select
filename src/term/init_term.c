#include "ft_select.h"

void	init_term_data(t_entlist *l)
{
	char	*termtype;
	int		success;
	char	*term_buffer;

	term_buffer = NULL;
	if (!isatty(l->fd))
	{
		ft_putendl_fd("Not a terminal device", 2);
		exit(EXIT_FAILURE);
	}
	termtype = getenv("TERM");
	if (termtype == 0)
	{
		ft_putendl_fd("Specify a terminal type in the env.", 2);
		exit(EXIT_FAILURE);
	}
	success = tgetent(term_buffer, termtype);
	if (success < 0)
	{
		ft_putstr_fd("The termtype ", 2);
		ft_putstr_fd(termtype, 2);
		ft_putendl_fd(" is not a valid.", 2);
		exit(EXIT_FAILURE);
	}
}
