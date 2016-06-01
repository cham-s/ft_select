/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 16:53:36 by cattouma          #+#    #+#             */
/*   Updated: 2016/06/01 16:13:27 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		sig_stp(t_entlist *l)
{
	char	buff[2];

	buff[0] = 032;
	buff[1] = '\0';
	if (isatty(1))
	{
		signal(SIGTSTP, SIG_DFL);
		ft_putstr_fd(tgetstr("ve", NULL), l->fd);
		ft_putstr_fd(tgetstr("te", NULL), l->fd);
		ioctl(0, TIOCSTI, buff);
		reset_default_mode(&l->old_term);
	}
	else
	{
		ft_putendl_fd("Not a terminal device", 2);
		exit(EXIT_FAILURE);
	}
}

static void		sig_cont(t_entlist *l)
{
	ft_putstr_fd(tgetstr("vi", NULL), l->fd);
	ft_putstr_fd(tgetstr("ti", NULL), l->fd);
	signal(SIGTSTP, sig_handler);
	init_raw_mode(&l->old_term);
	draw(l);
}

void			sig_handler(int sig)
{
	t_entlist		*l;
	struct winsize	w;

	l = ret_entlist();
	if (sig == SIGWINCH)
	{
		ioctl(l->fd, TIOCGWINSZ, &w);
		l->height = w.ws_row;
		l->width = w.ws_col;
		l->row = l->height - START - PAD;
		l->col = l->width - SPACE * 2;
		draw(l);
	}
	else if (sig == SIGTSTP)
		sig_stp(l);
	else if (sig == SIGCONT)
		sig_cont(l);
	else
		quit(l);
}

void			signals(void)
{
	int i;

	i = 1;
	while (i < MAX_SIGNAL)
	{
		signal(i, sig_handler);
		i++;
	}
}
