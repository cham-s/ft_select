#include "libft.h"

char	**tabdup(char **str)
{
	char	**new;
	size_t	len;
	int		i;

	len = ft_tablen(str);
	new = (char **)malloc(sizeof(char *) * len + 1);
	if (!new)
		return NULL;
	i = 0;
	while (len--)
	{
		new[i] = ft_strdup(str[i]);
		i++;
	}
	new[i] = NULL;
	return (new);
}
