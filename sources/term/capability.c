#include "ft_select.h"

void	get_cstr(char *ret ,char *c, char **term_buffer)
{
	ret = tgetstr(c, term_buff);
}

void	get_cflag(char *c, int *buflag)
{
	*buflag = tgetflag(c);
}

void	get_cnum(char *c, int *bufnum)
{
	*bufnum = tgetflag(c);
}
