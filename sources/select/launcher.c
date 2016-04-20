#include "ft_select.h"

int	launcher(t_entlist *l)
{
	char		buf[MAX_KEY_LENGTH];

	ft_putstr(HO);
	//lstprint(l);
	while (1)
	{
		t_key *key;
		read(0, buf, MAX_KEY_LENGTH);
		key = getkey(buf);
		key_react(key, l);
		key_destroy(key);
	}
	return (0);
}
