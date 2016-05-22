#include "ft_select.h"

void	set_draw(t_entlist *l)
{
	if (l->head)
		l->head->us = 1;
}

void	draw(t_entlist *l)
{
	t_entry *tmp;

	tmp = l->head;
	ft_putstr_fd(tgetstr("cl", NULL), l->fd);
	while (tmp)
	{
		if (tmp->us)
			ft_putstr_fd(tgetstr("us", NULL), l->fd);
		if (tmp->hl)
			ft_putstr_fd(tgetstr("mr", NULL), l->fd);
		ft_putendl_fd(tmp->line, l->fd);
		ft_putstr_fd(tgetstr("me", NULL), l->fd);
		tmp = tmp->next;
	}
}

void	print_selected(t_entlist *l)
{
	t_entry		*tmp;
	static int	i = 0;

	i = 0;
	ft_putstr_fd(ME,l->fd);
	tmp = l->head;
	while (tmp)
	{
		if (tmp->hl)
		{
			if (i++ != 0)
				ft_putchar(' ');
			ft_putstr(tmp->line);
		}
		tmp = tmp->next;
	}
}
