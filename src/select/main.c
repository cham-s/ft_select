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
	init_raw_mode(&l, &default_term);
	init_entlist(&l, av, ac);
	launcher(&l);
	ft_putstr(tgetstr("ve", NULL));
	ft_putstr(tgetstr("te", NULL));
	reset_default_mode(&l, &default_term);
	printf_selected(&l);
	entry_destroy(l.list);
	return (EXIT_SUCCESS);
}
