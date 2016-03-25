#include "libft.h"

void	ft_destroylst(t_list **alst)
{
	t_list *current;

	current = *alst;
	while (*alst)
	{
		current = *alst;
		free(current->content);
		free(current);
		*alst = (*alst)->next;
	}
}
