#include "ft_select.h"

void	draw(t_entlist *l)
{
	t_entry *tmp;

	tmp = l->list;
	l->current->us = 1;
	ft_putstr(CL);
	while (tmp)
	{
		if (tmp->us)
		{
			ft_putstr(US);
			tmp->us = 0;
		}
		if (tmp->hl)
			ft_putstr(MR);
		ft_putendl(tmp->line);
		ft_putstr(ME);
		tmp = tmp->next;
	}
}
