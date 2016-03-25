#include "key.h"

int	key_is_down_arrow(const char *buff)
{
	static char *arrow = NULL;

	if (arrow == NULL)
	{
		arrow = tgetstr("kd", NULL);
		arrow[1] = 91;
	}
	if (!ft_memcmp((void *)arrow, (void *)buff, ft_strlen(arrow)))
		return (TRUE);
	return (FALSE);
}

int	key_is_up_arrow(const char *buff)
{
	static char *arrow = NULL;

	if (arrow == NULL)
	{
		arrow = tgetstr("ku", NULL);
		arrow[1] = 91;
	}
	if (!ft_memcmp((void *)arrow, (void *)buff, ft_strlen(arrow)))
		return (TRUE);
	return (FALSE);
}

int	key_is_left_arrow(const char *buff)
{
	static char *arrow = NULL;

	if (arrow == NULL)
	{
		arrow = tgetstr("kl", NULL);
		arrow[1] = 91;
	}
	if (!ft_memcmp((void *)arrow, (void *)buff, ft_strlen(arrow)))
		return (TRUE);
	return (FALSE);
}

int	key_is_right_arrow(const char *buff)
{
	static char *arrow = NULL;

	if (arrow == NULL)
	{
		arrow = tgetstr("kr", NULL);
		arrow[1] = 91;
	}
	if (!ft_memcmp((void *)arrow, (void *)buff, ft_strlen(arrow)))
		return (TRUE);
	return (FALSE);
}
