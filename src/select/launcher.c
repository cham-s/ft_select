#include "ft_select.h"

void	go_down(t_entlist *l)	
{
	l->list->us = 0;
	l->list = l->list->next;
	if (l->list == NULL)
		l->list = l->head;
	l->list->us = 1;
}

void	go_up(t_entlist *l)	
{
	l->list->us = 0;
	l->list = l->list->prev;
	if (l->list == NULL)
		l->list = l->tail;
	l->list->us = 1;
}

int	launcher(t_entlist *l)
{
	char			buf[MAX_KEY_LENGTH];
	int				is_running = 1;
	unsigned int	key;

	set_draw(l);
	while (is_running)
	{
		draw(l);
		ft_bzero(buf, MAX_KEY_LENGTH);
		read(0, buf, MAX_KEY_LENGTH);
		key = *(unsigned int *)buf;
		if (key == K_ENT)
			is_running = 0;
		else
		{
			if (key == K_ESC)
			{
				ft_putstr(tgetstr("vi", NULL));
				ft_putstr(tgetstr("ti", NULL));
				exit(EXIT_SUCCESS);
			}
			else if (key == K_DOWN || key == K_RIGHT)
				go_down(l);
			else if (key == K_UP || key == K_LEFT)
				go_up(l);
			else if (key == K_SPACE)
			{
				l->list->hl = l->list->hl == 0? 1: 0;
				go_down(l);
			}
		}
	}
	return (0);
}
