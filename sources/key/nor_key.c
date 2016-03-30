#include "ft_select.h"

int	key_is_ctrl_d(const char *buffkey)
{
	static char c = '\0';

	if (c == '\0')
		c = 0x04;
	if (c == *buffkey)
		return (TRUE);
	return (FALSE);
}

int	key_is_return(const char *buffkey)
{
	static char c = '\0';

	if (c == '\0')
		c = '\n';
	if (c == *buffkey)
		return (TRUE);
	return (FALSE);
}

int	key_is_space(const char *buffkey)
{
	static char c = '\0';

	if (c == '\0')
		c = ' ';
	if (c == *buffkey)
		return (TRUE);
	return (FALSE);
}

int	key_is_escape(const char *buffkey)
{
	static char c = '\0';

	if (c == '\0')
		c = 0x1b;
	if (c == *buffkey)
		return (TRUE);
	return (FALSE);
}

int	key_is_delete(const char *buffkey)
{
	static char c = '\0';

	if (c == '\0')
		c = 0x7f;
	if (c == *buffkey)
		return (TRUE);
	return (FALSE);
}

int	key_is_backspace(const char *buffkey)
{
	static char c = '\0';

	if (c == '\0')
		c = 0x08;
	if (c == *buffkey)
		return (TRUE);
	return (FALSE);
}

int	key_is_tab(const char *buffkey)
{
	static char c = '\0';

	if (c == '\0')
		c = '\t';
	if (c == *buffkey)
		return (TRUE);
	return (FALSE);
}
