#include "ft_select.h"

int	main(void)
{
	char term_buffer[2048];
	char *buffaddr;

	buffaddr = &term_buffer[0];
	init_terminal_data(&buffaddr);
	interrogate_terminal();
}
