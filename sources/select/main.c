#include "ft_select.h"


int	ft_putc(int c)
{
	ft_putchar(c);
	return (0);
}

void	check_args(int ac)
{
	if (!(ac > 1))
	{
		ft_putendl_fd("usage: ./ft_select args[...]", 2);
		exit(EXIT_FAILURE);
	}
}

int	main(int ac, char **av)
{
	t_entlist l;

	//use malloc instead
	init_term_data();
	init_raw_mode();
	ft_putstr(tgetstr("ti", NULL));
	init_entlist(&l, av, ac);
	launcher(&l);
	entry_destroy(l.list);
	reset_default_mode();
	ft_putstr(tgetstr("te", NULL));
	return (EXIT_SUCCESS);
}
