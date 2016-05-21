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
	//fd
	ft_putstr_fd(tgetstr("cl", NULL), l->fd);
	while (tmp)
	{
		if (tmp->us)
			ft_putstr(tgetstr("us", NULL));
		if (tmp->hl)
			ft_putstr(MR);
		ft_putendl(tmp->line);
		ft_putstr(ME);
	tmp = tmp->next;
	}
}
