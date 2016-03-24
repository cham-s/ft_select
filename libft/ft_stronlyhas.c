/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stronlyhas.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 13:32:25 by cattouma          #+#    #+#             */
/*   Updated: 2016/01/02 14:23:03 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_stronlyhas(const char *s, char c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s != c)
			return (0);
		s++;
	}
	return (1);
}
