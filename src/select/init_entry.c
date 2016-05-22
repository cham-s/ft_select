#include "ft_select.h"

t_entry	*newentry(char *str)
{
	t_entry *new;

	new = (t_entry *)ft_memalloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->prev = NULL;
	new->line = ft_strdup(str);
	new->hl = 0;
	new->us = 0;
	return (new);
}

void	init_entlist(t_entlist *l, char **av, int ac)
{
	t_entry	*tmp;
	t_entry *slow;

	l->head = NULL;
	l->tail = NULL;
	l->list = NULL;
	getargs(ac, av, l);
	l->head = l->list;
	l->current = l->head;
	tmp = l->list;
	while (tmp->next)
	{
		slow = tmp;
		tmp = tmp->next;
	}
	l->tail = tmp;
	l->tail->prev = slow;;
}

void	addentry(t_entlist *l, t_entry *new)
{
	t_entry *tmp;
	t_entry *slow;

	tmp = l->list;
	slow = l->list;
	if (!tmp)
	{
		l->list = new;
		l->tail = new;
	}
	else
	{
		while (tmp->next)
		{
			tmp = tmp->next;
			tmp->prev = slow;
			slow = slow->next;
		}
		tmp->next = new;
	}
}

void	getargs(int ac, char **av, t_entlist *l)
{
	int i;

	i = 1;
	while (ac-- > 1)
	{
		addentry(l, newentry(av[i]));
		i++;
	}
}

void	entry_destroy(t_entlist *l)
{
	t_entry *tmp;

	while (l->list)
	{
		tmp = l->list;
		l->list = l->list->next;
		free(tmp->line);
		free(tmp);
	}
	close(l->fd);
}

void	destroy_entry(t_entry *e)
{
	free(e->line);
	e->line = NULL;
	e->next = NULL;
	e->prev = NULL;
	free(e);
	e = NULL;
}

void	quit(t_entlist *l)
{
	ft_putstr_fd(tgetstr("ve", NULL), l->fd);
	ft_putstr_fd(tgetstr("te", NULL), l->fd);
	entry_destroy(l);
	exit(EXIT_SUCCESS);
}


int		delete_entry(t_entlist *l)
{
	t_entry	*tmp;

	if (l->head == l->list)
	{
		if (l->head->next == NULL)
		{
			destroy_entry(l->list);
			return (-1);
		}
		tmp = l->head;
		l->head = l->head->next;
		destroy_entry(tmp);
	}
	else if (l->list == l->tail)
	{
		tmp = l->tail;
		l->tail = l->tail->prev;
		l->tail->next = NULL;
		destroy_entry(tmp);
	}
	else
	{
		tmp = l->list;
		tmp = l->list->prev;
		tmp->next = l->list->next;
		l->list->next->prev = tmp;
		destroy_entry(l->list);
		l->list = tmp->next;
	}
	return (0);
}
