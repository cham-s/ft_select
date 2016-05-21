#include "ft_select.h"

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
				exit(EXIT_SUCCESS);
			else if (key == K_DOWN || key == K_RIGHT)
			{
				l->list->us = 0;
				l->list = l->list->next;
				if (l->list == NULL)
					l->list = l->head;
				l->list->us = 1;
			}
			else if (key == K_UP || key == K_LEFT)
			{
				l->list->us = 0;
				l->list = l->list->prev;
				if (l->list == NULL)
					l->list = l->tail;
				l->list->us = 1;
			}
		}
	}
	return (0);
}
