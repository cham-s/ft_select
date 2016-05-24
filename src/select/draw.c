/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 16:33:43 by cattouma          #+#    #+#             */
/*   Updated: 2016/05/24 18:53:42 by cattouma         ###   ########.fr       */
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

	i = 0;
	tmp = l->head;
	ft_putstr_fd(tgetstr("cl", NULL), l->fd);
	while (i < l->ac)
	{
		if (tmp->us)
			ft_putstr_fd(tgetstr("us", NULL), l->fd);
		if (tmp->hl)
			ft_putstr_fd(tgetstr("mr", NULL), l->fd);
		ft_putendl_fd(tmp->line, l->fd);
		ft_putstr_fd(tgetstr("me", NULL), l->fd);
		tmp = tmp->next;
		i++;
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
