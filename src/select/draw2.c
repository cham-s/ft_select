/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 17:19:09 by cattouma          #+#    #+#             */
/*   Updated: 2016/05/30 17:20:40 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	print_entry_color(t_entlist *l, char *path)
{
	struct stat	file;

	if (stat(path, &file) < 0)
		ft_putstr_fd(path, l->fd);
	else
	{
		if (file.st_mode & S_IXUSR && !S_ISDIR(file.st_mode))
		{
			ft_putstr_fd("\e[31m", l->fd);
			ft_putstr_fd(path, l->fd);
			ft_putstr_fd("\e[0m", l->fd);
		}
		else if (S_ISDIR(file.st_mode))
		{
			ft_putstr_fd("\e[34m", l->fd);
			ft_putstr_fd(path, l->fd);
			ft_putstr_fd("\e[0m", l->fd);
		}
		else
			ft_putstr_fd(path, l->fd);
	}
}

void	set_draw(t_entlist *l)
{
	ft_putstr(tgetstr("ho", NULL));
	ft_putstr(tgetstr("cd", NULL));
	if (l->head)
		l->head->us = 1;
}
