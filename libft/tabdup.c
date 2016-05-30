/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 17:17:23 by cattouma          #+#    #+#             */
/*   Updated: 2016/05/30 17:18:11 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**tabdup(char **str)
{
	char	**new;
	size_t	len;
	int		i;

	len = ft_tablen(str);
	new = (char **)malloc(sizeof(char *) * len + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (len--)
	{
		new[i] = ft_strdup(str[i]);
		i++;
	}
	new[i] = NULL;
	return (new);
}
