#include "ft_select.h"

void	set_draw(t_entlist *l)
{
	ft_putstr(tgetstr("vi", NULL));
	ft_putstr(tgetstr("ti", NULL));
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
			ft_putstr_fd(tgetstr("us", NULL), l->fd);
		if (tmp->hl)
			ft_putstr(MR);
		ft_putendl_fd(tmp->line, l->fd);
		ft_putstr_fd(ME,l->fd);
		tmp = tmp->next;
	}
}

void	printf_selected(t_entlist *l)
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
				ft_putchar_fd(' ', l->fd);
			ft_putstr_fd(tmp->line, l->fd);
		}
		//ft_putchar('\n');
		tmp = tmp->next;
	}
}
