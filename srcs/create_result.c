#include "../includes/push_swap.h"

t_command	*create_new_result(t_main *inf)
{
	t_command	*new;

	new = (t_command *)malloc(sizeof(t_command));
	if (!new)
		exit (end_program("Error: malloc 'res'\n", inf, 7));
	new->command = NULL;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
