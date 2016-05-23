/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 16:33:33 by cattouma          #+#    #+#             */
/*   Updated: 2016/05/23 16:33:52 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	t_entlist	l;
	//use malloc instead
	check_args(ac);
	if ((l.fd = open("/dev/tty", O_WRONLY)) < 0)
	{
		ft_putendl_fd("failed to open terminal device", 2);
		exit(EXIT_FAILURE);
	}
	init_term_data(&l);
	init_raw_mode(&l.old_term);
	init_entlist(&l, av, ac);
	launcher(&l);
	reset_default_mode(&l.old_term);
	print_selected(&l);
	entry_destroy(&l);
	return (EXIT_SUCCESS);
}
