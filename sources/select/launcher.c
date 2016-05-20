#include "ft_select.h"

int	launcher(t_entlist *l)
{
	char		buf[MAX_KEY_LENGTH];
	int			is_running = 1;
	int			ret;

	//ft_putstr(VI);
	//ft_putstr(CL);
	(void)l;
	//lstprint(l);
	while (is_running)
	{
		unsigned int	key;
		ret = read(0, buf, MAX_KEY_LENGTH);
		//
		buf[ret] = '\0';
		printf("%d\n", *(int *)buf);
	}
	return (0);
}
