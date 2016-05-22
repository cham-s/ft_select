#include "ft_select.h"

void	init_raw_mode(struct termios *old)
{
	struct termios termattr;

	if (tcgetattr(0, old) == -1)
	{
		ft_putendl_fd("failed to tgetattr", 2);
		exit(EXIT_FAILURE);
	}

	termattr = *old;
	termattr.c_lflag &= ~(ECHO | ICANON);
	termattr.c_cc[VMIN] = 1;
	termattr.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &termattr) == -1)
	{
		ft_putendl_fd("failed to setattr", 2);
		exit(EXIT_FAILURE);
	}
}

void	reset_default_mode(struct termios *old)
{
	if (tcsetattr(0, TCSADRAIN, old) == -1)
	{
		ft_putendl_fd("failed to setattr", 2);
		exit(EXIT_FAILURE);
	}
}
