/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_entry.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 16:33:47 by cattouma          #+#    #+#             */
/*   Updated: 2016/05/25 16:07:59 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_entlist	*ret_entlist(void)
{
	static t_entlist l;
	return (&l);
}

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

int		nbr_col(t_entlist *l)
{
	double	cols_float;
	int		cols_int;

	cols_float = (double)l->ac / (double)l->row;
	if (cols_float == (int)cols_float)
		cols_int = (int)cols_float;
	else
		cols_int = (int)cols_float + 1;
	cols_int = (l->max_len + SPACE) * cols_int;
	return (cols_int - SPACE);
}

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

void	init_entlist(t_entlist *l, char **av, int ac)
{
	t_entry		   	*tmp;
	t_entry		   	*slow;
	struct winsize	w;

	ioctl(l->fd, TIOCGWINSZ, &w);
	l->row = w.ws_row - START;
	l->col = w.ws_col;
	l->head = NULL;
	l->list = NULL;
	l->ac = ac - 1;
	l->max_len = 0;
	getargs(ac, av, l);
	//l->col_max = nbr_col(l);
	l->head = l->list;
	tmp = l->list;
	slow = l->list;
	while (tmp->next)
	{
		tmp = tmp->next;
		tmp->prev = slow; 
		slow = slow->next;
	}
	tmp->next = l->head;
	l->list->prev = tmp;
}

void	addentry(t_entlist *l, t_entry *new)
{
	t_entry *tmp;

	tmp = l->list;
	if (!tmp)
		l->list = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	getargs(int ac, char **av, t_entlist *l)
{
	int i;
	int	max_len;

	i = 1;
	while (ac-- > 1)
	{
		max_len = ft_strlen(av[i]);
		l->max_len = max_len > l->max_len? max_len : l->max_len; 
		addentry(l, newentry(av[i]));
		i++;
	}
}

void	entry_destroy(t_entlist *l)
{
	t_entry *tmp;
	int		i;

	i = 0;
	if (l->head)
	{
		while (i < l->ac)
		{
			tmp = l->head;
			l->head = l->head->next;
			free(tmp->line);
			free(tmp);
			i++;
		}
	}
	close(l->fd);
}

void	free_entry(t_entry *e)
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
	clean_screen(l);
	entry_destroy(l);
	reset_default_mode(&l->old_term);
	exit(EXIT_SUCCESS);
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
