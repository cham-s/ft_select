/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 16:09:23 by cattouma          #+#    #+#             */
/*   Updated: 2016/05/25 16:12:10 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

// add a paginagtion system
void	print_window_small(t_entlist *l)
{
	ft_putstr_fd(tgoto(tgetstr("cm", NULL), 0, START), l->fd);
	ft_putstr_fd("Window too small to display all entries", l->fd);
}

