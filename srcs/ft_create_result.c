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

t_command	*create_new_result(void)
{
	t_command	*new;

	new = (t_command *)malloc(sizeof(t_command));
	if (!new)
		return (NULL);
	new->command = NULL;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
