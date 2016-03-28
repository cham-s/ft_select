#include "key.h"

t_key	*newkey(int keytype, const char *buffkey)
{
	t_key	*new;

	new = (t_key *)ft_memalloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->type = keytype;
	new->str = ft_strdup(buffkey);
	return (new);
}

void	key_destroy(t_key *key)
{
	free(key->str);
	free(key);
}

t_key	*getkey(const char *keybuff)
{
	int i;
	static t_functs_tab funcs[] = {
		{KEY_C_CTRL_D, &key_is_ctrl_d},
		{KEY_C_TAB, &key_is_tab},
		{KEY_C_UP, &key_is_up_arrow},
		{KEY_C_DOWN, &key_is_down_arrow},
		{KEY_C_RIGHT, &key_is_right_arrow},
		{KEY_C_LEFT, &key_is_left_arrow},
		{KEY_C_SPACE, &key_is_space},
		{KEY_C_RETURN, &key_is_return},
		{KEY_C_ESCAPE, &key_is_escape},
		{KEY_C_DELETE, &key_is_delete},
		{KEY_C_BACKSPACE, &key_is_backspace},
		{KEY_C_NONE, NULL},
	};

	i = 0;

	while (funcs[i].f)
	{
		if ((funcs[i].f)(keybuff) == TRUE)
			return newkey(funcs[i].type, keybuff);
		i++;
	}
	return (newkey(KEY_C_NONE, keybuff));
}

void	key_react(t_key *key, int *index, int ac, char **av)
{

	//index;
	(void)index;
	int i = 3;
	static int y = 1;
	if (key->type == KEY_C_DOWN)
		lstprint(ac, av);
	else if (key->type == KEY_C_UP)
	{
		ft_putstr(tgetstr("up", NULL));
		if (y == 1)
			tgoto(tgetstr("cm", NULL), 0, i);
	}
	else if (key->type == KEY_C_ESCAPE)
		exit(0);
	else if (key->type == KEY_C_TAB)
		ft_putendl("tab key");
	else if (key->type == KEY_C_SPACE)
		ft_putstr(tgetstr("mr", NULL));
	else if (key->type == KEY_C_BACKSPACE)
		ft_putstr(tgetstr("dl", NULL));
	else if (key->type == KEY_C_DELETE)
		ft_putstr(tgetstr("dl", NULL));
}
