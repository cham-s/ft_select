#include "ft_select.h"

void	init_terminal_data(char **term_buffer)
{
	char	*termtype;
	int		success;

	termtype = getenv("TERM");
	if (termtype == 0)
	{
		ft_putendl_fd("Specify a terminal whith setenv TERM <your type>", 2);
		exit(EXIT_FAILURE);
	}
	success = tgetent(*term_buffer, termtype);
	if (success == 0)
	{
		ft_putendl_fd("The termtype specified is not defined", 2);
		exit(EXIT_FAILURE);
	}
}

void	interrogate_terminal(void)
{
	int		height;
	int		width;

	height = tgetnum("li");
	width = tgetnum("co");

	ft_putnbr(height);
	ft_putendl("");
	ft_putnbr(width);
	ft_putendl("");
}
