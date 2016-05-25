/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 16:33:43 by cattouma          #+#    #+#             */
/*   Updated: 2016/05/25 16:54:11 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	set_draw(t_entlist *l)
{
	if (l->head)
		l->head->us = 1;
}

void	draw(t_entlist *l)
{
	t_entry *tmp;
	int		i;
	int		j;
	int		times;

	i = START;
	j = 0;

	times = 0;
	tmp = l->head;
	ft_putstr_fd(tgetstr("cl", NULL), l->fd);
	/* while (j < col) */
	/* { */
	/* 	i = 0; */
	/* 	while (i < li) */
	/* 	{ */
	/* 		if (tmp->us) */
	/* 			ft_putstr_fd(tgetstr("us", NULL), l->fd); */
	/* 		if (tmp->hl) */
	/* 			ft_putstr_fd(tgetstr("mr", NULL), l->fd); */
	/* 		ft_putstr_fd(tgoto(tgetstr("cm", NULL), j, i + START), l->fd); */
	/* 		ft_putstr_fd(tmp->line, l->fd); */
	/* 		ft_putstr_fd(tgetstr("me", NULL), l->fd); */
	/* 		tmp = tmp->next; */
	/* 		i++; */
	/* 	} */
	/* 	j += l->max_len + SPACE; */
	/* } */
	while (times < l->ac)
	{
		if (i == l->row - 1)
		{
			i = START;
			j += l->max_len + SPACE;
		}
		if (tmp->us)
			ft_putstr_fd(tgetstr("us", NULL), l->fd);
		if (tmp->hl)
			ft_putstr_fd(tgetstr("mr", NULL), l->fd);
		ft_putstr_fd(tgoto(tgetstr("cm", NULL), j, i + START), l->fd);
		ft_putstr_fd(tmp->line, l->fd);
		ft_putstr_fd(tgetstr("me", NULL), l->fd);
		tmp = tmp->next;
		i++;
		times++;
	}
}

void	print_selected(t_entlist *l)
{
	t_entry		*tmp;
	static int	i = 0;

	i = 0;
	ft_putstr_fd(ME,l->fd);
	tmp = l->head;
	if (l->head != NULL)
	{
		while (tmp->next != l->head)
		{
			if (tmp->hl)
			{
				if (i++ != 0)
					ft_putchar(' ');
				ft_putstr(tmp->line);
			}
			tmp = tmp->next;
		}
	}
}
