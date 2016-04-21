#include "ft_select.h"

/* void	init_ent(t_ent *e, char ** av) */
/* { */
/* 	e->args = NULL; */
/* 	e->pos = 0; */
/* 	e->args = tabdup(av); */
/* 	e->tablen = tab_len(e->args); */
/* } */

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
	t_entry *tmp;

	l->head = NULL;
	l->tail = NULL;
	l->list = NULL;
	getargs(ac, av, l);
	l->head = l->list;
	l->current = l->head;
	tmp = l->list;
	while (tmp->next)
		tmp = tmp->next;
	l->tail = tmp;
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

void	entry_destroy(t_entry *list)
{
	t_entry *tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp->line);
		free(tmp);
	}
}

void	lstprint(t_entlist *l)
{
	t_entry *tmp;

	tmp = l->list;
	ft_putstr(CL);
	while (tmp)
	{
		if (tmp->us)
			ft_putstr(US);
		if (tmp->hl)
			ft_putstr(MR);
		ft_putendl(tmp->line);
		ft_putstr(ME);
		tmp = tmp->next;
	}
}
