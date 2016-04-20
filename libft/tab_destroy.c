#include "libft.h"

void	tab_destroy(char **tabl)
{
	int i;

	i = 0;
	while (tabl[i])
	{
		free(tabl[i]);
		i++;
	}
	free(tabl);
}
