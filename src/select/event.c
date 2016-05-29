#include "ft_select.h"

int		check_window_size(t_entlist *l)
{
	//
	//dprintf(l->fd, "col_max: %d col: %d row: %d ac: %d max_len: %d\n", l->col_max, l->col, l->row, l->ac, l->max_len);
	if (l->max_len - SPACE > l->col && l->ac > l->row)
		return (-1);
	if (l->col_max >= l->col)
		return (-1);
	return (0);
}

void		select_all(t_entlist *l, int value)
{
	t_entry *tmp;
	int		i;

	i = 0;
	tmp = l->head;
	while (i < l->ac)
	{
		tmp->hl = value;
		tmp = tmp->next;
		i++;
	}
}

static void	free_entry(t_entry *e)
{
	free(e->line);
	e->line = NULL;
	e->next = NULL;
	e->prev = NULL;
	free(e);
	e = NULL;
}

int		delete_entry(t_entlist *l)
{
	t_entry	*tmp;
	int		y;

	y = (l->list == l->head? 1 : 0);
	tmp = l->list;
	l->list = l->list->next;
	tmp->prev->next = l->list;
	l->list->prev = tmp->prev;
	free_entry(tmp);
	if (y)
		l->head = l->list;
	l->ac--;
	return (l->ac == 0? -1 : 0);
}

void	quit(t_entlist *l)
{
	clean_screen(l);
	entry_destroy(l);
	reset_default_mode(&l->old_term);
	exit(EXIT_SUCCESS);
}