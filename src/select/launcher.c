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

void	delete_key(t_entlist *l)
{
	if (delete_entry(l) < 0)
	{
		ft_putstr_fd(tgetstr("ve", NULL), l->fd);
		ft_putstr_fd(tgetstr("te", NULL), l->fd);
		reset_default_mode(&l->old_term);
		exit(0);
	}
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
		{
			ft_putstr_fd(tgetstr("ve", NULL), l->fd);
			ft_putstr_fd(tgetstr("te", NULL), l->fd);
			is_running = 0;
		}
		else if (g_w.ws_row != l->row || g_w.ws_col != l->col)
			continue ;
		else
		{
			if (key == K_ESC)
				quit(l);
			else if (key == K_DOWN || key == K_RIGHT)
				go_down(l);
			else if (key == K_UP || key == K_LEFT)
				go_up(l);
			else if (key == K_SPACE)
			{
				l->list->hl = l->list->hl == 0? 1: 0;
				go_down(l);
			}
			else if (key == K_DEL || key == K_BKSPC)
				delete_key(l);
		}
	}
	return (0);
}
