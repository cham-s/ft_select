#include "ft_select.h"

void	delete_key(t_entlist *l)
{
	if (delete_entry(l) < 0)
	{
		clean_screen(l);
		reset_default_mode(&l->old_term);
		exit(0);
	}
	l->list->us = 1;
}

void	key_handler(unsigned int key, t_entlist *l, int *running)
{
	if (key == K_ENT)
	{
		clean_screen(l);	
		*running = 0;
	}
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
		else if (key == K_a)
		{
			l->sel_v = (l->sel_v == 0? 1 : 0);
			select_all(l, l->sel_v);
		}
	}
}

int		launcher(t_entlist *l)
{
	char			buf[MAX_KEY_LENGTH];
	int				is_running;
	unsigned int	key;

	set_draw(l);
	is_running = 1;
	while (is_running) {
		draw(l);
		ft_bzero(buf, MAX_KEY_LENGTH);
		read(0, buf, MAX_KEY_LENGTH);
		key = *(unsigned int *)buf;
		key_handler(key, l, &is_running);
	}
	return (0);
}
