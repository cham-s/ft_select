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
	t_entlist			l;
	struct termios		default_term;	
	//use malloc instead
	check_args(ac);
	if ((l.fd = open("/dev/tty", O_WRONLY)) < 0)
	{
		ft_putendl_fd("failed to open terminal device", 2);
		exit(EXIT_FAILURE);
	}
	init_term_data(&l);
	init_raw_mode(&default_term);
	init_entlist(&l, av, ac);
	launcher(&l);
	reset_default_mode(&default_term);
	print_selected(&l);
	//entry_destroy(&l);
	return (EXIT_SUCCESS);
}
