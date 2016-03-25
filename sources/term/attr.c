#include "ft_select.h"

void	init_raw_mode(void)
{
	struct termios termattr;

	if (tcgetattr(0, &termattr) == -1)
	{
		ft_putendl_fd("probelem with tgetattr", 2);
		exit(EXIT_FAILURE);
	}
	termattr.c_lflag &= ~(ECHO | ICANON);
	termattr.c_cc[VMIN] = 1;
	termattr.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &termattr) == -1)
	{
		ft_putendl_fd("probelem with setattr", 2);
		exit(EXIT_FAILURE);
	}
}

void	reset_default_mode(void)
{
	struct termios termattr;

	if (tcgetattr(0, &termattr) == -1)
	{
		ft_putendl_fd("problem with tgetattr", 2);
		exit(EXIT_FAILURE);
	}
	termattr.c_lflag |= ~ECHO;
	termattr.c_lflag |= ~ICANON;
	termattr.c_cc[VMIN] = 1;
	termattr.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &termattr) == -1)
	{
		ft_putendl_fd("problem with setattr", 2);
		exit(EXIT_FAILURE);
	}
}
