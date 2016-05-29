#include "ft_select.h"

void	go_down(t_entlist *l)	
{
	l->list->us = 0;
	l->list = l->list->next;
	l->list->us = 1;
}

void	go_up(t_entlist *l)	
{
	l->list->us = 0;
	l->list = l->list->prev;
	l->list->us = 1;
}

void	clean_screen(t_entlist *l)
{
		ft_putstr_fd(tgetstr("ho", NULL), l->fd);
		ft_putstr_fd(tgetstr("cd", NULL), l->fd);
		ft_putstr_fd(tgetstr("ve", NULL), l->fd);
		ft_putstr_fd(tgetstr("te", NULL), l->fd);
}
