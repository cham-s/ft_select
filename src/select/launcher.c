#include "ft_select.h"

int	launcher(t_entlist *l)
{
	char			buf[MAX_KEY_LENGTH];
	int				is_running = 1;
	int				ret;
	unsigned int	key;

	while (is_running)
	{
		ret = read(0, buf, MAX_KEY_LENGTH);
		buf[ret] = '\0';
		key = *(unsigned int *)buf;
		if (key == K_ESC)
		{
			ft_putstr(tgetstr("te", NULL));
			exit(3);
		}
		else if (key == K_ENT)
		{
			//
			printf("you just pressed enter\n");
		}
		//draw();
	}
	return (0);
}
