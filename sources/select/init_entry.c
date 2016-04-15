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
	new->flags = (t_opt *)ft_memalloc(sizeof(t_opt)); 
	if (!new->flags)
		return (NULL);
	new->head = new;
	init_flags(new->flags);
	return (new);
}

void	init_entlist(t_entlist *l)
{
	l->head = NULL;
	l->list = NULL;
}

void	addentry(t_entry **list, t_entry *new)
{
	t_entry *tmp;

	tmp =  *list;
	if (!tmp)
		*list = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
}

/* void	getargs(int ac, char **av, t_entry **list) */
/* { */
/* 	int i; */

/* 	i = 1; */
/* 	while (ac-- > 1) */
/* 	{ */
/* 		addentry(list, newentry(av[i])); */
/* 		i++; */
/* 	} */
/* } */

void	entry_destroylist(t_entry *list)
{
	t_entry *tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp->line);
		free(tmp->flags);
		free(tmp);
	}
}

void	lstprint(t_entry **list)
{
	t_entry *tmp;

	tmp = *list;
	while (tmp)
	{
		ft_putendl(tmp->line);
		tmp = tmp->next;
	}
}