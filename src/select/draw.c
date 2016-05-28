/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 16:33:43 by cattouma          #+#    #+#             */
/*   Updated: 2016/05/25 17:42:25 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	set_draw(t_entlist *l)
{
	ft_putstr(tgetstr("ho", NULL));
	ft_putstr(tgetstr("cd", NULL));
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
	ft_putstr_fd(tgetstr("ho", NULL), l->fd);
	ft_putstr_fd(tgetstr("cd", NULL), l->fd);
	l->col_max = nbr_col(l);
	if (check_window_size(l) < 0)
	{
		ft_putstr_fd(tgoto(tgetstr("cm", NULL), l->col / 2 - SPACE, l->row / 2), l->fd);
		ft_putstr_fd("window too small", l->fd);
	}
	else
	{
		while (times < l->ac)
		{
			if (i == l->row)
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
		ft_putchar('\n');
	}
}
