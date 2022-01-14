#include "../includes/push_swap.h"

int	ft_count_commands(t_command **result)
{
	t_command	*tmp;
	int			count;

	tmp = *result;
	count = 0;
	while (tmp)
	{
		if (tmp->command)
			count++;
		tmp = tmp->next;
	}
	return (count);
}

t_command	*create_new_result(t_main *inf)
{
	t_command	*new;

	new = (t_command *)malloc(sizeof(t_command));
	if (!new)
		exit (error_mess("Error: init result\n", inf, 7));
	new->command = NULL;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
